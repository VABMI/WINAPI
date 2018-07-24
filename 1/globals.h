DWORD editstyle=WS_VISIBLE|WS_CHILD|WS_BORDER|ES_MULTILINE|ES_NOHIDESEL|WS_OVERLAPPED|WS_VSCROLL;
static int butc=50001;
static bool bn=false;
static int cbutc=30001;
static int editc=70001;

HWND EDITGLOBAL,childButton;

ULONG edittextferi;
ULONG textlineferi;
ULONG bckferi;

HFONT hfont_glob;
CHOOSEFONT cf_glob;
LOGFONT lf_glob;
ULONG rgb_glob=0;


