// wxshowmath.cpp                            Copyright (C) 2016, A C Norman

/**************************************************************************
 * Copyright (C) 2016, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$


// This is a fresh implementation of this code and will avoid use of
// custom fonts used with wxGraphicsContext - this is bacause in order
// to use custom fontw in a wxGraphicsContext I needed a private extension
// to wxWidgets. The code here should work using a standard copy of wxWidgets.
// To achieve accurate character placement I will use a memory buffer
// rather bigger than the screen and first draw onto that, and then do
// scale reduction to a second buffer sized as per the real window I am
// painting in. That real window will never be bigger than the screen size.


#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif

#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include"wx/wx.h"
#endif

#include <wx/display.h>
#include <wx/graphics.h>
#include <wx/filename.h>
#include <wx/rawbmp.h>

#include"config.h"

#include "wxfwin.h"

#ifdef WIN32
#include <windows.h>
#endif  // WIN32

// I may be old fashioned, but I will be happier using C rather than C++
// libraries here.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>
#include <stdint.h>
#include <inttypes.h>

#if HAVE_UNISTD_H
#include <unistd.h>
#else
extern char *getcwd(char *s, size_t n);
#endif // HAVE_UNISTD_H

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#else
#ifndef WIN32
#include <sys/dir.h>
#else
#include <direct.h>
#endif
#endif // HAVE_DIRENT_H

#if !defined __WXMSW__ && !defined __WXPM__
#include"fwin.xpm" // Icon to use in non-Windows cases
#endif

// I have a generated file that contains the widths of all the fonts
// that I am willing to use here.

#include "uninames.h"
#include "charmetrics.h"

static wxStopWatch sw;

static int options = 5;  // default to using my own scaling

static FILE *logfile = NULL;

static int logprintf(const char *fmt, ...)
{   va_list a;
    int r = 0;
    if (logfile == NULL) logfile = fopen("wxshowmath.log", "w");
    if (logfile != NULL)
    {   va_start(a, fmt);
        r = vfprintf(logfile, fmt, a);
        fflush(logfile);
        va_end(a);
    }
#ifndef MACINTOSH
// On systems other than the Mac I expect I can (sometimes!) have a console
// attached to my program, and in that case it will be convenient to sent the
// trace output there as well as to a file.
    va_start(a, fmt);
    r = vprintf(fmt, a);
    va_end(a);
    fflush(stdout);
#endif
    return r;
}

class showmathApp : public wxApp
{
public:
    virtual bool OnInit();
};

#define MAX_FONTS 16
wxFont Font[MAX_FONTS];
int Baseline[MAX_FONTS];
bool FontValid[MAX_FONTS];


class showmathPanel : public wxPanel
{
public:
    showmathPanel(class showmathFrame *parent, const char *showmathfilename);

    void OnPaint(wxPaintEvent &event);

// The event handling is not really needed for this application, but I
// am putting some in so I can experiment with it!
    void OnChar(wxKeyEvent &event);
    void OnKeyDown(wxKeyEvent &event);
    void OnKeyUp(wxKeyEvent &event);
    void OnMouse(wxMouseEvent &event);

private:
    wxFont FixedPitch;
    int FixedPitchBaseline;

    void RenderDVI();        // sub-function used by OnPaint

    char *showmathData;  // the .showmath file's contents are stored here
    unsigned const char *stringInput;



    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(showmathPanel, wxPanel)
    EVT_PAINT(           showmathPanel::OnPaint)
    EVT_CHAR(            showmathPanel::OnChar)
//  EVT_KEY_DOWN(        showmathPanel::OnKeyDown)
//  EVT_KEY_UP(          showmathPanel::OnKeyUp)
    EVT_LEFT_UP(         showmathPanel::OnMouse)
END_EVENT_TABLE()

// The size (in pixels, or at least in the units that wxWidgets uses)
// of my screen. No window can ever be bigger than this.
int screenWidth, screenHeight;

wxBitmap *bigBitmap;
wxMemoryDC *bigDC;
// I have bigBitmap which is bigWidth*bigHeight, which is 4 times the
// size of my screen (well my screen as reported and worked with by
// wxWidgets). Eg for a HD monitor that means it will be 7680x4320 which
// is 31 megapixels. It turns out to be VITALLY IMPORTANT for performance
// that I make this bitmnap have the same depth as my screen. It ends up
// using quite a lot of memory!

int bigWidth, bigHeight;

// I will limit the area of my window to the size of my screen, and so once
// borders (and perhaps scroll bars and other decorations) have been allowed
// for the client area will be strictly smaller. The size of it is recorded
// here.

int clientWidth, clientHeight;

// The client area will be mapped by a region in the top left hand corner of
// bigBitmap. This will be larger by some factor that is in the range 3.5
// to 4. usedScale records this scale factor and usedWidth and usedHeight
// the size of this area. Note that the constraints I have documented ensure
// that this fits within bigBitmap. I am going to arrange that usedWidth is
// either a multiple of 80 or only a few pixels larger. That is so that I can
// fit a row of 80 fixed-pitch characters across my window neatly.

double usedScale;
int usedWidth, usedHeight;

// To help me redraw the client area of my screen reasonably rapidly I
// will work with tiles, and I will require usedScale to be a rational
// number bigTileSize/smallTileSize. Then I will have usedWidth as
// ceiling(usedScale*clientWidth) and usedHeight = celing(usedScale*
// clientHeight). If I do this I can align my tiles precisely on both
// client and big bitmaps. Vertical measurements are in charOffset and
// charLinespacing, and charPointSize records the point size passed
// to wxWidgets to create the font. To help me choose a suitable point size
// I record charWidth_1000 which is the width of a 1000-point character.

wxBitmap *bigTile = NULL;
wxBitmap *smallTile = NULL;
wxMemoryDC *tileDC;
int smallTileSize, bigTileSize;

// bigfont is a fixed pitch font sized for use on bigBitmap, such that
// each character there has width charWidth, and usedWidth is just over
// 80*charWidth. The latter is so that the line neatly fills my window.

wxFont *bigfont;

int charPointSize;   // size of the font.
int charWidth_1000;  // width of characters when font is 1000 points.
int charWidth;       // for fixed pitch font, as on bigBitmap.
int charOffset;      // so that I print relative to index point.
int charLinespace;   // how much to separate lines by.

// Once I have done all that I intend to set a wxWidgets UserScale so that
// the user works using integer coordinates such that the apparent point size
// of the fixed point font is 10000 -- I intend to think of this as working
// in millipoints, and it amounts to pretending that the fixed pitch
// font I am working with is at 10 points (even though on screen it will
// typically be larger).

// The scale factor between bigBitmap and the client area means that I
// will initially position and render characters between 3.5 and 4 times as
// precisely as single-pixel addressing would have allowed. Copying down from
// bigBitmap to the screen will do anti-aliasing and support sub-pixel
// character placement. I may need to experiment to decide if this reduction
// factor is about right, but at present my guess is that it will give
// usefully better visual effects than schemes that force all characters to
// snap to pixels, and that more oversampling would bot gain anything
// worth while. And the cost of what I am doing now is perhaps already
// fairly bad.


class showmathFrame : public wxFrame
{
public:
    showmathFrame(const char *showmathfilename);

    void RepaintBuffer();

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnSize(wxSizeEvent &event);

private:
    showmathPanel *panel;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(showmathFrame, wxFrame)
    EVT_CLOSE(           showmathFrame::OnClose)
    EVT_MENU(wxID_EXIT,  showmathFrame::OnExit)
    EVT_MENU(wxID_ABOUT, showmathFrame::OnAbout)
    EVT_SIZE(            showmathFrame::OnSize)
END_EVENT_TABLE()

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

int main(int argc, char *argv[])
{   int usegui = 1;
// Find where I am invoked from before doing anything else
    find_program_directory(argv[0]);
// The next fragment is not very useful in THIS program but stands in for
// behaviour I want in more complicated cases.
    for (int i=1; i<argc; i++)
    {   if (strncmp(argv[i], "-w", 2) == 0) usegui = 0;
        if (strncmp(argv[i], "-x", 2) == 0) options = atoi(argv[i]+2);
    }
#if !defined WIN32 && !defined MACINTOSH
// Under X11 I will demote to being a console mode application if DISPLAY
// is not set. This is not a perfect test but it will spot the simple
// cases. Eg I could look at stdin & stdout and check if it looks as if
// they are pipes of they have been redirected...
    {   const char *s = getenv("DISPLAY");
        if (s==NULL || *s == 0) usegui = 0;
    }
#endif
    if (usegui)
    {
#ifdef MACINTOSH
// If I will be wanting to use a GUI and if I have just loaded an
// executable that is not within an application bundle then I will
// use "open" to launch the corresponding application bundle. Doing this
// makes resources (eg fonts) that are within the bundle available and
// it also seems to cause things to terminate more neatly.
        char xname[LONGEST_LEGAL_FILENAME];
        sprintf(xname,"%s.app", programName);
        if (strstr(fullProgramName, xname) == NULL)
        {
// Here the binary I launched was not located as
//      ...foo.app../.../foo
// so I will view it is NOT being from an application bundle. I will
// re-launch it so it is! This may be a bit of a hacky way to decide!
            struct stat buf;
            sprintf(xname,"%s.app", fullProgramName);
            if (stat(xname, &buf) == 0 &&
                (buf.st_mode & S_IFDIR) != 0)
            {
// Well foo.app exists and is a directory, so I will try to use it
                const char **nargs =
                    (const char **)malloc(sizeof(char *)*(argc+3));
                nargs[0] ="/usr/bin/open";
                nargs[1] = xname;
                nargs[2] ="--args";
                for (int i=1; i<argc; i++)
                    nargs[i+2] = argv[i];
                nargs[argc+2] = NULL;
// /usr/bin/open foo.app --args [any original arguments]
                return execv("/usr/bin/open", const_cast<char * const *>(nargs));
            }
        }
#endif
// I have my own "main" function and call wxEntry from it. So I need
// to call the following so that if I compiled with NDEBUG set a range of
// assertions etc will not be checked...
        wxDISABLE_DEBUG_SUPPORT();
        add_custom_fonts();
#if DEBUG
//      display_font_information();
#endif
        return wxEntry(argc, (char **)argv);
    }
//
// The following is a bit silly but is here to prove that I can launch this
// code in console mode if I wish to. In this case it is not very useful!
//
    printf("This program has been launched asking for use in a console\n");
    printf("type a line of text please\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) putchar(c);
    putchar('\n');
    printf("Exiting from demonstration of console mode use!\n");
    return 0;
}

IMPLEMENT_APP_NO_MAIN(showmathApp)

//=========================================================================
//
// Now that start of my code in a proper sense!
//
//

bool showmathApp::OnInit()
{
// The program can take an argument - grab that here and pass it down to
// showmathFrame - or NULL if there was none.
    char **myargv = (char **)argv;
    const char *showmathfilename = NULL;
    for (int i=1; i<argc; i++)
        if (myargv[i][0] != '-') showmathfilename = myargv[i];
#ifdef WIN32
    static char tidyfilename[LONGEST_LEGAL_FILENAME];
    if (showmathfilename != NULL &&
        strncmp(showmathfilename, "/cygdrive/", 10) == 0 &&
        showmathfilename[11] == '/')
    {   sprintf(tidyfilename, "%c:%s",
                showmathfilename[10], showmathfilename+11);
        showmathfilename = tidyfilename;
    }
#endif
    sw.Start(0);  // start the StopWatch
    showmathFrame *frame = new showmathFrame(showmathfilename);
    frame->Show(true);
    return true;
}

showmathFrame::showmathFrame(const char *showmathfilename)
    : wxFrame(NULL, wxID_ANY, "wxshowmath")
{   SetIcon(wxICON(fwin));
    panel = new showmathPanel(this, showmathfilename);
    int numDisplays = wxDisplay::GetCount(); // how many displays?
// It is not clear to me what I should do if there are several displays,
// and if there are none I am probably in a mess!
    if (numDisplays != 1)
    {   logprintf("There seem to be %d displays\n", numDisplays);
    }
    wxDisplay d0(0);                         // just look at display 0
    wxRect screenArea(d0.GetClientArea());   // omitting task bar
    screenWidth = screenArea.GetWidth();
    screenHeight = screenArea.GetHeight();

    bigBitmap = new wxBitmap(bigWidth=4*screenWidth,
                             bigHeight=4*screenHeight,
                             24); // wxBITMAP_SCREEN_DEPTH);
    bigDC = new wxMemoryDC();
    bigTile = NULL;
    smallTile = NULL;
    tileDC = new wxMemoryDC();
    bigDC->SelectObject(*bigBitmap);
//
// I will now create a font suitable for writing into the big
// bitmap. Well here I will just make one using "CMU Typewriter Text", a
// fixed pitch font. I start by creating a font that is 1000 points. This
// is of course ridiculously big, but maybe it lets me measure widths
// accurately. Actually the size I use here is not that important and
// I will (repeatedly) change it later on.
    wxFontInfo bigfi(1000);
    bigfi.FaceName("CMU Typewriter Text");
    bigfont = new wxFont(bigfi);
    bigDC->SetFont(*bigfont);
    int w, h, d, xl;
    bigDC->GetTextExtent("X", &w, &h, &d, &xl);
    charWidth_1000 = w;
    bigDC->SelectObject(wxNullBitmap);
// I am now going to pick a default initial size for the client area
// of my main window. The choice here is perhaps somewhat arbitrary and
// may only be good for MY screen.
    clientWidth = 640;
    clientHeight = 880;
// If the default size would fill over 90% of screen width or height I
// clip it down to make it fit better. The consequence of this is that on
// computers in general the window size may not end up a neat multiple
// of anything in particular.
    if (10*clientWidth > 9*screenWidth) clientWidth = 90*screenWidth/100;
    if (10*clientHeight > 9*screenHeight) clientHeight = 90*screenHeight/100;
    SetClientSize(clientWidth, clientHeight);
// I put a minimum on the client size...
    SetMinClientSize(wxSize(400, 100));
// ... but a maximum on the total size including borders and decorations.
    SetMaxSize(wxSize(screenWidth, screenHeight));
    RepaintBuffer(); // I must get an image ready before I first try to
                        // display the window.
    Centre();
    Refresh();          // Force full re-draw so it appears on-screen
}

int bestP, bestQ, bestErr;

void farey(int p1, int q1, int p2, int q2, int maxQ)
{
    int uw = (p2 * clientWidth)/q2;
    int err = uw % 80;
    if (err <= bestErr)
    {   if (err < bestErr || q2 < bestQ)
        {   bestP = p2;
            bestQ = q2;
        }
        bestErr = err;
    }
    int p = p1 + p2;
    int q = q1 + q2;
    if (q > maxQ) return;
    farey(p1, q1, p, q, maxQ);
    farey(p, q, p2, q2, maxQ);
}

#if 0
// When I was developing this code I ran this fragment to help me judge how
// large denominators would be useful. I record the following table of
// which shows how large a denominator must be accepted in order to
// limit the gap at the right hand end of the line to a given number of
// pixels for all possible client widths in the range 400..2000.
//        gap  necessary denominator
//         10          13             
//          8          16             
//          6          18             
//          5          19             
//          4          22             
//          3          25             
//          2          31             
//          1          40             
//          0          53
// Based on this table I pick 25 as my cut-off.
    for (int m = 2; m<80; m++)
    {   int cw = clientWidth;
        int maxQ = m;
        int worstErr = 0;
        int Q = 0, WW = 0;
        for (clientWidth = 400; clientWidth <=2000; clientWidth++)
        {   bestP = 7;
            bestQ = 2;
            int uw = (bestP * clientWidth)/bestQ;
            bestErr = uw % 80;
            farey(7, 2, 4, 1, maxQ);
            if (bestErr > worstErr)
            {   worstErr = bestErr;
                WW = clientWidth;
                Q = bestQ;
            }
        }
        logprintf("at maxQ = %d see err = %d at cw=%d, Q=%d\n",
            m, worstErr, WW, Q);
        clientWidth = cw;
    }
#endif


void showmathFrame::RepaintBuffer()
{
    logprintf("RepaintBuffer called\n");
// Now that I know how big by client window will be I can work out how
// much of the big bitmap I will use.
    bestP = 7;
    bestQ = 2;
    int uw = (bestP * clientWidth)/bestQ;
    bestErr = uw % 80;
    farey(7, 2, 4, 1, 25);
// My small times will be in the range 20x20 to 40*40 pixels, which means that
// each covers say 2 lines of text and a width of 4 characters. 
    {   int r = 40/bestQ;
        bigTileSize = r*bestP;
        smallTileSize = r*bestQ;
    }
    if (bigTile != NULL) delete bigTile;
    bigTile =
        new wxBitmap(bigTileSize, bigTileSize, 24); // wxBITMAP_SCREEN_DEPTH);
    if (smallTile != NULL) delete smallTile;
    smallTile =
        new wxBitmap(smallTileSize, smallTileSize, 24); // wxBITMAP_SCREEN_DEPTH);
// The used region of the big bitmap will be bestP/bestQ times the size of
// the client area. Well that might not be exactly an integer, so I will
// round up here, and what I will end up with will be a width that is 0, 1,
// 2, 3 or 4 modulo 80. When scaled down to the client area that means that
// I can expect 80 columns of text to come within a pixel of the width. That
// seems like pretty good fitting to me.
    usedWidth = (bestP*clientWidth + bestQ - 1)/bestQ;
    usedHeight = (bestP*clientHeight + bestQ - 1)/bestQ;
    bigDC->SelectObject(*bigBitmap); // Writing to the DC writes into bitmap
// Predict a point size to use...
    charPointSize = (usedWidth*1000 + 40*charWidth_1000)/(80*charWidth_1000);
// There us a potential danger that xWidgets create a font here that was
// not exactly what I wanted - and in particular that it might have created
// one (slightly) bigger than I wanted, leading to 80 characters not fitting
// neatly on the line. If that is the case I will decrease the requested
// point size by 1 and try again. Equally I could at least imagine the
// font ending up too small, in which case I will make it larger.
    for (;;)
    {   bigfont->SetPointSize(charPointSize);
        bigDC->SetFont(*bigfont);
        int w, h, d, xl;
        bigDC->GetTextExtent("X", &w, &h, &d, &xl);
        if (80*w > usedWidth) charPointSize--;
        if (80*w <= usedWidth-80) charPointSize++;
        charWidth = w;
        charOffset = h - d;
        charLinespace = h + xl;
        break;
    }
    logprintf("Now 80 chars should have with %d in bigBitmap (cf %d)\n",
              80*charWidth, usedWidth);
//
// Now so that I can see what is going in a bit I will draw a row of
// characters across the top of bigBitmap...
    bigDC->SetBackground(*wxWHITE_BRUSH);
    sw.Start(0);
    bigDC->Clear();
    sw.Start(0);
    for (int i=0; i<80; i++)
    {   bigDC->DrawText(wxString((wchar_t)(i+0x21)),
           i*charWidth,
           charLinespace - charOffset);
    }
#if 1
// Draw blocks every 1000 pixels in bigBitmap
    bigDC->SetBrush(*wxYELLOW_BRUSH);
    for (int i=0; i<usedWidth; i+=1000)
        bigDC->DrawRectangle(i, 2*charLinespace, 500, charLinespace);
#endif
    bigDC->SelectObject(wxNullBitmap);
}

static char default_data[4096] =
    "deffont 1 Regular 24;"
    "put 1 -408 0 84;"
    "put 1 14256 0 104;"
    "put 1 26256 0 101;"
    "put 1 36912 0 32;"
    "put 1 42912 0 98;"
    "put 1 54912 0 111;"
    "put 1 66384 0 121;"
    "put 1 78384 0 32;"
    "put 1 84384 0 115;"
    "put 1 93528 0 116;"
    "put 1 100152 0 111;"
    "put 1 112152 0 111;"
    "put 1 124152 0 100;"
    "put 1 136152 0 32;"
    "put 1 142152 0 111;"
    "put 1 154152 0 110;"
    "put 1 166152 0 32;"
    "put 1 172152 0 116;"
    "put 1 179016 0 104;"
    "put 1 191016 0 101;"
    "put 1 201672 0 32;"
    "put 1 207672 0 98;"
    "put 1 219672 0 117;"
    "put 1 231672 0 114;"
    "put 1 240168 0 110;"
    "put 1 252168 0 105;"
    "put 1 258840 0 110;"
    "put 1 270840 0 103;"
    "put 1 282840 0 32;"
    "put 1 288840 0 100;"
    "put 1 300840 0 101;"
    "put 1 311496 0 99;"
    "put 1 321624 0 107;"
    "put 1 333744 0 44;"
    "put 1 339744 0 32;"
    "put 1 345744 0 119;"
    "put 1 363072 0 104;"
    "put 1 375072 0 101;"
    "put 1 385728 0 110;"
    "put 1 397728 0 99;"
    "put 1 408384 0 101;"
    "put 1 419040 0 32;"
    "put 1 425040 0 97;"
    "put 1 435696 0 108;"
    "put 1 442368 0 108;"
    "put 1 449040 0 32;"
    "put 1 455040 0 98;"
    "put 1 467040 0 117;"
    "put 1 479040 0 116;"
    "put 1 485712 0 32;"
    "put 1 491712 0 104;"
    "put 1 503712 0 101;"
    "put 1 514368 0 32;"
    "put 1 520368 0 104;"
    "put 1 532368 0 97;"
    "put 1 543024 0 100;"
    "put 1 555024 0 32;"
    "put 1 561024 0 102;"
    "put 1 570072 0 108;"
    "put 1 576744 0 101;"
    "put 1 587400 0 100;"
    "put 1 599400 0 46;";

// When I construct this I must avoid the wxTAB_TRAVERSAL style since that
// tends to get characters passed to child windows not this one. Avoiding
// that is the reason behind providing so many arguments to the parent
// constructor

showmathPanel::showmathPanel(showmathFrame *parent, const char *showmathfilename)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition,
              wxDefaultSize, 0L,"showmathPanel")
{
// I will read in any data once here and put it in a character buffer.
    FILE *f = NULL;
    if (showmathfilename == NULL) showmathData = default_data;
    else
    {   int i;
        stringInput = NULL;
        f = fopen(showmathfilename,"r");
        if (f == NULL)
        {   logprintf("File \"%s\" not found\n", showmathfilename);
            exit(1);
        }
        fseek(f, (off_t)0, SEEK_END);
        off_t len = ftell(f);
        showmathData = (char *)malloc(4+(size_t)len);
        fseek(f, (off_t)0, SEEK_SET);
        for (i=0; i<len; i++) showmathData[i] = getc(f);
        showmathData[i] = 0;
        fclose(f);
    }
    for (int i=0; i<MAX_FONTS; i++)
    {   FontValid[i] = false;
        Baseline[i] = 0;
    }
}


void showmathFrame::OnClose(wxCloseEvent &WXUNUSED(event))
{   Destroy();
#ifdef WIN32
// Otherwise under XP bad things happen for me. Like the application
// re-launching. I do not think I understand, but the extreme action of
// utterly killing the process does what I need!
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void showmathFrame::OnExit(wxCommandEvent &WXUNUSED(event))
{   Destroy();
#ifdef WIN32
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void showmathFrame::OnAbout(wxCommandEvent &WXUNUSED(event))
{
// At present this never gets activated!
    wxMessageBox(
        wxString::Format(
            "wxshowmath (A C Norman 2016)\n"
              "wxWidgets version: %s\n"
              "Operating system: %s",
            wxVERSION_STRING,
            wxGetOsDescription()),
        "About wxshowmath",
        wxOK | wxICON_INFORMATION,
        this);
}

void showmathFrame::OnSize(wxSizeEvent &WXUNUSED(event))
{   wxSize clientSize(GetClientSize());
    int w = clientSize.GetWidth(), h = clientSize.GetHeight();
    if (clientWidth == w) logprintf("Width has not changed\n");
    if (clientHeight == h) logprintf("Height has not changed\n");
//  if (clientWidth == w && clientHeight == h) return;
    clientWidth = w;
    clientHeight = h;
    logprintf("New window size %d*%d\n", clientWidth, clientHeight);
    panel->SetSize(clientWidth, clientHeight);
    logprintf("About to repaint\n");
    RepaintBuffer();
    logprintf("Completed repaint\n");
    Refresh();
}

void showmathPanel::OnChar(wxKeyEvent &event)
{
// This merely records the character in the log file.
    const char *msg ="OnChar", *raw ="";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw ="Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
}

void showmathPanel::OnKeyDown(wxKeyEvent &event)
{
// Again merely log the event.
    const char *msg ="OnKeyDown", *raw ="";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw ="Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
    event.Skip();
}

void showmathPanel::OnKeyUp(wxKeyEvent &event)
{
// Merely log the event.
    const char *msg ="OnKeyUp", *raw ="";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw ="Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
    event.Skip();
}

void showmathPanel::OnMouse(wxMouseEvent &event)
{
// Log but take no action.
    logprintf("Mouse event\n");
    event.Skip();
// Here I use a mouse event to force a re-draw.
    Refresh();     // forces redraw of everything
}

//- static int32_t convert_font_name(char *dest, char *src)
//- {
//- // The font name passed should be one of
//- //    cmuntt
//- //    odokai
//- //    math
//- //    <anything else>
//- //    <anything else>-Bold
//- //    <anything else>-Italic
//- //    <anything else>-BoldItalic
//- //
//-     int32_t r = wxFONTFLAG_DEFAULT;
//-     if (strcmp(src, "cmuntt") == 0) strcpy(dest, "CMU Typewriter Text");
//-     else if (strcmp(src, "odokai") == 0) strcpy(dest, "AR PL New Kai");
//-     else if (strcmp(src, "Math") == 0) strcpy(dest, "cslSTIXMath");
//-     else sprintf(dest, "cslSTIX");
//- // Here if the font name is suffixed as "-Bold" or "-Italic" or "-BoldItalic"
//-     if (strcmp(dest, "CMU Typewriter Text") == 0) r |= (F_cmuntt<<16);
//-     else if (strcmp(dest, "AR PL New Kai") == 0) r |= (F_odokai<<16);
//-     else if (strcmp(dest, "cslSTIXMath") == 0) r |= (F_Math<<16);
//- // I have not thought through and implemented support for bold and italic
//- // options here...
//- #ifdef PENDING_BOLD_AND_ITALIC
//-     else if ((r & (wxFONTFLAG_BOLD + wxFONTFLAG_ITALIC)) ==
//-              (wxFONTFLAG_BOLD + wxFONTFLAG_ITALIC)) r |= (F_BoldItalic<<16);
//-     else if ((r & wxFONTFLAG_BOLD) ==
//-              wxFONTFLAG_BOLD) r |= (F_Bold<<16);
//-     else if ((r & wxFONTFLAG_ITALIC) ==
//-              wxFONTFLAG_ITALIC) r |= (F_Italic<<16);
//-     else
//- #endif
//-     r |= (F_Regular<<16);
//-
//-     logprintf("Gives %s with flags %x\n", dest, r); fflush(stdout);
//-     return r;
//- }

static void allow_for_utf16(wchar_t *ccc, int cp)
{   if (sizeof(wchar_t) == 4 ||
        cp <= 0xffff)
    {   ccc[0] = cp;
        ccc[1] = 0;
    }
    else
    {   cp = (cp - 0x10000) & 0xfffff;
        ccc[0] = 0xd800 + (cp >> 10);
        ccc[1] = 0xdc00 + (cp & 0x3ff);
//      logprintf("Char mapped to %x %x\n", ccc[0], ccc[1]);
        ccc[2] = 0;
    }
}

void showmathPanel::OnPaint(wxPaintEvent &event)
{   logprintf("OnPaint called\n");
    wxPaintDC mydc(this);
    mydc.SetBackground(*wxWHITE_BRUSH);
// Here I may not need to repaint the whole region. I will try to sort out
// which bits need re-work... The code I am using here based on that in the
// wxWidgets documentation relating to Paint Events.
//@ The fillowing few lines would make sense if the window I was working
//@ with here was a scrolled one... which in the fullness of time it will be!
//@    int vbX, vbY;
//@    GetViewStart(&vbX, &vbY);
//@    logprintf("top left of client is at %d %d\n", vbX, vbY);
    wxRegionIterator upd(GetUpdateRegion());
    if (upd) logprintf("Have an update region\n");
    else logprintf("No update regions reported\n");
    while (upd)
    {   int vX = upd.GetX();
        int vY = upd.GetY();
        int vW = upd.GetW();
        int vH = upd.GetH();
        logprintf("Need to repaint %d %d %d %d\n", vX, vY, vW, vH);
        upd++;
    }

    sw.Start(0);
// I show several strategies here so I can compare performance and quality.
// Drawing the whole big bitmap all in one operation is by far the easiest
// scheme, but apart from the cost issues (which are themselves bad) it tends
// to lead to bad screen flicker and would mean that the whole screen had to
// be refreshed for every small update.
// The other version that uses a wxGraphicsContext scales the screen via
// tiles. This does not save time when the whole client area needs drawing,
// and indeed it may increase overheads a bit. But it will allow me to
// repaint just parts of the screen when I need to.
// Finally there is a version that avoids use of wxGraphicsContext and
// instead tries StretchBlit, which at least on some platforms ough to end
// up really fast since it goes done to the operating system (and ideally
// to the video card and its driver). At present that appears to do low
// quality re-sizing. At the time I was testing this a particular way that
// quality issues showed up was that I drew a row of yellow boxes with
// black borders below my test - the borders fails to be rendered.
// When I use tiles and enable anti-aliasing as I draw then I see artefects at
// tile borders, so perhaps I will try goint back to drawing the whole bitmap?
//
// I will let the user go "-xNNN" on the command to pick an option here. The
// bottom decimal digit will pick a strategy.
    wxGraphicsContext *gg;
    double scaledWidth, scaledHeight;
    int tileCount = 0;
    switch (options % 10)
    {
    default:
    case 0:
// -x0 or default. Simply write whole bitmap using a wxGraphicsContext. This
// is especially bad because it may inspect the whole of bigBitmap even though
// much of it will not correspont to areas visible within the client area of
// the window.
        gg = wxGraphicsContext::Create(mydc);
        scaledWidth = bigWidth*clientWidth/(double)usedWidth;
        scaledHeight = bigHeight*clientWidth/(double)usedWidth;
        gg->DrawBitmap(*bigBitmap, 0.0, 0.0, scaledWidth, scaledHeight);
        delete gg;
        break;
    case 1:
// -x1. This was to see if setting up a clipping region led DrawBitmap
// to run fast by only looking at the relevent part. It seems it does not
// gain anything like as much as one might ideally hope.
        gg = wxGraphicsContext::Create(mydc);
        scaledWidth = bigWidth*clientWidth/(double)usedWidth;
        scaledHeight = bigHeight*clientWidth/(double)usedWidth;
        tileCount = 0;
        for (int y=0; y<clientHeight; y+=smallTileSize)
        {   for (int x=0; x<clientWidth; x+=smallTileSize)
            {
// This is to see if drawing a big bitmap but subject to clipping is
// as slow as drawing it without clipping.
                gg->ResetClip();
                gg->Clip(x, y, smallTileSize, smallTileSize);
                gg->DrawBitmap(*bigBitmap, 0.0, 0.0, scaledWidth, scaledHeight);
                tileCount++;
            }
        }
        delete gg;
        break;
    case 2: case 12: case 22: case 32: case 42:
    case 3: case 13: case 23: case 33: case 43:
// -x2 and -x3.  -x2 has no anti-aliasing, -x3 has some.
// Here I paint the bitmap tile by tile... Each tile corresponds to a whole
// number of pixels in both big and screen resolution, so I rather hope there
// is no scope for odd effects are tile boundaries. HOWEVER when I try things
// I observe that there ARE visible artefects where tiles abut. Rats!
        tileCount = 0;
        bigDC->SelectObject(*bigBitmap);
        gg = wxGraphicsContext::Create(mydc);
        logprintf("interp=%d, antiA=%d\n",
            gg->GetInterpolationQuality(), gg->GetAntialiasMode());
        if (options % 10 == 2) gg->SetAntialiasMode(wxANTIALIAS_NONE);
        else gg->SetAntialiasMode(wxANTIALIAS_DEFAULT);
// What I find here is that settting an interpolation option other that NONE
// leads to artefacts at tile boundaries, but not having interpolation leads
// to poor randering of characters.
        switch ((options/10) % 10)
        {
        case 0:
            gg->SetInterpolationQuality(wxINTERPOLATION_NONE);
            break;
        case 1:
            gg->SetInterpolationQuality(wxINTERPOLATION_FAST);
            break;
        case 2:
            gg->SetInterpolationQuality(wxINTERPOLATION_GOOD);
            break;
        case 3:
            gg->SetInterpolationQuality(wxINTERPOLATION_BEST);
            break;
        case 4:
            gg->SetInterpolationQuality(wxINTERPOLATION_DEFAULT);
            break;
        }
        logprintf("interp=%d, antiA=%d\n",
            gg->GetInterpolationQuality(), gg->GetAntialiasMode());
        for (int y=0; y<clientHeight; y+=smallTileSize)
        {   int by = bigTileSize*(y/smallTileSize);
            for (int x=0; x<clientWidth; x+=smallTileSize)
            {   int bx = bigTileSize*(x/smallTileSize);
                tileDC->SelectObject(*bigTile);
                tileDC->Blit(0, 0, bigTileSize, bigTileSize,
                             bigDC, bx, by);
                tileDC->SelectObject(wxNullBitmap);
                gg->DrawBitmap(*bigTile, x, y, smallTileSize, smallTileSize);
                tileCount++;
            }
        }
        bigDC->SelectObject(wxNullBitmap);
        delete gg;
        logprintf("Drew using %d tiles\n", tileCount);
        break;
    case 4:
// -x4. Use StretchBlit on a regular DC rather than going via a Graphics
// Context. This seems to implement a crude shrink that is does not end up
// looking good!
        tileCount = 0;
        bigDC->SelectObject(*bigBitmap);
        for (int y=0; y<clientHeight; y+=smallTileSize)
        {   int by = bigTileSize*(y/smallTileSize);
            for (int x=0; x<clientWidth; x+=smallTileSize)
            {   int bx = bigTileSize*(x/smallTileSize);
                mydc.StretchBlit(x, y, smallTileSize, smallTileSize,
                    bigDC, bx, by, bigTileSize, bigTileSize);
                tileCount++;
            }
        }
        bigDC->SelectObject(wxNullBitmap);
        logprintf("Drew using %d tiles\n", tileCount);
        break;
    case 5:
        logprintf("This will be for my own code for down-sizing\n");
        typedef wxPixelData<wxBitmap, wxNativePixelFormat> PixelData;
        logprintf("bigBitmap = %p\n", bigBitmap);
        logprintf("Line %d %" PRId64 "\n", __LINE__, (int64_t)sw.Time());
// For reasons that I do not yet understand this next line frequently takes
// an apprciable fraction of a second, and in doing so utterly dominates
// all costs. This is BAD.
        PixelData bigData(*bigBitmap);
        logprintf("Line %d %" PRId64 " %d\n", __LINE__, (int64_t)sw.Time(),
                  (int)time(NULL));
        if (!bigData) logprintf("Creation of bigData failed\n");
        PixelData smallData(*smallTile);
        if (!smallData) logprintf("Creation of smallData failed\n");
        PixelData::Iterator pBig(bigData);
        PixelData::Iterator pSmall(smallData);

        for (int tiley=0; tiley<clientHeight; tiley+=smallTileSize)
        for (int tilex=0; tilex<clientWidth;  tilex+=smallTileSize)
        {
            pBig.MoveTo(bigData, (bigTileSize*tilex)/smallTileSize,
                                 (bigTileSize*tiley)/smallTileSize);
            pSmall.MoveTo(smallData, 0, 0);
            int srcy=0, srcy1=smallTileSize, desty=0, desty1=bigTileSize;
            int srcpixyR[40], srcpixyG[40], srcpixyB[40], 
                destpixyR[160], destpixyG[160], destpixyB[160];
            int scale = bigTileSize*bigTileSize;
            for (int i=0; i<smallTileSize; i++)
            {   srcpixyR[i] = 0;  srcpixyG[i] = 0;  srcpixyB[i] = 0; 
                destpixyR[i] = 0; destpixyG[i] = 0; destpixyB[i] = 0;
            }
            while (desty < smallTileSize)
            {
                PixelData::Iterator rowStartSmall = pSmall;
                PixelData::Iterator rowStartBig = pBig;
                int srcx=0, srcx1=smallTileSize, destx=0, destx1=bigTileSize;
                int srcpixxR=0, srcpixxG=0, srcpixxB=0,
                    destpixxR=0, destpixxG=0, destpixxB=0,
                    w;
                while (destx < smallTileSize)
                {
// The next line is the only one where I access the source bitmap...
                    srcpixxR = pBig.Red();
                    srcpixxG = pBig.Green();
                    srcpixxB = pBig.Blue();
                    ++pBig;
                    srcx++;
                    if (srcx1 < destx1)
                    {   destpixxR += smallTileSize*srcpixxR;
                        destpixxG += smallTileSize*srcpixxG;
                        destpixxB += smallTileSize*srcpixxB;
                    }
                    else
                    {   w = srcx1 - destx1;
                        srcpixyR[destx] = (srcpixxR*(smallTileSize-w) + destpixxR);
                        srcpixyG[destx] = (srcpixxG*(smallTileSize-w) + destpixxG);
                        srcpixyB[destx] = (srcpixxB*(smallTileSize-w) + destpixxB);
                        destpixxR = srcpixxR*w;
                        destpixxG = srcpixxG*w;
                        destpixxB = srcpixxB*w;
                        destx++;
                        destx1 += bigTileSize;
                    }
                    srcx1 += smallTileSize;
                }
                pBig = rowStartBig;
                pBig.OffsetY(bigData, 1);
                srcy++;
                if (srcy1 < desty1)
                {   for (int i=0; i<smallTileSize; i++)
                    {   destpixyR[i] += smallTileSize*srcpixyR[i];
                        destpixyG[i] += smallTileSize*srcpixyG[i];
                        destpixyB[i] += smallTileSize*srcpixyB[i];
                    }
                }
                else
                {   w = srcy1 - desty1;
                    for (int i=0; i<smallTileSize; i++)
                    {
// The next line is the only one where I access the destination bitmap...
                        pSmall.Red() =
                            (srcpixyR[i]*(smallTileSize-w) + destpixyR[i])/scale;
                        pSmall.Green() =
                            (srcpixyG[i]*(smallTileSize-w) + destpixyG[i])/scale;
                        pSmall.Blue() =
                            (srcpixyB[i]*(smallTileSize-w) + destpixyB[i])/scale;
                        ++pSmall;
                        destpixyR[i] = srcpixyR[i]*w;
                        destpixyG[i] = srcpixyG[i]*w;
                        destpixyB[i] = srcpixyB[i]*w;
                    }
                    pSmall = rowStartSmall;
                    pSmall.OffsetY(smallData, 1);
                    desty++;
                    desty1 += bigTileSize;
                }
                srcy1 += smallTileSize;
            }
            mydc.DrawBitmap(*smallTile, tilex, tiley);
        }
        break;
    }
    logprintf("Scale frombitmap to screen in %" PRId64 "\n", (int64_t)sw.Time());

    return;

// The next could probably be done merely by setting a background colour
    wxColour c1(230, 200, 255);
    wxBrush b1(c1);
//-     gc->SetBrush(b1);
    wxSize window(mydc.GetSize());
    logprintf("Window is %d by %d\n", window.GetWidth(), window.GetHeight());
//-     gc->DrawRectangle(0.0, 0.0,
//-                       (double)window.GetWidth(),
//-                       (double)window.GetHeight());
//-
//- // The FixedPitch font will be for a line spacing of 24 pixels,
//- // but I will scale it as relevant.
//-     FixedPitch =
//-         gc->CreateFont(
//-             wxFont(wxFontInfo(24).FaceName(wxT("CMU Typewriter Text"))));
//-     double dwidth, dheight, ddepth, dleading;
//-     gc->SetFont(FixedPitch);
//-     gc->GetTextExtent(wxT("M"), &dwidth, &dheight, &ddepth, &dleading);
//-     charWidth = dwidth;
//-     logprintf("charWidth=%#.6g\n", charWidth);
//-     logprintf("height = %#.6g total height = %#.6g leading = %#.6g\n",
//-               dheight-ddepth-dleading, dheight, dleading);
//-
//-     double screenWidth = (double)window.GetWidth();
//-     double lineWidth = 80.0*charWidth;
//-     double scale = screenWidth/lineWidth;
//- // This will now scale everything so that I end up with 80 characters from
//- // that fixed-pitch font across the width of my window.
//-     gc->Scale(scale, scale);
//-     logprintf("Scale now %.6g\n", scale); fflush(stdout);
//-
//- // Now I should find how all my fonts will be arranged in terms of the
//- // distance from the index point used by wxWidgets to the font base-line
//- // as relevent in .afm metrics.
//-     for (;;)
//-     {   int ddd;
//-         wxGraphicsFont tf1 =
//-             gc->CreateFont(10000.0, "cslSTIX",
//-                            wxFONTFLAG_BOLD + wxFONTFLAG_ITALIC);
//-         gc->SetFont(tf1);
//-         gc->GetTextExtent(wxString((wchar_t)'X'),
//-                           &dwidth, &dheight, &ddepth, &dleading);
//-         logprintf("%.6g %.6g [%.6g]\n",
//-                   dheight, ddepth, dheight-ddepth);
//-         ddd = (int)((dheight - ddepth)/10.0 + 0.5);
//-         if (ddd == chardepth_WIN32[F_BoldItalic])
//-         {   chardepth = chardepth_WIN32;
//-             tf1 = FixedPitch;
//-             break;
//-         }
//-         tf1 =
//-             gc->CreateFont(10000.0, "AR PL New Kai", wxFONTFLAG_DEFAULT);
//-         gc->SetFont(tf1);
//-         gc->GetTextExtent(wxString((wchar_t)'X'),
//-                           &dwidth, &dheight, &ddepth, &dleading);
//-         logprintf("%.6g %.6g [%.6g]\n",
//-                   dheight, ddepth, dheight-ddepth);
//-         ddd = (int)((dheight - ddepth)/10.0 + 0.5);
//-         if (ddd == chardepth_X11[F_odokai])
//-         {   chardepth = chardepth_X11;
//-             tf1 = FixedPitch;
//-             break;
//-         }
//-         tf1 =
//-             gc->CreateFont(10000.0, "cslSTIXMath", wxFONTFLAG_DEFAULT);
//-         gc->SetFont(tf1);
//-         gc->GetTextExtent(wxString((wchar_t)unicode_INTEGRAL),
//-                           &dwidth, &dheight, &ddepth, &dleading);
//-         logprintf("%.6g %.6g [%.6g]\n",
//-                   dheight, ddepth, dheight-ddepth);
//-         ddd = (int)((dheight - ddepth)/10.0 + 0.5);
//-         if (ddd == chardepth_OSX[F_Math])
//-         {   chardepth = chardepth_OSX;
//-             tf1 = FixedPitch;
//-             break;
//-         }
//-         logprintf("\n+++ Character positioning not recognized\n");
//-         chardepth = chardepth_X11;
//-         tf1 = FixedPitch;
//-         break;
//-     }

//-     gc->SetFont(FixedPitch);
//-     double width, height, descent, xleading;
//-     gc->GetTextExtent(wxString((wchar_t)'x'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g fixedpitch\n", width, height, descent, xleading);
//-     FixedPitchBaseline = height - descent;
//-     logprintf("Fixed Pitch Baseline = %.6g\n", height-descent);
//- // Sort of for fun I put a row of 80 characters at the top of the screen
//- // so I can show how fixed pitch stuff might end up being rendered.
//-     gc->SetFont(FixedPitch);
//-     for (int i=0; i<80; i++)
//-         gc->DrawText(wxString((wchar_t)(i+0x21)), (double)i*charWidth, 24.0-FixedPitchBaseline);
#if 0
    wxColour c2(29, 99, 25);
    wxBrush b2(c2);
    gc->SetBrush(b2);
    for (int x=0; x<1000; x+=10)
        for (int y=0; y<=1000; y+=10)
            if (((x/10)+(y/10)) & 1 != 0)
                gc->DrawRectangle((double)x, (double)y, 10.0, 10.0);
#endif


//- // Now I need to do something more serious!
//-     wxGraphicsFont regular =
//-         gc->CreateFont(wxFont(wxFontInfo(24).FaceName(wxT("cslSTIX"))));
//-     if (regular.IsNull()) logprintf("cslSTIX font not created\n");
//-     gc->SetFont(regular);
//-     gc->GetTextExtent(wxString((wchar_t)'x'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g regular\n", width, height, descent, xleading);
//-     double regularBaseline = height - descent;
//-     logprintf("regular baseline = %.6g\n", height-descent);
//-     wxGraphicsFont math =
//-         gc->CreateFont(wxFont(wxFontInfo(24).FaceName(wxT("cslSTIXMath"))));
//-     if (math.IsNull()) logprintf("cslSTIXMath font not created\n");
//-     else logprintf("Sym font should be OK\n");
//-     gc->SetFont(math);
//-     gc->GetTextExtent(wxString((wchar_t)'x'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g math\n", width, height, descent, xleading);
//-     gc->GetTextExtent(wxString((wchar_t)'M'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g math\n", width, height, descent, xleading);
//-     gc->GetTextExtent(wxString((wchar_t)'j'), &width, &height, &descent, &xleading);
//-     logprintf("%.6g %.6g %.6g %.6g math\n", width, height, descent, xleading);
//-     double symbolsBaseline = height - descent;

// cslSTIXMath puts the glyphs used to build up big delimiters in a
// private use area. It expects the code to use maths tables to discover
// where they are rather than mere unicode names.

#define stix_LEFT_CURLY_BRACKET_UPPER_HOOK    0x10821c
#define stix_LEFT_CURLY_BRACKET_MIDDLE_PIECE  0x10821d
#define stix_CURLY_BRACKET_EXTENSION          0x10821f
#define stix_LEFT_CURLY_BRACKET_LOWER_HOOK    0x10821e
//-     gc->SetFont(math);
//-     gc->GetTextExtent(wxT("M"), &dwidth, &dheight, &ddepth, &dleading);
//-     logprintf("(D)charWidth=%#.3g\n", dwidth);
//-     logprintf("(D)height = %#.3g total height = %#.3g leading = %#.3g\n",
//-               dheight-ddepth-dleading, dheight, dleading);
//-     lookupchar(F_Math, stix_LEFT_CURLY_BRACKET_UPPER_HOOK);
//-     logprintf("upper hook   %d %d\n", c_lly, c_ury);
//-     lookupchar(F_Math, stix_LEFT_CURLY_BRACKET_MIDDLE_PIECE);
//-     logprintf("middle piece %d %d\n", c_lly, c_ury);
//-     lookupchar(F_Math, stix_LEFT_CURLY_BRACKET_LOWER_HOOK);
//-     logprintf("lower hook   %d %d\n", c_lly, c_ury);
//-     lookupchar(F_Math, stix_CURLY_BRACKET_EXTENSION);
//-     logprintf("extension    %d %d\n", c_lly, c_ury);
//- #define H (24.0)
//- #define XX 120.0
//- #define YY 100.0
//-     {   wchar_t ccc[4];
//-         allow_for_utf16(ccc, stix_LEFT_CURLY_BRACKET_UPPER_HOOK);
//-         gc->DrawText(wxString(ccc), XX, YY-H-symbolsBaseline);
//-         allow_for_utf16(ccc, stix_LEFT_CURLY_BRACKET_MIDDLE_PIECE);
//-         gc->DrawText(wxString(ccc), XX, YY-symbolsBaseline);
//-         allow_for_utf16(ccc, stix_CURLY_BRACKET_EXTENSION);
//-         gc->DrawText(wxString(ccc), XX, YY+H-symbolsBaseline);
//-         allow_for_utf16(ccc, stix_LEFT_CURLY_BRACKET_LOWER_HOOK);
//-         gc->DrawText(wxString(ccc), XX, YY+2.0*H-symbolsBaseline);
//-     }
//- // The next two have codepoints in the Basic Multilingual Plane so
//- // I do not need to mess around with encoding even on platforms like
//- // Windows that use UTF16 internally.
//-     gc->SetFont(regular);
//-     gc->DrawText(wxString((wchar_t)unicode_GREEK_SMALL_LETTER_OMEGA),        XX, YY+100.0-regularBaseline);
//-     gc->DrawText(wxString((wchar_t)unicode_RIGHT_ANGLE_WITH_DOWNWARDS_ZIGZAG_ARROW), XX+100.0, YY+100.0-regularBaseline);

    char *in = showmathData;
    logprintf("About to process data:\n\"%.70s\"... ...\n\n", in);
    do
    {   int x, y, n, cp, size;
        char name[100], name1[64];
        while (isspace(*in)) in++;
        if (*in == 0) break;
        if (*in == '#' || *in == '%')
// # ...     comments extend to the end of the line
// % ...
        {   n = 0;
            while (*in != 0 && *in != '\n')
                if (n < 99) name[n++] = *in++;
                else in++;
            name[n] = 0;
            logprintf("%s\n", name);
            if (*in == '\n') in++;
            continue;
        }
        else if (sscanf(in, "deffont %d %60s %d;", &n, name, &size) == 3 &&
// deffont number name size;   define font with given number
                 0 <= n &&
                 n < MAX_FONTS)
        {   //- int flags = convert_font_name(name1, name);
            //- int col;
            logprintf("font[%d] = \"%s\" size %d\n", n, name1, size);
//-             graphicsFont[n] = gc->CreateFont((double)size, name1, flags & 0xffff);
//-             gc->SetFont(graphicsFont[n]);
//-             gc->GetTextExtent(wxString((wchar_t)'('), &width, &height, &descent, &xleading);
//-             logprintf("( %s/%d: %.6g %.6g [%.6g]\n",
//-                       name1, size, height, descent, height-descent);
//-             col = logprintf("    %d,", (int)((height - descent)/10.0 + 0.5));
//-             while (col++ < 20) logprintf(" ");
//-             logprintf("// %s\n", name);
//-             graphicsBaseline[n] =
//-                 (double)size * (double)chardepth[(flags >> 16) & 0x1f] / 1000.0;
//-             logprintf("from table baseline offset = %.6g\n", graphicsBaseline[n]);
        }
        else if (sscanf(in, "put %d %d %d 0x%x;", &n, &x, &y, &cp) == 4 ||
                 sscanf(in, "put %d %d %d %d;", &n, &x, &y, &cp) == 4)
        {
// put fontnum xpos ypos codepoint;  dump character onto screen
// note x & y in units of 1/1000 point.
//          logprintf("Font %d (%d,%d) char %d = %#x\n", n, x, y, cp, cp);
//-             gc->SetFont(graphicsFont[n]);
            wchar_t ccc[4];
// For the benefit of Windows I need to represent code points in other
// then the basic multilingual pane as surrogate pairs. Well that will
// probably apply anywhere where sizeof(wchar_t) < 4.
            allow_for_utf16(ccc, cp);
//-             gc->DrawText(wxString(ccc),
//-                          x/1000, 400-y/1000-graphicsBaseline[n]);
        }
        else logprintf("\nLine <%.32s> unrecognised\n", in);
        in = strchr(in, ';');
        if (in != NULL) in++;
    }
    while (in != NULL);

// I will mark all the fonts I might have created as invalid now
// that the context they were set up for is being left.
    for (int i=0; i<MAX_FONTS; i++) FontValid[i] = false;
    return;
}

// A dummy definition that is needed because of wxfwin.cpp

int windowed_worker(int argc, const char *argv[],
                    fwin_entrypoint *fwin_main)
{   return 0;
}

// end of wxshowmath.cpp
