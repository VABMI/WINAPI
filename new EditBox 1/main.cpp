                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                #include <windows.h>
#include "head.h"
#include "globals.h"

#include "defines.h"
#include "ReadAndWrite.cpp"
#include "functions.cpp"
#include "on_create_msg.cpp"
#include "cmd_msg.cpp"

#include "paint_msg.cpp"




#pragma comment(lib,"comctl32.lib")

//----------------------------------------------------------------
HCURSOR hCursor;


	 bool delet12=1;
	 char *sechwat="fff";
	 static char*sechwatPev=sechwat;
//----------------------------------------------------------------
const UINT findmsg=RegisterWindowMessage(FINDMSGSTRING);  //// finde funqciis messagi
long __stdcall vaxo(HWND hwnd,unsigned int message, unsigned int wparam,long lparam)
{
	HWND editaa=GetDlgItem(hwnd,editc);
	 StatusBar= GetDlgItem(hwnd,idStatusBar);

//	HWND tolbar=GetDlgItem(hwnd,70000);

	RECT r;
	LPFINDREPLACE lpfr =(LPFINDREPLACE) lparam;

if(message==findmsg)
{
	
		
		static	char bufs2[100];
		    char bufs[100];
			
////////////////////////// finde Text funqciis struqturidan wchar_t to lpcstr /////////////////////////////////////
			////////////////////////////////// tu sheyvanilia igive striqonii magis logikaa /////////////////////////
			if(vb)
			{
				for(int i=0;i<6;i++)
				{
			
				bufs[i]=szFindWhat[i];
			
				}
				vb=0;
					sechwat=bufs;
					sechwatPev=sechwat;
			}
			else 
		{	
			for(int i=0;i<6;i++)
				{
			
				bufs[i]=szFindWhat[i];
			
				}sechwat=bufs;

			}		
	////////////////////////////////////////////////////////////
	
	/////////////////////////// dziebaaaaaaaaa masivshi ////////////////////////////////////////////

	static char  bufg[10000]; //////////////// enacvlebian ertmanets mashi rodesac sxvadasxva sadziebo sityva shedis fanjris gautishvelad 
	static char bufg1[10000]; // anu tu chavwer raime sadziebo sityvas da mere sxva sadziebo sityvas 
    UINT ff;
	  

		if(lpfr->Flags&FR_FINDNEXT)
		{
	
			if(delet12)
				 {
					  SendMessage(EDITGLOBAL,WM_GETTEXT,999,(LPARAM)bufg);
					  sprintf(bufg1,"%s",bufg);
					  delet12=0;
				 }
			static bool nm=0;
			static bool nm2=0;
			////////////////////////////////////////////////// if IIIIIIIIIIIII
			//if(strlen1==strlen){
			for(int i=0;i<strlen(bufs);i++)
			{
				if(bufs[i]!=bufs2[i])
				{
					nm2=0;

				}
				else nm2=1;


			}
			

			if(sechwat==sechwatPev&&nm==0)
			{
		 
	
				const char *position1=strstr(bufg,sechwat);
				
				ff=(position1-bufg);

		/////////////////////// monishvna //////////////////

				SendMessage(EDITGLOBAL,EM_SETSEL,ff,ff+strlen(sechwat));
		
				if(position1)
				{
					 for(int i=ff;i<ff+strlen(sechwat);i++)
					{

						bufg[i]=(char)(-52);

					}

				}

				else 
				{

					
					sprintf(bufg,"%s",bufg1);

				}


			}
			else if(nm==0){
				nm=1;

				sechwatPev=sechwat;
				sprintf(bufg,"%s",bufg1);
			}

			//////////////////////////////// if II_II_II_II_II_
			else if(sechwatPev==sechwat&&nm)
			{

				
				const char *position2=strstr(bufg1,sechwat);
		
		
				ff=(position2-bufg1);

	



		/////////////////////// monishvna //////////////////

				SendMessage(EDITGLOBAL,EM_SETSEL,ff,ff+strlen(sechwat));
		
					if(position2)
				{
						 for(int i=ff;i<ff+strlen(sechwat);i++)
						{

							bufg1[i]=(char)(-52);

						}
				}

			} 
			else if(nm) {
				nm=0;

				sechwatPev=sechwat;
			
				sprintf(bufg1,"%s",bufg);
			}


		}
		else delet12=1;






}
	












	switch(message)
	{ 
	
		case WM_LBUTTONDOWN:

		
		break;

		case WM_CREATE:
		
		create_menu(hwnd);
		tolbar=	Toolar(hwnd);
		DoCreateStatusBar(hwnd,6,0,5);
	  	on_create(hwnd,message,wparam,lparam,10);


		break;
	
		
		case WM_COMMAND:
			on_cmd(hwnd,message,wparam,lparam);

		break;
		case WM_PAINT:
		//on_paint(hwnd,message,wparam,lparam);
		break;

		case WM_KEYDOWN:
		switch(wparam)
		{

		case VK_RETURN:

			MessageBox(hwnd,"adasdas","asdas",0);

			break;


		}
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
		case WM_SIZE:
				GetClientRect(hwnd,&r);
	     		MoveWindow(editaa,2,31,r.right-4,r.bottom-55,1);
				//// toll bari Status bari ///////////////
			 SendMessage(tolbar, TB_AUTOSIZE, 0, 0);/////
		//	 SendMessage(StatusBar, TB_AUTOSIZE, 0, 0); //////
			
			//  SendMessage(StatusBar, WM_SIZE, 0, 0); 
				DoCreateStatusBar(hwnd,6,0,5);

			 static char statusc[5];
			  sprintf(statusc,"BOTTOM /=/%i",r.bottom);
			  SendMessage(StatusBar, SB_SETTEXT, 3,(LPARAM)statusc);
			  ZeroMemory(&statusc,strlen(statusc));
			  
			  sprintf(statusc,"RIGHT /=/%i",r.right);
			  SendMessage(StatusBar, SB_SETTEXT, 4,(LPARAM)statusc);

			   SendMessage(StatusBar, SB_SETTEXT, 1,(LPARAM)path);

			//  SendMessage(StatusBar, SB_SETBKCOLOR , (WPARAM) 1, (LPARAM)RGB(0,128,0));
			  
			//  SendMessage(StatusBar, SB_SETPARTS , (WPARAM) 5, (LPARAM)r.right-30);
 //////////////////////////////////////////////////////////////////////////////////////////////

			// DoCreateStatusBar(hwnd,6,0,5);
		break;

		case WM_DESTROY:
		exit(1);
		break;
	}
		SendMessage(StatusBar,SB_SETTEXT,0,(LPARAM)"Ready");
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
wc.hbrBackground=(HBRUSH)CreateSolidBrush(RGB(25,255,55));
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