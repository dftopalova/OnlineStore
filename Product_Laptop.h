#pragma once
#include<iostream>

using namespace std;

class Product_Laptop
{
public:
	Product_Laptop();
	Product_Laptop(int sku, char* brand, char* model, char* os, char* cpu, double screen, double price, int ram, int quantity);
	Product_Laptop(const Product_Laptop& other);
	Product_Laptop& operator=(const Product_Laptop& other);
	~Product_Laptop();

	void setSKU(int sku);
	void setBrand(char* brand);
	void setModel(char* model);
	void setOS(char* os);
	void setBrandOfCPU(char* cpu);
	void setScreenSize(double size);
	void setPrice(double price);
	void setRAM(int ram);
	void setQuantity(int quantity);

	int getSKU() const;
	const char* getBrand() const;
	const char* getModel() const;
	const char* getOS() const;
	const char* getBrandOfCPU() const;
	double getScreenSize() const;
	double getPrice() const;
	int getRAM() const;
	int getQuantity() const;

	friend ostream& operator<<(ostream& out, const Product_Laptop& laptop);

private:
	int SKU;
	char* Brand;
	char* Model;
	char* OS;
	char* BrandOfCPU;
	double ScreenSize;
	double Price;
	int RAM;
	int Quantity;
};