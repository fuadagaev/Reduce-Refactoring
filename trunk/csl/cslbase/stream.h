// stream.h                              Copyright (C) Codemist, 1995-2017

//
// Header defining the structure of stream objects in CSL, and also
// the format for "library" files used with the fast-load mechanism.
//


/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

#ifndef header_stream_h
#define header_stream_h 1

extern FILE *non_terminal_input;
extern int terminal_pushed;

typedef int character_stream_reader(LispObject);
typedef int character_stream_writer(int, LispObject);
typedef int32_t other_stream_op(int32_t, LispObject);

extern LispObject Lopen(LispObject env, LispObject name, LispObject dir);

//
// The values used here are placed where characters might be, or possibly
// OR'd with character codes. They are now such that even if I am using
// 21-bit characters (Unicode) all ought to be well. Anything that can be
// treated as a character (including an end of file marker) will be limited
// to                   0x001fffff
// so these two bits are well out of the way.
//
#define ESCAPED_CHAR    0x20000000
#define NOT_CHAR        0x40000000

extern int char_to_terminal(int c, LispObject f);
extern int char_to_file(int c, LispObject f);
extern int char_to_pipeout(int c, LispObject f);
extern int char_to_synonym(int c, LispObject f);
extern int char_to_broadcast(int c, LispObject f);
extern int char_to_illegal(int c, LispObject f);
extern int char_to_list(int c, LispObject f);
extern int code_to_list(int c, LispObject f);
extern int count_character(int c, LispObject f);
extern int binary_outchar(int c, LispObject f);
extern int char_to_function(int c, LispObject f);
#if defined HAVE_LIBFOX || defined HAVE_LIBWX
extern int char_to_math(int c, LispObject f);
extern int char_to_spool(int c, LispObject f);
#endif

extern int32_t write_action_terminal(int32_t c, LispObject f);
extern int32_t write_action_file(int32_t c, LispObject f);
extern int32_t write_action_pipe(int32_t c, LispObject f);
extern int32_t write_action_synonym(int32_t c, LispObject f);
extern int32_t write_action_broadcast(int32_t c, LispObject f);
extern int32_t write_action_twoway(int32_t c, LispObject f);
extern int32_t write_action_illegal(int32_t c, LispObject f);
extern int32_t write_action_list(int32_t c, LispObject f);
#if defined HAVE_LIBFOX || defined HAVE_LIBWX
extern int32_t write_action_math(int32_t c, LispObject f);
extern int32_t write_action_spool(int32_t c, LispObject f);
#endif

extern int char_from_terminal(LispObject f);
extern int char_from_file(LispObject f);
extern int char_from_pipe(LispObject f);
extern int char_from_synonym(LispObject f);
extern int char_from_concatenated(LispObject f);
extern int char_from_echo(LispObject f);
extern int char_from_illegal(LispObject f);
extern int char_from_list(LispObject f);
extern int char_from_vector(LispObject f);

extern int32_t read_action_terminal(int32_t c, LispObject f);
extern int32_t read_action_file(int32_t c, LispObject f);
extern int32_t read_action_output_file(int32_t c, LispObject f);
extern int32_t read_action_synonym(int32_t c, LispObject f);
extern int32_t read_action_concatenated(int32_t c, LispObject f);
extern int32_t read_action_echo(int32_t c, LispObject f);
extern int32_t read_action_twoway(int32_t c, LispObject f);
extern int32_t read_action_illegal(int32_t c, LispObject f);
extern int32_t read_action_list(int32_t c, LispObject f);
extern int32_t read_action_vector(int32_t c, LispObject f);

#define MAX_PROMPT_LENGTH 80
extern char memory_print_buffer[MAX_PROMPT_LENGTH];

//
// The following typedef shows the expected layout of a Lisp_STREAM object,
// but it is not used directly because I need to insist that each field is
// exactly CELL wide. Thus when I access things that contain pointers I
// will perform horrible casts. This is essential if I am to be able to host
// this system on certain 64-bit systems.
//
//  typedef struct Lisp_STREAM
//  {
//      Header h;                              0
//      LispObject type;                       CELL
//      LispObject write_data;                 2*CELL
//      LispObject read_data;                  3*CELL
//      FILE *file;                            4*CELL
//      character_stream_writer *write_fn;     5*CELL
//      other_stream_op *write_other_fn;       6*CELL
//      intptr_t line_length;                  7*CELL
//      intptr_t byte_pos;                     8*CELL
//      intptr_t char_pos;                     9*CELL
//      character_stream_reader *read_fn;      10*CELL
//      other_stream_op *read_other_fn;        11*CELL
//      intptr_t pushed_char;                  12*CELL
//      intptr_t spare;                        13*CELL
//  } Lisp_STREAM;
//
// Now in fact I could make STREAM objects longer than this provided I
// accept that if a stream is moved from a 32 to a 64-bit world its length
// will alter. If the extra space is for use as a buffer that feels OK to me
// because the stream should not be active while it is being dumped and
// re-loaded. I can use stream_spare to tell me where the buffer begins.
// So here I am now putting STREAM_BUFFER_SIZE bytes at the end of each
// STREAM object, and that will be 64K on a 64-bit machine and 32K on
// a 32-bit one. I am not yet doing that and may not need to until and unless
// I make the code here multi-threaded.
//

#define STREAM_BUFFER_SIZE    (8192*CELL)
#define STREAM_SIZE           (14*CELL)
#define BUFFERED_STREAM_SIZE  (STREAM_SIZE+STREAM_BUFFER_SIZE)

#define stream_type(v)        elt(v, 0)
#define stream_write_data(v)  elt(v, 1)
#define stream_read_data(v)   elt(v, 2)
#define stream_file(v)        ((FILE *)elt(v, 3))
#define stream_write_fn(v)    ((character_stream_writer *)elt(v, 4))
#define stream_write_other(v) ((other_stream_op *)elt(v,5))
#define stream_line_length(v) elt(v, 6)
#define stream_byte_pos(v)    elt(v, 7)
#define stream_char_pos(v)    elt(v, 8)
#define stream_read_fn(v)     ((character_stream_reader *)elt(v, 9))
#define stream_read_other(v)  ((other_stream_op *)elt(v,10))
#define stream_pushed_char(v) elt(v, 11)
#define stream_spare(v)       elt(v, 12)

#define set_stream_file(v, x)           (elt(v, 3) = (LispObject)(x))
#define set_stream_write_fn(v, x)       (elt(v, 4) = (LispObject)(x))
#define set_stream_write_other(v, x)    (elt(v, 5) = (LispObject)(x))
#define set_stream_read_fn(v, x)        (elt(v, 9) = (LispObject)(x))
#define set_stream_read_other(v, x)     (elt(v, 10) = (LispObject)(x))

#define STREAM_HEADER (TAG_HDR_IMMED + TYPE_STREAM + (STREAM_SIZE<<(Tw+5)))
#define STREAM_FLAG_PIPE       1

#define is_stream(v)      (is_vector(v) && vechdr(v) == STREAM_HEADER)

#define putc_stream(c, f)          (stream_write_fn(f)((c) & 0xff, (f)))
#define getc_stream(f)             (stream_read_fn(f)(f))
#define other_write_action(c, f)   (stream_write_other(f)((c), (f)))
#define other_read_action(c, f)    (stream_read_other(f)((c), (f)))

//
// For other_write_action if the top four bits of the operand select an
// action to be performed, while the remaining 28 are available to pass
// an operand.
//

#define WRITE_GET_INFO        0x00000000
#  define WRITE_GET_LINE_LENGTH        0
#  define WRITE_GET_COLUMN             1
#  define WRITE_IS_CONSOLE             2
#define WRITE_CLOSE                  0x10000000
#define WRITE_FLUSH                  0x20000000
#define WRITE_SET_LINELENGTH         0x30000000
#define WRITE_SET_COLUMN             0x40000000
#define WRITE_SET_LINELENGTH_DEFAULT 0x50000000

//
// For other_read_action() if the operand is in the range -1 to 0x10ffff then
// it is a character to be unread (-1 is used for EOF). Otherwise if the most
// significant bit is a "1" then the request is a seek (with a 31-bit address
// within the stream to go to).  The remaining few cases are things that do
// not need additional data passed.
//
#define READ_SEEK          0x80000000
#define READ_TELL          0x40000000
#define READ_CLOSE         0x40000001
#define READ_FLUSH         0x40000002
#define READ_IS_CONSOLE    0x40000003
#define READ_END           0x40000004

// Print options...

#define escape_yes          0x0001    // make output re-readable

#define escape_fold_down    0x0002    // force lower case output
#define escape_fold_up      0x0004    // FORCE UPPER CASE OUTPUT
#define escape_capitalize   0x0008    // Force Capitalisation (!)

#define escape_binary       0x0010    // print format for numbers
#define escape_octal        0x0020    // (including bignums)
#define escape_hex          0x0040
#define escape_nolinebreak  0x0080    // use infinite line-length
#define escape_hexwidth     0x3f00    // 6 bits to specify width of hex/bin
#define escape_width(n)     (((n) & escape_hexwidth) >> 8)
#define escape_checksum     0x4000    // doing a checksum operation
#define escape_exploding    0x8000    // in explode, exploden etc


extern LispObject make_stream_handle(void);
extern bool use_wimp;

extern character_reader *procedural_input;
extern character_writer *procedural_output;

//
// Now support for the structure of image files....
//


//
// This version of the directory structure can cope with up to 2047
// modules in any single library. It can also cope with a directory
// being mapped onto an operating-system directory rather than my own
// sub-structure packed within a file.
//

#define IMAGE_FORMAT_VERSION       '5'

#define DIRECTORY_SIZE              8    // Initial directory size

typedef struct directory_header
{   char C, S, L, version;  // Identification
    unsigned char dirext,   // Extra bits for dirused, dirsize
             dirsize,  // Number of directory entries provided
             dirused,  // Number currently in use
             updated;  // In need of compaction & other flags
    char eof[4];            // fseek/ftell location of end of file
} directory_header;

#define get_dirused(d) ((int)((d).dirused + (((d).dirext & 0x0f)<<8)))
#define get_dirsize(d) ((int)((d).dirsize + (((d).dirext & 0xf0)<<4)))

typedef struct directory_entry
{   char data[44];
//
//  char newline;                * Makes file easier to read as a text file! *
//  char name[12];               * blank padded to 12 characters             *
//                               * but with special rules for root image etc *
//  char date[24];
//  char position[4];            * Machine byte-order insensitive format     *
//  char size[3];                * Ditto                                     *
//
} directory_entry;

//
// I use these macros rather than just the structure definition shown above
// so that the behaviour of the code is not sensitive to attempts by a C
// compiler to align things for me.  Think C 5.0 on the Macintosh (and
// probably many other C compilers) put padder bytes in the original
// structure to give word-alignment.
//
#define D_newline     data[0]
#define D_name        data[1]
#define D_space       data[12]
#define D_date        data[13]
#define D_position    data[37]
#define D_size        data[41]

#define name_size     12
#define date_size     24

//
// The limit set here to the length of the name of a directory should only
// have an effect on cosmetics not functionality.
//
#define DIRNAME_LENGTH  256
#define NEWLINE_CHAR    0x0a

//
// The D_newline location in a directory originally held a newline,
// because doing so resulted in image files being a little bit easier
// to interpret when looked at with a simple text editor. But then
// it turned out that the C value `\n' was not the same on all computers,
// and so I used a literal hex value 0x0a instead, expecting it to
// be the same as '\n' on "most" systems.
//

typedef struct directory
{   directory_header h;
    FILE *f;
    const char *full_filename;    // NULL unless native directory
//
// It is unexpectedly and unpleasantly the case that the "filename"
// field here must be the last one before the array of directory
// entries. This is because in the case where an image file is
// left pending at startup the structure is extended overlapping where the
// directory entries will end up to hold a full-length file name not merely
// one truncated to DIRNAME_LENGTH.
//
    char filename[DIRNAME_LENGTH];
    directory_entry d[1];   // Will usually have many more entries
} directory;

#ifdef COMMON
#  define MIDDLE_INITIAL   'C'
#else
#  define MIDDLE_INITIAL   'S'
#endif

//
// Flags for the UPDATED field
//

#define D_WRITE_OK  1
#define D_UPDATED   2
#define D_COMPACT   4
#define D_PENDING   8

extern directory *fasl_files[MAX_FASL_PATHS], *rootDirectory;
#define PDS_INPUT   0
#define PDS_OUTPUT  1
#define PDS_PENDING 2
extern directory *open_pds(const char *name, int mode);
extern bool finished_with(int h);

#endif // header_stream_h

// end of stream.h