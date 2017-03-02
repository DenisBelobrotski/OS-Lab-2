#include <fstream>
#include <iostream>
#include <windows.h>
#include "order.h"

using namespace std;

int outputBinary(char* path)
{
	ifstream fin(path, ios::binary);
	Order tmpOrder;
	if (!fin.is_open()) {
		fin.close();
		return -1;
	}
	else
	{
		//fin.seekg(0, ios::beg);
		while (!fin.eof())
		{
			fin.read((char*)&tmpOrder, sizeof tmpOrder);
			cout << tmpOrder.code << endl;
			cout << tmpOrder.name << endl;
			cout << tmpOrder.price << endl;
			cout << tmpOrder.amountOfSoldGoods << endl;
			cout << tmpOrder.amountOfUnsoldGoods << endl;
		}
	}
	fin.close();
	return 0;
}