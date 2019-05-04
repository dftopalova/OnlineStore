#pragma once
#include "Product_Laptop.h"

class Store
{
public:
	Store();
	Store(int Count);
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();

	int getLastFreePosition() const;
	void add(Product_Laptop& laptop);
	void remove(int sku);
	void change(int sku);
	void print();

private:
	void resizeStore();
	Product_Laptop* products;
	int count;
	int lastFreePosition;
};