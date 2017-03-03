#include <iostream>
#include <cstring>
#include <fstream>
#include "order.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(0, ".1251");
	int numOfWritings = 0;
	Order tmpOrder;
	ifstream fin(argv[1], ios::binary);
	ofstream fout(argv[2]);
	int codeOfReport = atoi(argv[3]);

	switch (codeOfReport)
	{
		case 1:
			fout << "Report about sold goods. ";
			break;
		case 2:
			fout << "Report about unsold goods. ";
			break;
		default:
			fout << "Incorrect report code! ";
	}
	fout << "File: " << argv[1] << "\n\n";

	fin.seekg(0, ios::beg);
	fin.read((char*)&numOfWritings, sizeof(int));
	for (int i = 0; i < numOfWritings; i++)
	{
		fin.read((char*)&tmpOrder, sizeof(Order));

		fout << "code: " << tmpOrder.code << endl;
		fout << "name: " << tmpOrder.name << endl;
		fout << "price: " << tmpOrder.price << endl;
		switch (codeOfReport)
		{
		case 1:
			fout << "sold goods: " << tmpOrder.amountOfSoldGoods << endl;
			fout << "total price: " << tmpOrder.amountOfSoldGoods * tmpOrder.price << endl;
			break;
		case 2:
			fout << "unsold goods: " << tmpOrder.amountOfUnsoldGoods << endl;
			fout << "total price: " << tmpOrder.amountOfUnsoldGoods * tmpOrder.price << endl;
			break;
		default:
			fout << "Incorrect report code! ";
		}
		fout << endl;
	}
	fin.close();
	fout.close();
	
	return 0;
}