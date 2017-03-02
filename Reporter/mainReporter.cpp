#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(0, ".1251");
	int codeOfReport = 0;

	int code = 0;
	char name[21];
	double price = 0;
	int amountOfSoldGoods = 0;
	int amountOfUnsoldGoods = 0;

	if (argc > 1)
	{
		ifstream fin(argv[1], ios::binary);
		if (!fin.is_open())
		{
			cout << "Input file wasn't open.\n";
			fin.close();
			return 0;
		}

		ofstream fout(argv[2]);

		codeOfReport = atoi(argv[3]);

		fout << "Report about ";
		if (codeOfReport == 1)
			fout << "sold";
		else 
			if (codeOfReport == 2)
				fout << "unsold";
			else
			{
				cout << "Uncorrect code of report.\n";
				return 0;
			}
		fout << " goods. File: " << argv[1] << endl;

		fin.seekg(0, ios::beg);
		while (!fin.eof()) {
			fin >> code;
			fout << "code: " << code << endl;

			fin.getline(name, 21);
			fout << "name: " << name << endl;

			fin >> price;
			fout << "price: " << price << endl;

			fin >> amountOfSoldGoods >> amountOfUnsoldGoods;
			fout << "total amount of goods: " << (amountOfSoldGoods + amountOfUnsoldGoods) << endl;

			fout << "total price of sold goods: " << (amountOfSoldGoods * price) << endl;
			fout << "total price of unsold goods: " << (amountOfUnsoldGoods * price) << endl;
		}
		fout.close();
	}
	else
		cout << "Not arguments\n";
	return 0;
}