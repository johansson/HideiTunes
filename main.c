#include <winsdkver.h>
#define _WIN32_WINNT 0x0501
#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#define UNICODE
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

HWND hWnd_iTunes = NULL;

BOOL CALLBACK FindiTunes (HWND hWnd, LPARAM lParam)
{
	LPWSTR title;	
	int len, is_iTunes;
	
	len = GetWindowTextLength (hWnd);
	title = (LPWSTR) malloc (sizeof (WCHAR) * (len + 1));
	
	GetWindowText(hWnd, title, len + 1);
	
	is_iTunes = 0 == lstrcmpW (title, L"iTunes");
	
	free (title);
	
	if (is_iTunes)
	{
		hWnd_iTunes = hWnd;
		return FALSE;
	}
	
	return TRUE;
}

int _tmain (int argc, _TCHAR *argv[])
{
	EnumWindows (FindiTunes, (INT_PTR)NULL);
	
	if (NULL == hWnd_iTunes)
	{
		fputws (L"error: could not find a running iTunes process", stderr);
		
		return 1;
	}
	
	ShowWindow (hWnd_iTunes, SW_HIDE);
	
	return 0;
}