#include <windows.h>
#include <stdio.h>
#include <richedit.h>
#include "commctrl.h"

#include "defines.h"
#include "globals.h"
#include "functions.cpp"
#include "on_create_msg.cpp"
#include "cmd_msg.cpp"
#include "paint_msg.cpp"




#pragma comment(lib,"comctl32.lib")

//----------------------------------------------------------------

//----------------------------------------------------------------

long __stdcall vaxo(HWND hwnd,unsigned int message, unsigned int wparam,long lparam)
{
	HWND editaa=GetDlgItem(hwnd,70000);
	switch(message)
	{ 

	case WM_LBUTTONDOWN:
		/*
	SetWindowLong(editaa,GWL_ID,0);
	SetWindowLong(editaa,GWL_HINSTANCE,0);
	SetWindowLong(editaa,GWL_EXSTYLE,0); 
	SetWindowLong(editaa,GWL_HWNDPARENT,0); 
 	SetWindowLong(editaa,GWL_STYLE,WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_BORDER|ES_MULTILINE|ES_CENTER|WS_VSCROLL);	
	
		*/	
		break;
	
	case WM_SIZE:
	     	LPRECT lpr;
	     	GetWindowRect(hwnd,lpr);
	         RECT r;
			GetClientRect(hwnd,&r);
			//MoveWindow(editaa,10,20,r.right-20,r.bottom-25,1);

	   break;
	
		case WM_CREATE:
		
		create_menu(hwnd);
	  	on_create(hwnd,message,wparam,lparam);
		break;
		
		case WM_COMMAND:
		on_cmd(hwnd,message,wparam,lparam);

		break;
		
		case WM_PAINT:
		//on_paint(hwnd,message,wparam,lparam);
		break;

		case WM_KEYDOWN:
	//	on_kbd(hwnd,message,wparam,lparam);
		
		break;

		case WM_CTLCOLOREDIT:
		{
		 HDC hdcStatic = (HDC) wparam;
		 SetTextColor(hdcStatic, edittextferi);
		 SetBkColor(hdcStatic,textlineferi);
	     return (INT_PTR)CreateSolidBrush(bckferi);
			/*
		HWND ctrl=(HWND)lparam;
		HDC hdc=(HDC)wparam;
		HBRUSH brush = CreateSolidBrush(col);
		SetBkMode(hdc,1);
		SetTextColor(hdc,(COLORREF)brush);
		return (long)brush;
		*/
		}
		break;

		case WM_DESTROY:
		exit(1);
		//PostQuitMessage(0);
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
wc.lpfnWndProc=(WNDPROC)&vaxo;
wc.lpszClassName="12";
wc.hbrBackground=(HBRUSH)CreateSolidBrush(RGB(255,255,255));
wc.hIcon=(HICON)LoadImage(0,"c:\\1.ico",IMAGE_ICON,16,16,LR_LOADFROMFILE);

	if(RegisterClass(&wc)==0)
	{
	MessageBox(hwnd,"RegisterClass error",0,0);
	return 0;
	}


//mtavari fanjara:
style=WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
X=10;Y=30;W=750;H=500;
hwnd=CreateWindow(wc.lpszClassName,"Main",style,X,Y,W,H,0,0,0,0);

	
MSG msg;
	while(GetMessage(&msg,0,0,0))
	{
	TranslateMessage(&msg);
	DispatchMessage(&msg);
	}
}