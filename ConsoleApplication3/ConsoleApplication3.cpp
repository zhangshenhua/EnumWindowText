// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>


BOOL CALLBACK EnumChildProc(HWND hWnd,LPARAM lParam);
char className[256]={0};
int _tmain(int argc, _TCHAR* argv[])
{

	while(1) {
		scanf_s("%s", className, _countof(className));
		HWND hWnd=::FindWindowA(className,NULL);    
		if(hWnd)
		{
			::EnumChildWindows(hWnd,EnumChildProc,0);
		}
	}
    return 0;
}

BOOL CALLBACK EnumChildProc(HWND hWnd,LPARAM lParam)
{
    char temp2[256];
    ::SendMessageA(hWnd,WM_GETTEXT,sizeof(temp2)/sizeof(char),(LPARAM)temp2);//EDIT的句柄，消息，接收缓冲区大小，接收缓冲区指针
    printf("%s\n", temp2);
    return true;
}
//Afx:400000:0:0:1d101b4b:0
