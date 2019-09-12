; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=CheckerBoard64
AppVerName=CheckerBoard64 version 1.75d
AppPublisher=Martin Fierz
DefaultDirName={pf32}\CheckerBoard
UsePreviousAppDir=no
AppendDefaultDirName=no
ArchitecturesInstallIn64BitMode=x64
ArchitecturesAllowed=x64
DefaultGroupName=CheckerBoard
DisableProgramGroupPage=no
SourceDir=.
OutputDir=Output
OutputBaseFilename=CheckerBoardSetup64.175d
Compression=lzma/ultra
SolidCompression=yes
Uninstallable=yes
DirExistsWarning=no

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
Source: "Executables\checkerboard64.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Executables\cake_186.dll"; DestDir: "{app}\engines"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "Executables\book.bin"; DestDir: "{app}\engines"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\help.htm"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\helpspanish.htm"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\nutshell.htm"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\toolbar.bmp"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\bmp\*"; DestDir: "{app}\bmp"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\db\db2.cpr"; DestDir: "{app}\db"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\db\db2.idx"; DestDir: "{app}\db"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\db\db3.cpr"; DestDir: "{app}\db"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\db\db3.idx"; DestDir: "{app}\db"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\db\db4.cpr"; DestDir: "{app}\db"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\db\db4.idx"; DestDir: "{app}\db"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\nutshellgif\*"; DestDir: "{app}\nutshellgif"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\source\cb_interface.h"; DestDir: "{app}\source"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\source\dama.c"; DestDir: "{app}\source"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\source\dama.def"; DestDir: "{app}\source"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\source\damahelp.htm"; DestDir: "{app}\source"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\source\enginedefs.h"; DestDir: "{app}\source"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\source\simplech.c"; DestDir: "{app}\source"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\source\simplech.def"; DestDir: "{app}\source"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\source\simplechhelp.htm"; DestDir: "{app}\source"; Flags: ignoreversion recursesubdirs createallsubdirs

[Dirs]
Name: "{app}\engines"

[Tasks]
Name: startmenu; Description: Create a start menu entry
Name: desktopicon; Description: Create a desktop shortcut

[Icons]
Name: "{commonprograms}\CheckerBoard\CheckerBoard64"; Filename: "{app}\CheckerBoard64.exe"; WorkingDir: "{app}"; Tasks: startmenu
Name: "{commondesktop}\CheckerBoard64"; Filename: "{app}\CheckerBoard64.exe"; WorkingDir: "{app}"; Tasks: desktopicon
