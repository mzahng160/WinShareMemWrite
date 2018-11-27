// WinShareMem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;

#define BUF_SIZE 2660
char szName[] = "FeatureData";

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		BUF_SIZE,
		szName);

	char *pBuf = (char*)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	while (1)
	{
		cout << "input..." << endl;
		char szInfo[BUF_SIZE*2] = { 0 };
		//gets_s(szInfo);
		memset(szInfo, 'b', BUF_SIZE*2);
		szInfo[BUF_SIZE * 2-1] = '\0';
		memcpy(pBuf, szInfo, BUF_SIZE+1);		
	}

	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);

	return 0;
}

