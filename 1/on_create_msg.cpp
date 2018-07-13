


long __stdcall on_create(HWND hwnd,unsigned int message	, unsigned int wparam,long lparam)
{
	static int but=10;
	int widthButton1=90;
	
	

	bckferi=RGB(40,40,40);
	textlineferi=RGB(40,40,40);
	edittextferi=RGB(150,74,96);


RECT r;
GetClientRect(hwnd,&r);

HWND hw=0;
HWND Hbutton,childButton;

Hbutton=CreateWindow("button"," ",WS_CLIPCHILDREN|WS_VISIBLE|WS_CHILD|WS_BORDER,but,3,widthButton1,25,hwnd,(HMENU)butc,0,0);

childButton=CreateWindow("button","X",WS_VISIBLE|WS_CHILD|WS_BORDER,but+90,3,15,25,hwnd,(HMENU)cbutc,0,0);
int X,Y,W,H;
but=but+widthButton1+25;
butc++;
cbutc++;


X=10,Y=30,W=700,H=500;

hw=CreateWindow("edit","123456789111213",editstyle,X,Y,r.right-20,r.bottom,hwnd,(HMENU)editc,0,0);
editc++;
////////////////// region //////

RECT rb;
	HDC hdc=GetDC(Hbutton);
	GetClientRect(Hbutton,&rb);

	HRGN hrgn;// = CreateRectRgnIndirect(&r);
	//HBRUSH hbrush = CreateSolidBrush(RGB(200,200,200));
	//FillRgn(hdc,hrgn, hbrush);
	//HPEN hPen = CreatePen(PS_DOT,1,RGB(0,255,0));

//	SetWindowRgn(Hbutton,hrgn,1);





////////////////////////////////////////

/////////// create font ////////////////
/// richedit 
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


return 0;
}