#include <windows.h>
#include<stdio.h>
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
		HWND cm=GetDlgItem(hwnd,1);	HWND lm=GetDlgItem(hwnd,3);
		char out[100];
	switch(Message) {
		
		case WM_COMMAND:
			
			switch(wParam){
				 case 2:
				 MessageBox(hwnd,"Asdasd","Asdas",1);
      for (int i=2; i<1000000; i++) {
        for (int j=2; j<i; j++)
        {
            if (i % j == 0) 
                break;
            else if (i == j+1){
            		sprintf(out,"%i",i);
					SendMessage(cm,CB_ADDSTRING,0,(LPARAM)out);
					SendMessage(lm,LB_ADDSTRING,0,(LPARAM)out);
			}
           

        }   
  }
				
				
			}
			
			break;
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd,combo,listb; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		640, 
		480, 
		NULL,NULL,hInstance,NULL);
		
		combo=CreateWindow("ComboBox","",WS_VISIBLE|WS_BORDER|WS_CHILD|  CBS_DROPDOWN | CBS_HASSTRINGS | WS_OVERLAPPED|WS_VSCROLL ,10,40,100,200,hwnd,(HMENU)1,0,0);
		listb=CreateWindow("listBox","asdasd",WS_VISIBLE|WS_BORDER|WS_CHILD|WS_VSCROLL ,140,40,300,200,hwnd,(HMENU)3,0,0);
		  CreateWindow("button","asdasd",WS_VISIBLE|WS_BORDER|WS_CHILD,10,100,40,40,hwnd,(HMENU)2,0,0);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
