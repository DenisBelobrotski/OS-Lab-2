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
	ofstream fout(argv[1], ios::binary);

	cout << "Enter number of writing iterations:\n";
	cin >> numOfWritings;

	fout.write((char*)&numOfWritings, sizeof(int));
	for (int i = 0; i < numOfWritings; i++)
	{
		cout << "Enter code of product:\n";
		cin >> tmpOrder.code;

		cout << "Enter name of product (max 10 symbols)(without space symbols):\n";
		cin >> tmpOrder.name;

		cout << "Enter price of product:\n";
		cin >> tmpOrder.price;

		cout << "Enter amount of sold goods:\n";
		cin >> tmpOrder.amountOfSoldGoods;

		cout << "Enter amount of unsold goods:\n";
		cin >> tmpOrder.amountOfUnsoldGoods;

		fout.write((char*)&tmpOrder, sizeof (Order));
	}
	fout.close();
		
	return 0;
}