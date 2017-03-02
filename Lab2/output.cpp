#include <fstream>
#include <iostream>
#include <windows.h>
#include "order.h"

using namespace std;

int output(char* path)
{
	cout << path << endl;
	ifstream fin(path);
	char tmp[100];
	if (!fin.is_open()) {
		fin.close();
		return -1;
	}
	else
	{
		fin.seekg(0, ios::beg);
		while (!fin.eof())
		{
			fin.getline(tmp, 100);
			cout << tmp << endl;
		}
	}
	fin.close();
	return 0;
}