#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <richedit.h>
#include "commctrl.h"
#include <stdlib.h>
#include <malloc.h>
#include <WinSpool.h>
#include <WinCon.h>
#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"WinSpool.lib")

#define IDM_NEW 1700
#define IDM_OPEN 1701
#define IDM_SAVE 1702
#define IDM_GO 1703
#define IDM_FINDE 1704
#define IDM_PRINT 1705
#define IDM_REPLACE 1706
#define IDM_UNDO 1707
#define IDM_PROPETIES 1708  
#define IDM_folder 1709 
#define idStatusBar 5456

	HWND Toolar(HWND);
	void RawDataToPrinter(HWND);
	 
HWND DoCreateStatusBar(HWND hwndParent, int idStatus, HINSTANCE hinst, int cParts);