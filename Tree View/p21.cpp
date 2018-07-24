#include "head.h"
HFONT hfont_global;
HWND h;



			
	HWND tree;
	HINSTANCE hInst,g_hInst; // main function handler
#define WIN32_LEAN_AND_MEAN // this will assume smaller exe
TV_ITEM tvi;
HTREEITEM Selected;

TV_INSERTSTRUCT tvinsert;  // struct to config out tree control




HTREEITEM Parent;           // Tree item handle
HTREEITEM Before;           // .......
HTREEITEM Root;             // .......

HTREEITEM hitTarget;
static HTREEITEM hPrev=(HTREEITEM)TVI_FIRST;

HIMAGELIST hImageList;      // Image list array hadle
HBITMAP hBitMap;            // bitmap handler
bool flagSelected=false;

HWND hTree;
TVHITTESTINFO tvht; 
POINTS Pos;
bool Dragging;

HWND hEdit;






	//=====================================================//
HWND CreateATreeView(HWND hwndParent);


HTREEITEM AddItemToTree(HWND hwndTV, LPSTR lpszItem, int nLevel) 

{ 
    TV_ITEM tvi; 
    TV_INSERTSTRUCT tvins; 
    static HTREEITEM hPrev = (HTREEITEM) TVI_FIRST; 
    static HTREEITEM hPrevRootItem = NULL; 
    static HTREEITEM hPrevLev2Item = NULL; 
    HTREEITEM hti; 
 
    tvi.mask = TVIF_TEXT | TVIF_IMAGE 
        | TVIF_SELECTEDIMAGE | TVIF_PARAM; 
 
    // Set the text of the item. 
    tvi.pszText = lpszItem; 
    tvi.cchTextMax = lstrlen(lpszItem); 
 
    // Assume the item is not a parent item, so give it a 

    // document image. 
    tvi.iImage = 0; 
    tvi.iSelectedImage = 0; 
 
    // Save the heading level in the item's application-defined 
    // data area. 
    tvi.lParam = (LPARAM) nLevel; 
 
    tvins.item = tvi; 
    tvins.hInsertAfter = hPrev; 
 
    // Set the parent item based on the specified level. 
    if (nLevel == 1) 
        tvins.hParent = TVI_ROOT; 
    else if (nLevel == 2) 
        tvins.hParent = hPrevRootItem; 
    else 

        tvins.hParent = hPrevLev2Item; 
 
    // Add the item to the tree-view control. 
    hPrev = (HTREEITEM) SendMessage(hwndTV, TVM_INSERTITEM, 0, 
         (LPARAM) (LPTV_INSERTSTRUCT) &tvins); 
 
    // Save the handle of the item. 
    if (nLevel == 1) 
        hPrevRootItem = hPrev; 
    else if (nLevel == 2) 
        hPrevLev2Item = hPrev; 
 
    // The new item is a child item. Give the parent item a 
    // closed folder bitmap to indicate it now has child items. 

    if (nLevel > 1) { 
        hti = TreeView_GetParent(hwndTV, hPrev); 
        tvi.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE; 
        tvi.hItem = hti; 
        tvi.iImage =0; 
        tvi.iSelectedImage = 0; 
        TreeView_SetItem(hwndTV, &tvi); 
    } 
 
    return hPrev; 
} 
 



void create(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{

	//=====================================================//
	
	CreateATreeView(hwnd);

	/*
	
	TVITEM tvitm;	
	tvitm.mask=TVIF_TEXT;
	tvitm.pszText="vaxo";
	tvitm.cchTextMax=strlen(tvitm.pszText);

	tvinsert.item=tvitm;
	tvinsert.hInsertAfter=TVI_ROOT;
	SendMessage(hwnd,TVM_INSERTITEM,(WPARAM)0,(LPARAM)&tvitm);

	
	tvitm.pszText="saqartvelo";
	tvitm.cchTextMax=lstrlen("saqartvelo");
	tvinsert.item=tvitm;
	SendMessage(hwnd,TVM_INSERTITEM,(WPARAM)0,(LPARAM)&tvinsert);




	tvitm.pszText="item3";
	tvitm.cchTextMax=lstrlen(tvitm.pszText);
	
	tvitm.hItem=TreeView_GetParent(hwnd,tvitm.hItem);



	*/


	//	CreateWindowEx(0, WC_TREEVIEW,TEXT("Tree View"), WS_VISIBLE | WS_CHILD,0, 0, 200, 500, hwnd, (HMENU)123, GetModuleHandle(NULL), NULL);
	//	if(InitTreeViewImageLists()

	/*
	
	tvi.mask=TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_PARAM;
	tvi.pszText="saqartvelo";
	tvi.cchTextMax=lstrlen("saqartvelo");
	tvi.iImage=1;
	tvi.iSelectedImage=1;
	tvi.lParam=(LPARAM)1;
	tvinsert.item=tvi;
	tvinsert.hInsertAfter=hPrev;
	
		TreeView_CreateDragImage(hwnd,hitTarget);	

		hImageList=ImageList_Create(16,16,ILC_COLOR16,2,10);
		
		hBitMap=(HBITMAP)LoadBitmap(NULL, MAKEINTRESOURCE("C:\\Users\\vaxoa\\OneDrive\\Documents\\GitHub\\WINAPI\\icon\\BMP.png"));
		
		///// C:\Users\vaxoa\OneDrive\Desktop\icon\Itzikgur-My-Seven-Downloads-1.ico
		
		
		
		
		
		ImageList_Add(hImageList,hBitMap,NULL);	

		DeleteObject(hBitMap);	

		
		*/


	//	SendDlgItemMessage(hwnd,123,TVM_SETIMAGELIST,0,(LPARAM)&tvinsert);

		

//////////////////////////////// parents and children /////////////////////////////////
	HWND hwnd_tv=GetDlgItem(hwnd,123);
	/*
			tvinsert.hParent=NULL;			// top most level no need handle
			tvinsert.hInsertAfter=TVI_ROOT; // work as root level
            tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE;//|TVIF_CHILDREN;//|TVIF_SELECTEDIMAGE|
	        tvinsert.item.pszText="Parent";
			tvinsert.item.cchTextMax=128;
			tvinsert.item.iImage=0;
			tvinsert.item.iSelectedImage=1; 
			Parent=(HTREEITEM)SendMessage(hwnd_tv,TVM_INSERTITEM,0,(LPARAM)&tvinsert);	//SendDlgItemMessage(hwnd,123,TVM_INSERTITEM,0,(LPARAM)&tvinsert);

			
			
				tvinsert.hParent=Parent;         // handle of the above data
				tvinsert.hInsertAfter=TVI_LAST;  // below parent
				tvinsert.item.pszText="Child 1";
				tvinsert.item.iImage=0;
				tvinsert.item.iSelectedImage=0; 

					 Parent=(HTREEITEM)SendDlgItemMessage((HWND)Parent,123,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
					 */
					 AddItemToTree(hwnd_tv,"saqartvelo",1);
					  AddItemToTree(hwnd_tv,"saqartvelo2",2);
					   AddItemToTree(hwnd_tv,"saqartvelo3",3);
					     AddItemToTree(hwnd_tv,"saqartvelo2",1);
						 AddItemToTree(hwnd_tv,"saqartvelo21",2);
						  AddItemToTree(hwnd_tv,"saqartvelo21",2);
					      AddItemToTree(hwnd_tv,"saqartvelo22",3);
						
					 /*
////======================================================//////////////////////////////////////////////////////
			 tvinsert.hParent=NULL;			// top most level no need handle
			 tvinsert.hInsertAfter=TVI_LAST; // work as root level
	         tvinsert.item.pszText="Parent2";
             Parent=(HTREEITEM)SendDlgItemMessage(hwnd,123,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
/////==================================================//////////////////////////////////////////////
	 tvinsert.hParent=NULL;			// top most level no need handle
			 tvinsert.hInsertAfter=TVI_LAST; // work as root level
	         tvinsert.item.pszText="Parent3";
             Parent=(HTREEITEM)SendDlgItemMessage(hwnd,123,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
			 */

			 

}


//======================== 22222222222222=====

BOOL InitTreeViewImageLists(HWND hwndTV) 
{ 
    HIMAGELIST himl;  // handle to image list 
    HBITMAP hbmp;     // handle to bitmap 

    // Create the image list. 
    if (hImageList=ImageList_Create(16,16,ILC_COLOR16,2,10)) return 0; 

    // Add the open file, closed file, and document bitmaps. 
    hbmp = LoadBitmap(g_hInst, MAKEINTRESOURCE("C:\\Users\\vaxoa\\OneDrive\\Desktop\\icon\\resource\\bitmap3.bmp")); 
 int   g_nOpen = ImageList_Add(hImageList, hbmp, (HBITMAP)NULL); 
    DeleteObject(hbmp); 


    // Fail if not all of the images were added. 
//   if (ImageList_GetImageCount(hImageList) 2)return FALSE; 

    // Associate the image list with the tree-view control. 
    TreeView_SetImageList(hwndTV, hImageList, TVSIL_NORMAL); 

    return TRUE; 
}
long __stdcall window_main_function_chvenia(HWND hwnd,unsigned int message, unsigned int wparam,long lparam)
{	
	switch(message)
	{
			case WM_INITDIALOG: 
		{

	

		}
		break;
		case WM_CREATE:
		create(hwnd, message,wparam,lparam);
		break;
		
		case WM_COMMAND:
	
		if(wparam==3){
		}
		break;
		
		case WM_LBUTTONDBLCLK:
	
		break;

		case WM_PAINT:

		
		break;

		case WM_KEYDOWN:
	
		break;
		case WM_NOTIFY:
			
			break;
		
	}
return DefWindowProc(hwnd,message,wparam,lparam);
}

void main()
{
HWND hwnd=0;
int X,Y,W,H;
ULONG style=0;
WNDCLASS wc;
ZeroMemory(&wc,sizeof(WNDCLASS));
wc.style=CS_DBLCLKS|SW_MAXIMIZE;
wc.lpfnWndProc=(WNDPROC)&window_main_function_chvenia;
wc.lpszClassName="12";
wc.hbrBackground=(HBRUSH)CreateSolidBrush(RGB(200,200,200));
wc.hIcon=(HICON)LoadImage(0,"c:\\1.ico",IMAGE_ICON,16,16,LR_LOADFROMFILE);
	if(RegisterClass(&wc)==0)
	{
	MessageBox(hwnd,"RegisterClass error",0,0);
	return;
	}
//mtavari fanjara:
style=WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
X=10;Y=30;W=700;H=500;
hwnd=CreateWindow(wc.lpszClassName,"Main",style|SW_MAXIMIZE,X,Y,W,H,0,0,0,0);
MSG msg;
int s=1;
	while(s!=0)
	{
	s=GetMessage(&msg,0,0,0);
	TranslateMessage(&msg);
	DispatchMessage(&msg);
	}
}



HWND CreateATreeView(HWND hwndParent)
{ 
    RECT rcClient;  // dimensions of client area 
    HWND hwndTV;    // handle to tree-view control 
    InitCommonControls(); 
  
	///// | 0x0008|0x0010

	hwndTV = CreateWindow( WC_TREEVIEW,TEXT("Tree View"), TVS_LINESATROOT|TVS_HASBUTTONS|WS_VISIBLE | TVS_CHECKBOXES|WS_CHILD|WS_BORDER|TVS_HASLINES|TVS_EDITLABELS ,10,20, 200, 700, hwndParent, (HMENU)123, NULL, NULL);
	if (InitTreeViewImageLists(hwndTV)) // || !InitTreeViewItems(hwndTV))
    { 
        DestroyWindow(hwndTV); 
        return FALSE; 
    } 

	SendDlgItemMessage(hwndParent,123,TVM_SETIMAGELIST,0,(LPARAM)hImageList);
    return hwndTV;
} 