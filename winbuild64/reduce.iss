;;----------------------------------------------------------------;;
;; -- reduce.iss --  REDUCE InnoSetup installation script         ;;
;;----------------------------------------------------------------;;
;;                                                                ;;
;;  * InnoSetup version 5.1.7 or above is recommended             ;;
;;                                                                ;;
;;  * IMPORTANT!                                                  ;;
;;    Section [CustomMessages] below contains messages            ;;
;;    in several 8-bit encodings (code pages 1251, 1252).         ;;
;;    Don't use any encoding conversion tool (e.g. iconv,         ;;
;;    recode) on this file directly!                              ;;
;;                                                                ;;
;;----------------------------------------------------------------;;


[Setup]
AppName=REDUCE
AppVerName=REDUCE
AppId=REDUCE
UsePreviousAppDir=yes
AppPublisher=REDUCE Developers
VersionInfoCopyright=REDUCE Developers
AppPublisherURL=http://reduce-algebra.sourceforge.net/
AppSupportURL=http://reduce-algebra.sourceforge.net/
AppUpdatesURL=http://reduce-algebra.sourceforge.net/
AppVersion=2019-02-09
OutputBaseFilename=Reduce-Setup
DefaultDirName={pf}\Reduce
DefaultGroupName=Reduce
AllowNoIcons=yes
LicenseFile=D:\testing-reduce\winbuild\C\csl\reduce.doc\BINARY-LICENSE.txt
Compression=lzma/ultra
SolidCompression=yes
Uninstallable=yes
UninstallFilesDir={app}\uninst
ShowLanguageDialog=yes
ChangesAssociations=yes
PrivilegesRequired=none
ArchitecturesInstallIn64BitMode=x64


[Languages]
Name: "en"; MessagesFile: "compiler:Default.isl"
Name: "de"; MessagesFile: "compiler:Languages\German.isl"
Name: "fr"; MessagesFile: "compiler:Languages\French.isl"
Name: "it"; MessagesFile: "compiler:Languages\Italian.isl"
Name: "es"; MessagesFile: "compiler:Languages\Spanish.isl"


[Types]
Name: "full"; Description: "{cm:FullInstallation}"
Name: "cslonly"; Description: "{cm:CslOnlyInstallation}"
Name: "pslonly"; Description: "{cm:PslOnlyInstallation}"
Name: "custom"; Description: "{cm:CustomInstallation}"; Flags: iscustom


[Components]
Name: "common"; Description: "{cm:ReduceCommon}"; Types: full cslonly pslonly custom; Flags: fixed
Name: "common\source"; Description: "{cm:ReduceSrc}"; Types: full custom
Name: "csl"; Description: "{cm:ReduceCSL}"; Types: full cslonly custom
Name: "psl32"; Description: "{cm:ReducePSL}"; Types: full pslonly custom; Check: not Is64BitInstallMode
Name: "psl64"; Description: "{cm:ReducePSL}"; Types: full pslonly custom; Check: Is64BitInstallMode


[Files]
; common
Source: "D:\testing-reduce\winbuild\C\csl\reduce.doc\BINARY-LICENSE.txt"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\csl\reduce.doc\BSD-LICENSE.txt"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\csl\reduce.doc\LGPL-2.1.txt"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\misc\primer.tex"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\misc\primer.pdf"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\misc\sl.tex"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\misc\sl.bib"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\misc\sl.pdf"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\redlogo.png"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\*.tex"; DestDir: "{app}\doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\manual.pdf"; DestDir: "{app}\lib\csl\reduce.doc\"; Flags: ignoreversion; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\manual*.html"; DestDir: "{app}\lib\csl\reduce.doc\"; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\manual*.png"; DestDir: "{app}\lib\csl\reduce.doc\"; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\bild*.png"; DestDir: "{app}\lib\csl\reduce.doc\"; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\cmsy10*.png"; DestDir: "{app}\lib\csl\reduce.doc\"; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\gnuplotex*.png"; DestDir: "{app}\lib\csl\reduce.doc\"; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\turtleeg*.png"; DestDir: "{app}\lib\csl\reduce.doc\"; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\manual.css"; DestDir: "{app}\lib\csl\reduce.doc\"; Components: common
Source: "D:\testing-reduce\winbuild\C\doc\manual\manual.html"; DestDir: "{app}\lib\csl\reduce.doc\"; DestName: "index.html"; Components: common
Source: "D:\testing-reduce\winbuild\C\winbuild\gp460-win32-setup.exe"; DestDir: "{app}\lib\"; Components: common

Source: "D:\testing-reduce\winbuild\C\packages\*.*"; Excludes: "regressions\*"; DestDir: "{app}\packages\"; Flags: recursesubdirs; Components: common\source
Source: "D:\testing-reduce\winbuild\C\xmpl\*.tst"; DestDir: "{app}\xmpl\"; Components: common
Source: "D:\testing-reduce\winbuild\C\xmpl\*.rlg"; DestDir: "{app}\xmpl\"; Components: common
Source: "D:\testing-reduce\winbuild\C\xmpl\README"; DestDir: "{app}\xmpl\"; Components: common

; csl
Source: "cslbuild\reduce.exe"; DestDir: "{app}\lib\csl\"; Components: csl;
Source: "cslbuild\winreduce.exe"; DestDir: "{app}\lib\csl\"; Components: csl;
Source: "cslbuild\reduce.img"; DestDir: "{app}\lib\csl\"; Components: csl;
Source: "cslbuild\reduce.fonts\*.*"; DestDir: "{app}\lib\csl\reduce.fonts"; Components: csl;
Source: "cslbuild\reduce.resources\*.*"; DestDir: "{app}\lib\csl\reduce.resources"; Components: csl;
Source: "cslbuild\bootstrapreduce.exe"; DestDir: "{app}\lib\csl\"; Components: csl;
Source: "cslbuild\bootstrapreduce.img"; DestDir: "{app}\lib\csl\"; Components: csl;
Source: "cslbuild\csl.exe"; DestDir: "{app}\lib\csl\"; Components: csl;
Source: "cslbuild\wincsl.exe"; DestDir: "{app}\lib\csl\"; Components: csl;
Source: "cslbuild\csl.img"; DestDir: "{app}\lib\csl\"; Components: csl;
Source: "D:\testing-reduce\winbuild\redcsl.bat"; DestDir: "{app}\bin\"; Components: csl;
Source: "D:\testing-reduce\winbuild\redcsl.sh"; DestDir: "{app}\bin\"; DestName: "redcsl"; Components: csl;
Source: "D:\testing-reduce\winbuild\bootstrapreduce.bat"; DestDir: "{app}\bin\"; Components: csl;
Source: "D:\testing-reduce\winbuild\bootstrapreduce.sh"; DestDir: "{app}\bin\"; DestName: "redcsl"; Components: csl;
Source: "D:\testing-reduce\winbuild\csl.bat"; DestDir: "{app}\bin\"; Components: csl;
Source: "D:\testing-reduce\winbuild\csl.sh"; DestDir: "{app}\bin\"; DestName: "redcsl"; Components: csl;
Source: "D:\testing-reduce\winbuild\cslcyg32\redfront\rfcsl.exe"; DestDir: "{app}\bin\"; Components: csl;
Source: "D:\testing-reduce\winbuild\cslcyg64\redfront\rfcsl.exe"; DestDir: "{app}\bin\"; DestName: "rfcslcyg64.exe"; Components: csl;
Source: "D:\testing-reduce\winbuild\cslcyg32\redfront\rfcslwin.exe"; DestDir: "{app}\bin\"; DestName: "rfcsl.com"; Components: csl;

Source: "cslbuild\make-cygwin-symlink.exe"; DestDir: "{app}\lib\csl\"; Components: csl;
Source: "cslbuild\make-cygwin-symlink.exe"; DestDir: "{app}\lib\psl\"; Components: psl32 psl64;



;psl
Source: "D:\testing-reduce\winbuild\C\pslbuild\i686-pc-windows\psl\*"; DestDir: "{app}\lib\psl\psl\"; Components: psl32
Source: "D:\testing-reduce\winbuild\C\pslbuild\i686-pc-windows\red\*.b"; DestDir: "{app}\lib\psl\red\"; Components: psl32
Source: "D:\testing-reduce\winbuild\C\pslbuild\i686-pc-windows\red\*.lap"; DestDir: "{app}\lib\psl\red\"; Components: psl32; Flags: skipifsourcedoesntexist
Source: "D:\testing-reduce\winbuild\redpsl.sh"; DestDir: "{app}\bin\"; DestName: "redpsl"; Components: psl32;
Source: "D:\testing-reduce\winbuild\cslcyg32\redfront\rfpsl.exe"; DestDir: "{app}\bin\"; Components: psl32 psl64;
Source: "D:\testing-reduce\winbuild\cslcyg32\redfront\rfpslwin.exe"; DestDir: "{app}\bin\"; DestName: "rfpsl.com"; Components: psl32 psl64;

Source: "D:\testing-reduce\winbuild\C\pslbuild\x86_64-pc-windows\psl\*"; DestDir: "{app}\lib\psl\psl\"; Components: psl64
Source: "D:\testing-reduce\winbuild\C\pslbuild\x86_64-pc-windows\red\*.b"; DestDir: "{app}\lib\psl\red\"; Components: psl64
Source: "D:\testing-reduce\winbuild\C\pslbuild\x86_64-pc-windows\red\*.lap"; DestDir: "{app}\lib\psl\red\"; Components: psl64

Source: "D:\testing-reduce\winbuild\reduce64.img"; DestDir: "{app}\lib\psl\red\"; DestName: "reduce.img"; Components: psl64
Source: "D:\testing-reduce\winbuild\reduce.img"; DestDir: "{app}\lib\psl\red\"; DestName: "reduce.img"; Components: psl32
Source: "D:\testing-reduce\winbuild\redpsl.bat"; DestDir: "{app}\bin\"; Components: psl32 psl64; Check: not Is64BitInstallMode
;;;Source: "D:\testing-reduce\winbuild\redpslw.bat"; DestDir: "{app}\bin\"; Components: psl32
Source: "D:\testing-reduce\winbuild\redpsl64.bat"; DestName: "redpsl.bat"; DestDir: "{app}\bin\"; Components: psl64
;;;Source: "D:\testing-reduce\winbuild\redpsl64w.bat"; DestName: "redpslw.bat"; DestDir: "{app}\bin\"; Components: psl64
Source: "D:\testing-reduce\winbuild\redpsl64.sh"; DestDir: "{app}\bin\"; DestName: "redpsl"; Components: psl64;
Source: "D:\testing-reduce\winbuild\cslcyg64\redfront\rfpsl.exe"; DestDir: "{app}\bin\"; Destname: "rfpslcyg64.exe"; Components: psl32 psl64;

Source: "cslbuild\make-cygwin-symlink.exe"; DestDir: "{app}\lib\psl\"; Components: psl32 psl64;


[Icons]
;Name: "{group}\redcsl"; Filename: "{app}\bin\redcsl.bat"; IconFileName: "{app}\bin\redcsl.bat"; Components: csl
Name: "{group}\CSL Reduce"; Filename: "{app}\lib\csl\winreduce.exe"; Components: csl
Name: "{group}\CSL Bootstrap Reduce"; Filename: "{app}\lib\csl\bootstrapreduce.exe"; Components: csl
Name: "{group}\CSL Lisp system"; Filename: "{app}\lib\csl\wincsl.exe"; Components: csl
Name: "{group}\PSL Reduce"; Filename: "{app}\bin\redpsl.bat"; IconFileName: "{app}\lib\psl\psl\bpslw.exe"; Components: psl32 psl64


[Run]
Filename: "{app}\lib\gp460-win32-setup.exe"; Description: "Install Gnuplot"; Flags: postinstall; Check: MyGnuPlotCheck
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\lib\csl\reduce.exe"" redcsl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\lib\csl\bootstrapreduce.exe"" bootstrapreduce"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\lib\csl\csl.exe"" csl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\bin\rfcsl.exe"" ""{app}\bin\rfcslcyg64.exe"" rfcsl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\psl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\bin\redpsl"" redpsl"; Flags: runhidden; Components: psl32 psl64
Filename: "{app}\lib\psl\make-cygwin-symlink.exe"; Description: "set symlinks for benefit of cygwin users"; Parameters: """{app}\bin\rfpsl.exe"" ""{app}\bin\rfpslcyg64.exe"" rfpsl"; Flags: runhidden; Components: psl32 psl64


[UninstallRun]
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Parameters: "redcsl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Parameters: "bootstrapreduce"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Parameters: "csl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\csl\make-cygwin-symlink.exe"; Parameters: "rfcsl"; Flags: runhidden; Components: csl
Filename: "{app}\lib\psl\make-cygwin-symlink.exe"; Parameters: "redpsl"; Flags: runhidden; Components: psl32 psl64
Filename: "{app}\lib\psl\make-cygwin-symlink.exe"; Parameters: "rfpsl"; Flags: runhidden; Components: psl32 psl64


[Code]
var
  NeedGnuPlotInstall: Boolean;
  GnuPlotPath: String;

function InitializeSetup(): Boolean;
var
  RegVal: String;
begin
  Log('InitializeSetup called');
  if not RegQueryStringValue(HKEY_CLASSES_ROOT, 'gnuplot\shell\open\command', '', RegVal) then begin
    NeedGnuPlotInstall := True;
    Log('No Gnuplot Installed');
  end else begin
    NeedGnuPlotInstall := False;
    GnuPlotPath := RegVal;
    Delete(GnuPlotPath, Pos(' -p ', RegVal), Length(RegVal));
    Log('Gnuplot found at '+GnuPlotPath);
  end;
  Result := True;
end;


function MyGnuPlotCheck(): Boolean;
begin
  Result := NeedGnuPlotInstall;
end;



[CustomMessages]


;=== English === LID=$0409 CodePage=0

FullInstallation=Full Installation
CslOnlyInstallation=Install CSL only
PslOnlyInstallation=Install PSL Only
CustomInstallation=Custom Installation

ReduceCommon=Files common to CSL and PSL
ReduceSrc=Reduce Source Code
ReduceCSL=Files for CSL
ReducePSL=Files for PSL



;=== German === LID=$0407 CodePage=1252

de.FullInstallation=Vollst�ndige Installation
de.CslOnlyInstallation=Nur CSL installieren
de.PslOnlyInstallation=Nur PSL installieren
de.CustomInstallation=Benutzerdefinierte Installation

de.ReduceCommon=Gemeinsame Dateien
de.ReduceSrc=Reduce-Quellen
de.ReduceCSL=CSL-Dateien
de.ReducePSL=PSL-Dateien


;=== French === LID=$040C CodePage=1252

fr.FullInstallation=Installation compl�te
fr.CslOnlyInstallation=Installez CSL seulement
fr.PslOnlyInstallation=Installez PSL seulement
fr.CustomInstallation=Installation personnalis�e

fr.ReduceCommon=Fichiers communs � CSL et PSL
fr.ReduceSrc=Fichiers de code source
fr.ReduceCSL=Fichiers pour CSL
fr.ReducePSL=Fichiers pour PSL


; === Italian ===

it.FullInstallation=Installazione completa
it.CslOnlyInstallation=Installare solo CSL
it.PSLOnlyInstallation=Installare solo PSL
it.CustomInstallation=Installazione personalizzata

it.ReduceCommon=File comuni a CSL e PSL
it.ReduceSrc=File de origine
it.ReduceCSL=File per CSL
it.ReducePSL=File per PSL


es.FullInstallation=Instalaci�n completa
es.CslOnlyInstallation=Instalar s�lo CSL
es.PSLOnlyInstallation=Instalar s�lo PSL
es.CustomInstallation=Instalaci�n personalizada

es.ReduceCommon=Archivos comunes de CSL y PSL
es.ReduceSrc=Archivos de origen
es.ReduceCSL=Archivos para CSL
es.ReducePSL=Archivos para PSL

