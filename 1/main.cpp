#include <windows.h>
#include <stdio.h>
#include <richedit.h>
#include "commctrl.h"
	//	long __stdcall buttonNewPro(HWND hwnd,unsigned int message, unsigned int wparam,long lparam);
//WNDPROC olde;
	//	long  (__stdcall *olde)    (HWND,unsigned int, unsigned int,long);


#include "defines.h"
#include "globals.h"
#include "functions.cpp"
#include "on_create_msg.cpp"
#include "cmd_msg.cpp"
#include "paint_msg.cpp"




#pragma comment(lib,"comctl32.lib")

//----------------------------------------------------------------
HCURSOR hCursor;
//----------------------------------------------------------------

long __stdcall vaxo(HWND hwnd,unsigned int message, unsigned int wparam,long lparam)
{
	HWND editaa=GetDlgItem(hwnd,70000);

	

	if(message==WM_SIZE){

	         RECT r;
			 for(int t=70000;t<=editc;t++){
				 	HWND editrect=GetDlgItem(hwnd,t);
		        	GetClientRect(hwnd,&r);

			MoveWindow(editrect,10,30,r.right-10,r.bottom-30.5,1);
			 }



	}
	
	switch(message)
	{ 
	
		case WM_LBUTTONDOWN:
		/*
		SetWindowLong(editaa,GWL_ID,0);
		SetWindowLong(editaa,GWL_HINSTANCE,0);
		SetWindowLong(editaa,GWL_EXSTYLE,0); 
		SetWindowLong(editaa,GWL_HWNDPARENT,1); 
 		SetWindowLong(editaa,GWL_STYLE,WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_BORDER|ES_MULTILINE|ES_CENTER|WS_VSCROLL);	
		*/
		
		break;

		case WM_CREATE:
		
		create_menu(hwnd);

	  	on_create(hwnd,message,wparam,lparam,10);

		//////////////////// kursoris chasma mtavar fanjatraze ////////////////
		hCursor = LoadCursorFromFile("C:\\Users\\vaxoa\\OneDrive\\Documents\\GitHub\\WINAPI\\icon\\cur197.ani");
		SetCursor(hCursor);
		SetClassLong(hwnd, -12, (DWORD)hCursor);
		///////////////////////////////////////////////////////

		break;
	
		
		case WM_COMMAND:
			
/////////////// EDITSHI CURSORIS SHECVLA ////////// 
			if(HIWORD(wparam)==EN_SETFOCUS)
			{
			//	MessageBox(hwnd,"asdasd","asdasd",1);
			hCursor = LoadCursorFromFile("C:\\Users\\vaxoa\\OneDrive\\Desktop\\cur1091.ani");
		       SetCursor(hCursor);
		       SetClassLong(editaa, -12, (DWORD)hCursor);
			}
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
		
		}
		break;

		case WM_DESTROY:
		exit(1);
		break;
	}

return DefWindowProc(hwnd,message,wparam,lparam);
}
//----------------------------------------------------------------

int __stdcall WinMain(HINSTANCE,HINSTANCE,char *,int)
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
wc.hCursor=LoadCursor(NULL,IDC_WAIT);
	if(RegisterClass(&wc)==0)
	{
	MessageBox(hwnd,"RegisterClass error",0,0);
	return 0;
	}


//mtavari fanjara:
style=WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
X=10;Y=30;W=750;H=500;
hwnd=CreateWindow(wc.lpszClassName,"Main",style,X,Y,W,H,0,0,0,0);


/////--------------------------///////
	
MSG msg;
	while(GetMessage(&msg,0,0,0))
	{/*
		if(msg.message==WM_COMMAND)
		{

			if(msg.wParam==30001)
			{

				MessageBox(msg.hwnd,"asdasd","Asdasd",0);
			}

		}
		*/
	TranslateMessage(&msg);
	DispatchMessage(&msg);
	}
}




/*
long __stdcall buttonNewPro(HWND hwnd,unsigned int message, unsigned int wparam,long lparam)
{
		SendMessage(hwnd,message,wparam,lparam);
return DefWindowProc(hwnd,message,wparam,lparam);
}
*/
//-------------