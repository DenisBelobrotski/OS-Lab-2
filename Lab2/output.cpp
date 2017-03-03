#include <fstream>
#include <cstdio>
#include <iostream>
#include <windows.h>
#include "order.h"

using namespace std;

int output(char* path)
{
	ifstream fin(path);
	char tmp[100];
	
	fin.seekg(0, ios::beg);
	while (!fin.eof())
	{
		fin.getline(tmp, 100);
		cout << tmp << endl;
	}
	fin.close();

	return 0;
}