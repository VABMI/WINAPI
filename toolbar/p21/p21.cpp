#include <windows.h>
#include <stdio.h>
#include <commctrl.h>
HFONT hfont_global;

#pragma comment(lib,"comctl32.lib")
void  CreateAToolBar1(HWND hwndParent) 
{ 
	HINSTANCE g_hinst;
#define NUM_BUTTONS 5
#define IDM_PASTE	100
#define	BMP_PASTE	200

#define IDM_COPY	300
#define BMP_COPY	400
#define IDM_CUT		500

#define BMP_CUT		600
#define IDS_PASTE	700
#define IDS_COPY	800
#define IDB_BUTTONS	900
#define	IDS_CUT		910
#define NUM_BUTTON_BITMAPS 920
#define MAX_LEN		1000
#define ID_TOOLBAR  1

    HWND hwndTB; 
    TBADDBITMAP tbab; 
    TBBUTTON tbb[3]; 

    char szBuf[16]; 
    int iCut, iCopy, iPaste; 
 
    // Ensure that the common control DLL is loaded. 
    InitCommonControls(); 
    hwndTB = CreateWindowEx(0, TOOLBARCLASSNAME,  NULL,  WS_CHILD | TBSTYLE_TOOLTIPS | CCS_ADJUSTABLE,  0, 0, 0, 0, hwndParent, (HMENU) ID_TOOLBAR,0, NULL); 
 


    SendMessage(hwndTB, TB_BUTTONSTRUCTSIZE, (WPARAM) sizeof(TBBUTTON), 0); 


	
 
    tbab.hInst = 0; 
    tbab.nID   = IDB_BUTTONS; 
    SendMessage(hwndTB, TB_ADDBITMAP, (WPARAM) NUM_BUTTON_BITMAPS, 
        (WPARAM) &tbab); 
 
    // Add the button strings to the toolbar. 
    LoadString(0, IDS_CUT, (LPSTR) &szBuf, MAX_LEN); 
    iCut = SendMessage(hwndTB, TB_ADDSTRING, 0, (LPARAM) (LPSTR) szBuf); 
 
    LoadString(0, IDS_COPY, (LPSTR) &szBuf, MAX_LEN); 
    iCopy = SendMessage(hwndTB, TB_ADDSTRING, (WPARAM) 0, 
        (LPARAM) (LPSTR) szBuf); 

 
    LoadString(0, IDS_PASTE, (LPSTR) &szBuf, MAX_LEN); 
    iPaste = SendMessage(hwndTB, TB_ADDSTRING, (WPARAM) 0, 
        (LPARAM) (LPSTR) szBuf); 

    tbb[0].iBitmap = 0; 
    tbb[0].idCommand = IDM_CUT; 
    tbb[0].fsState = TBSTATE_ENABLED; 
    tbb[0].fsStyle = TBSTYLE_BUTTON; 
    tbb[0].dwData = 0; 
    tbb[0].iString = iCut; 
 
    tbb[1].iBitmap = 0; 

    tbb[1].idCommand = IDM_COPY; 
    tbb[1].fsState = TBSTATE_ENABLED; 
    tbb[1].fsStyle = TBSTYLE_BUTTON; 
    tbb[1].dwData = 0; 
    tbb[1].iString = iCopy; 
 
    tbb[2].iBitmap = 0; 
    tbb[2].idCommand = IDM_PASTE; 
    tbb[2].fsState = TBSTATE_ENABLED; 
    tbb[2].fsStyle = TBSTYLE_BUTTON; 
    tbb[2].dwData = 0; 
    tbb[2].iString = iPaste; 
 
    SendMessage(hwndTB, TB_ADDBUTTONS, (WPARAM) NUM_BUTTONS, (LPARAM)&tbb); 

 	
    ShowWindow(hwndTB, SW_SHOW); 

   // return hwndTB; 
} 
 
	





//----------------------------------------------------------------
/*
void  CreateAToolBar(HWND parent) 
{ 
	HINSTANCE hInst;WNDPROC prc; int *toolWidthPtr;


	 DWORD dwStyle;  

    HWND hwndTB; 
    TBADDBITMAP tbab; 
  TBBUTTON tbButton[8];
    char szBuf[16]; 
    int iCut, iCopy, iPaste; 
     INITCOMMONCONTROLSEX iccex;
	 wchar_t *txt = L"wii";
	 
	 for(int i = 0; i < 8; i += 2)
{
    tbButton[i].iBitmap = 0;
    tbButton[i].fsStyle = BTNS_BUTTON;
    tbButton[i].fsState = TBSTATE_ENABLED;
    tbButton[i].iString = (INT_PTR)txt;
    tbButton->idCommand = 0;

}
	 iccex.dwSize = sizeof (INITCOMMONCONTROLSEX);
    iccex.dwICC = ICC_BAR_CLASSES;
//	  InitCommonControlsEx (&iccex);


	  dwStyle = WS_VISIBLE | WS_CHILD | TBSTYLE_TOOLTIPS | TBSTYLE_WRAPABLE |   TBSTYLE_TRANSPARENT | CCS_VERT ;

	  if (!(hwndTB = CreateToolbarEx (
        parent,               // Parent window handle
        dwStyle,            // Toolbar window styles
        (UINT) 666,  // Toolbar control identifier
        8,          // Number of button images
        hInst,              // Module instance 
        (UINT)LoadImage(hInst,MAKEINTRESOURCE("C:\\Users\\vaxoa\\OneDrive\\Documents\\GitHub\\WINAPI\\toolbar\\toolbar\\toolbar.ico"),0,0,0,LR_VGACOLOR),        // Bitmap resource identifier
        tbButton,           // Array of TBBUTTON structure 
        // contains button data
        sizeof(tbButton) / sizeof(TBBUTTON),
        // Number of buttons in toolbar
        40,        // Width of the button in pixels
        40,       // Height of the button in pixels
        40,         // Button image width in pixels
        40,        // Button image height in pixels
        sizeof (TBBUTTON))))// Size of a TBBUTTON structure
    {
       // return 0;
    }

	  


    hwndTB = CreateWindowEx(0, TOOLBARCLASSNAME,  NULL,WS_CHILD | TBSTYLE_TOOLTIPS | CCS_ADJUSTABLE,10, 0, 0, 0, parent, (HMENU) 1, 0, NULL); 
 
    SendMessage(hwndTB, TB_BUTTONSTRUCTSIZE, 
        (WPARAM) sizeof(TBBUTTON), 0); 
		

	// SendMessage (hwndTB, TB_SETTOOLTIPS, (WPARAM) 8, (LPARAM) 8);
 
    
    ShowWindow(hwndTB, SW_SHOW); 
   // return hwndTB; 
} 
 */
//----------------------------------------------------------------
long __stdcall window_main_function_chvenia(HWND hwnd,unsigned int message
					, unsigned int wparam,long lparam)
{
	switch(message)
	{
		case WM_CREATE:
	CreateAToolBar1(hwnd);
		break;
		
		case WM_COMMAND:
	//	on_cmd(hwnd,message,wparam,lparam);
		break;
		
		case WM_RBUTTONDOWN:
		case WM_LBUTTONDOWN:
		case WM_MOUSEMOVE:
		case WM_RBUTTONDBLCLK:
		case WM_LBUTTONDBLCLK:
	
		break;

		case WM_PAINT:
	
		break;

		case WM_KEYDOWN:

		break;
	}
return DefWindowProc(hwnd,message,wparam,lparam);
}
//----------------------------------------------------------------
int __stdcall WinMain(HINSTANCE,HINSTANCE,char *,int)
//void main()
{
HWND hwnd=0;
int X,Y,W,H;
ULONG style=0;

WNDCLASS wc;
ZeroMemory(&wc,sizeof(WNDCLASS));

wc.style=CS_DBLCLKS;
wc.lpfnWndProc=(WNDPROC)&window_main_function_chvenia;
wc.lpszClassName="12";
wc.hbrBackground=(HBRUSH)CreateSolidBrush(RGB(200,200,200));
wc.hIcon=(HICON)LoadImage(0,"c:\\1.ico",IMAGE_ICON,16,16,LR_LOADFROMFILE);

	if(RegisterClass(&wc)==0)
	{
	MessageBox(hwnd,"RegisterClass error",0,0);
//	return;
	}


//mtavari fanjara:
style=WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
X=10;Y=30;W=700;H=500;
hwnd=CreateWindow(wc.lpszClassName,"Main",style,X,Y,W,H,0,0,0,0);

	
MSG msg;
int s=1;
	while(s!=0)
	{
	s=GetMessage(&msg,0,0,0);
	TranslateMessage(&msg);
	DispatchMessage(&msg);	
	}
	//	return 0;
}