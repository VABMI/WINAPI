


long __stdcall on_cmd(HWND hwnd,unsigned int message,unsigned int wparam,long lparam)

{ int ctrl_id = (unsigned short)wparam;
   int id = (unsigned short)wparam;
     	HWND hwn=GetDlgItem(hwnd,70000);
	
 
	//////////////new ////////////
		int edtc=70000;
	    int ibhwn2=50001;
	for(int p=30001;p<=cbutc;p++)
	{
		if(id==p)
		{ HWND hwnd2=GetDlgItem(hwnd,70000);
		  SetWindowPos(hwnd2, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE); 

		  MessageBox(hwnd,"Asdasd","asdasdas",MB_OK);
	  	  HWND bhwn1=GetDlgItem(hwnd,id);
		   
		  HWND bhwn2=GetDlgItem(hwnd,ibhwn2);

		  HWND hwn2=GetDlgItem(hwnd,edtc);

  		  DestroyWindow(hwn2);
		  DestroyWindow(bhwn1);
		  DestroyWindow(bhwn2);

		 

		}
		ibhwn2++;
		edtc++;
    }



		  
 switch(id)
 
 {

  
	
    case 5001:
	   	on_create(hwnd,message,wparam,lparam);
   break;
	case 5006:

	hfont_glob=select_font(hwnd);
	SendMessage(hwn,WM_SETFONT,(UINT)hfont_glob,1);

		break;
	case 5007:

		edittextferi=choose_color(hwnd);
		InvalidateRect(hwn,0,1);

	  break;
	case 5008:

	bckferi=choose_color(hwnd);
	InvalidateRect(hwn,0,1);

	  break;
	case 5009:
	textlineferi=choose_color(hwnd);
	InvalidateRect(hwn,0,1);
	  break;
						//////////////// TExt align //////
	case 5010:


		//editstyle=WS_VISIBLE|WS_CHILD|WS_BORDER|ES_MULTILINE|ES_CENTER;

		//SendMessage(hwn, BM_SETSTYLE, (WPARAM)(ES_CENTER), (LPARAM)TRUE);
	
		///EM_SETSEL

//SetWindowLong(hwn,GWL_ID,0);
//SetWindowLong(hwn,GWL_HINSTANCE,0);
 //SetWindowLong(hwn,GWL_EXSTYLE,0); 
 ///SetWindowLong(hwn,GWL_HWNDPARENT,0); 
		SetWindowLong(hwn,GWL_STYLE,WS_VISIBLE|WS_CHILD|WS_BORDER|ES_MULTILINE|ES_CENTER|WS_VSCROLL);	
		
	//	SendMessage(hwn,EM_SETSEL,1,2);
		InvalidateRect(hwn,0,1);

		    //////  GetWindowLong();

		break;
	case 5011:
				SetWindowLong(hwn,GWL_STYLE,WS_VISIBLE|WS_CHILD|WS_BORDER|ES_MULTILINE|ES_RIGHT|WS_VSCROLL);	

						InvalidateRect(hwn,0,1);
		break;
	case 5012:
	
				SetWindowLong(hwn,GWL_STYLE,WS_VISIBLE|WS_CHILD|WS_BORDER|ES_MULTILINE|ES_LEFT|WS_VSCROLL);	

				InvalidateRect(hwn,0,1);
		break;


   }









	////////////////////////////


	



 if(ctrl_id==ID_MENU_COLOR)
	{
	ULONG color;
		if(color=choose_color(hwnd))
		{
		SetClassLong(hwnd,GCL_HBRBACKGROUND,(LONG)CreateSolidBrush(color));  //// backgraundze feris dasma 
		
		
		//ULONG err=GetLastError();

		/*
		InvalidateRect(hwnd,0,1);
		SendMessage(hwnd,WM_PAINT,0,0);
		InvalidateRect(hwnd,0,0);
		*/
		HWND h=GetDlgItem(hwnd,30);
		SetClassLong(h,GCL_HBRBACKGROUND,(LONG)CreateSolidBrush(color));
		InvalidateRect(h,0,1);
		SendMessage(h,WM_PAINT,0,0);
		//InvalidateRect(h,0,0);
		
		}
	}


	
	
	else if(ctrl_id==ID_MENU_FINDTEXT)
	{
	WinExec("calc.exe",1);
	//find_text(hwnd);
	}
	else if(ctrl_id==ID_MENU_WINAPI)
		WinExec("HELP\\winhlp32.exe progtech.hlp",1);
	else if(ctrl_id==ID_MENU_C_CPP)
		WinExec("HELP\\winhlp32.exe bcpp.hlp",1);
	else if(ctrl_id==ID_MENU_ALL)
		WinExec("HELP\\winhlp32.exe",1);
	
	else if(ctrl_id==ID_MENU_ABOUT)
		MessageBox(hwnd,"Copyright Quantum LTD","Quantum Labs",0);
	else if(ctrl_id==10)
	{
	//WinExec("calc.exe",1);
	HWND h=0;
	char str[500];
	h=GetDlgItem(hwnd,50);
	SendMessage(h,WM_GETTEXT,500,(long)str);
	strcat(str,"1");
	SendMessage(h,WM_SETTEXT,0,(long)str);
	
	h=GetDlgItem(hwnd,20);
	SendMessage(h,LB_DELETESTRING,0,0);

	h=GetDlgItem(hwnd,30);
	SendMessage(h,CB_DELETESTRING,0,0);

	}
	else if(ctrl_id==ID_MENU_PRIMES)
	{
	__int64 number=2342342364564564;
	char str[1000]="";
	HWND hedit;
		for(__int64 k=0;k<number;k++)
			if(isprime(k))
			{
			sprintf(str,"%ld",k);
			SendMessage(hedit,EM_REPLACESEL,0,(LPARAM)str);
			}
	}



return 0;
}