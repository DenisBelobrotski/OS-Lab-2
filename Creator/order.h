#ifndef ORDER_H
#define ORDER_H

struct Order
{
	int code;
	char name[10];
	double price;
	int amountOfSoldGoods;
	int amountOfUnsoldGoods;
};

#endif