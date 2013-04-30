#include <winsdkver.h>
#define _WIN32_WINNT 0x0501
#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#define UNICODE
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>

int _tmain (int argc, _TCHAR *argv[])
{
	HWND hWnd_iTunes = FindWindow (L"iTunes", L"iTunes");
	
	if (NULL == hWnd_iTunes)
	{
		fputws (L"error: could not find a running iTunes process", stderr);
		
		return 1;
	}
	
	ShowWindow (hWnd_iTunes, SW_HIDE);
	
	return 0;
}