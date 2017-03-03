#include <fstream>
#include <cstdio>
#include <iostream>
#include <windows.h>
#include "order.h"

using namespace std;

void outputBinary(char*);
int output(char*);

int main()
{
	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char pathToCreator[] = "D:\\”чЄба\\2 курс\\прога\\ќси\\Lab2\\Debug\\Creator.exe";
	char pathToReporter[] = "D:\\”чЄба\\2 курс\\прога\\ќси\\Lab2\\Debug\\Reporter.exe";
	char* lpszCommandLine = new char[1000];
	char* pathToInputFile = new char[261];
	char* pathToReportFile = new char[261];
	char* reportCode = new char[5];

	cout << "Enter path to input binary file:\n";
	cin.getline(pathToInputFile, 261);

	sprintf(lpszCommandLine, "%s %s", pathToCreator, pathToInputFile);

	STARTUPINFO si1;
	PROCESS_INFORMATION procInfo1;
	ZeroMemory(&si1, sizeof(STARTUPINFO));
	si1.cb = sizeof(STARTUPINFO);

	CreateProcess(NULL, lpszCommandLine, NULL, NULL, FALSE, NULL, NULL, NULL, &si1, &procInfo1);

	WaitForSingleObject(procInfo1.hProcess, INFINITE);

	CloseHandle(procInfo1.hThread);
	CloseHandle(procInfo1.hProcess);

	cout << "Content in binary file:\n\n";
	outputBinary(pathToInputFile);

	cout << "Enter path to report file:\n";
	cin.getline(pathToReportFile, 261);

	cout << "Enter report code:\n";
	cin >> reportCode;

	sprintf(lpszCommandLine, "%s %s %s %s", pathToReporter, pathToInputFile, pathToReportFile, reportCode);

	STARTUPINFO si2;
	PROCESS_INFORMATION procInfo2;
	ZeroMemory(&si2, sizeof(STARTUPINFO));
	si2.cb = sizeof(STARTUPINFO);

	CreateProcess(NULL, lpszCommandLine, NULL, NULL, FALSE, NULL, NULL, NULL, &si2, &procInfo2);

	WaitForSingleObject(procInfo2.hProcess, INFINITE);

	CloseHandle(procInfo2.hThread);
	CloseHandle(procInfo2.hProcess);

	output(pathToReportFile);
	
	return 0;
}