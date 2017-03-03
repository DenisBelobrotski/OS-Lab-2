#include <fstream>
#include <cstdio>
#include <iostream>
#include <windows.h>
#include "order.h"

using namespace std;

void outputBinary(char* path)
{
	Order tmpOrder;
	int numOfWritings = 0;
	ifstream fin(path, ios::binary);

	fin.seekg(0, ios::beg);
	fin.read((char*)&numOfWritings, sizeof(int));
	for (int i = 0; i < numOfWritings; i++)
	{
		fin.read((char*)&tmpOrder, sizeof (Order));

		cout << tmpOrder.code << endl;
		cout << tmpOrder.name << endl;
		cout << tmpOrder.price << endl;
		cout << tmpOrder.amountOfSoldGoods << endl;
		cout << tmpOrder.amountOfUnsoldGoods << endl << endl;
	}

	fin.close();
}