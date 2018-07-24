


long __stdcall on_create(HWND hwnd,unsigned int message	, unsigned int wparam,long lparam,int z)
{		
	static int but;
	
	if(z>0) but=z;
	


	int widthButton1=90;
	
	

	bckferi=RGB(40,40,40);
	textlineferi=RGB(40,40,40);
	edittextferi=RGB(210,74,196);


RECT r;
GetClientRect(hwnd,&r);

HWND hw;
HWND Hbutton;

	Hbutton=CreateWindow("button"," ",WS_CLIPCHILDREN|WS_VISIBLE|WS_CHILD|WS_BORDER,but,3,widthButton1,25,hwnd,(HMENU)butc,0,0);
butc++;

childButton=CreateWindow("button","X",WS_VISIBLE|WS_CHILD|WS_BORDER,but+widthButton1,3,15,15,hwnd,(HMENU)cbutc,0,0);



//olde=(WNDPROC)SetWindowLong(childButton,GWL_WNDPROC	,(long)buttonNewPro);


 //olde=(WNDPROC)SetWindowLong(childButton,GWL_WNDPROC,(long)buttonNewPro);

//  olde=(WNDPROC)SetWindowLong(hwnd,GWL_WNDPROC,(long)buttonNewPro);

cbutc++;
but=but+widthButton1+20;





int X,Y,W,H;
X=10,Y=40,W=700,H=500;

hw=CreateWindow("edit","123456789111213",editstyle,10,30,r.right-10,r.bottom-30.5,hwnd,(HMENU)editc,0,0);
editc++;

////////////////// region //////

RECT rb;
	HDC hdc=GetDC(Hbutton);
	GetClientRect(Hbutton,&rb);

	HRGN hrgn;





////////////////////////////////////////

/////////// create font ////////////////
/// richedit 
	/*
HFONT hfont=create_font(hwnd);
SendMessage(hw,WM_SETFONT,(UINT)hfont,1);

///SendMessage(hw,EM_SETSEL,4,12);

CHARFORMAT cf={0};
//memset
int sss2=SendMessage(hw,EM_GETCHARFORMAT,0,(LPARAM)&cf);

//cf.cbSize=sizeof (cf);
cf.dwMask=CFM_COLOR;
cf.crTextColor=RGB(255,0,25);
int sss=SendMessage(hw,EM_SETCHARFORMAT,SCF_SELECTION,(LPARAM) &cf);
UINT err=GetLastError();

///richedit class or rich edit32

*/

return 0;
}