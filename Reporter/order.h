#ifndef ORDER1_H
#define ORDER1_H

struct Order
{
	int code;
	char name[11];
	double price;
	int amountOfSoldGoods;
	int amountOfUnsoldGoods;
};

#endif