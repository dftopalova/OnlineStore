#include "Product_Laptop.h"

Product_Laptop::Product_Laptop()
	: SKU(0), Brand(nullptr), Model(nullptr), OS(nullptr), BrandOfCPU(nullptr), ScreenSize(0), Price(0), RAM(0), Quantity(0)
{
	this->setBrand("");
	this->setModel("");
	this->setOS("");
	this->setBrandOfCPU("");
}

Product_Laptop::Product_Laptop(int sku, char * brand, char * model, char * os, char * cpu, double screen, double price, int ram, int quantity)
{
	setSKU(sku);
	setBrand(brand);
	setBrandOfCPU(cpu);
	setOS(os);
	setModel(model);
	setScreenSize(screen);
	setPrice(price);
	setRAM(ram);
	setQuantity(quantity);
}

Product_Laptop::Product_Laptop(const Product_Laptop & other)
{
	setSKU(other.SKU);
	setBrand(other.Brand);
	setBrandOfCPU(other.BrandOfCPU);
	setOS(other.OS);
	setModel(other.Model);
	setScreenSize(other.ScreenSize);
	setPrice(other.Price);
	setRAM(other.RAM);
	setQuantity(other.Quantity);
}

Product_Laptop & Product_Laptop::operator=(const Product_Laptop & other)
{
	if (this != &other)
	{
		setSKU(other.SKU);
		setBrand(other.Brand);
		setBrandOfCPU(other.BrandOfCPU);
		setOS(other.OS);
		setModel(other.Model);
		setScreenSize(other.ScreenSize);
		setPrice(other.Price);
		setRAM(other.RAM);
		setQuantity(other.Quantity);
	}
	return *this;
}

Product_Laptop::~Product_Laptop()
{
	delete[] Brand;
	delete[] Model;
	delete[] OS;
	delete[] BrandOfCPU;
}

void Product_Laptop::setSKU(int sku)
{
	this->SKU = sku;
}

void Product_Laptop::setBrand(char * brand)
{
	if (brand == nullptr)
		return;
	int len = strlen(brand) + 1;
	delete[] Brand;
	this->Brand = new char[len];
	strcpy_s(Brand, len, brand);
}

void Product_Laptop::setModel(char * model)
{
	if (model == nullptr)
		return;
	int len = strlen(model) + 1;
	delete[] Model;
	this->Model = new char[len];
	strcpy_s(Model, len, model);
}

void Product_Laptop::setOS(char * os)
{
	if (os == nullptr)
		return;
	int len = strlen(os) + 1;
	delete[] OS;
	this->OS = new char[len];
	strcpy_s(OS, len, os);
}

void Product_Laptop::setBrandOfCPU(char * cpu)
{
	if (cpu == nullptr)
		return;
	int len = strlen(cpu) + 1;
	delete[] BrandOfCPU;
	this->BrandOfCPU = new char[len];
	strcpy_s(BrandOfCPU, len, cpu);
}

void Product_Laptop::setScreenSize(double size)
{
	this->ScreenSize = size;
}

void Product_Laptop::setPrice(double price)
{
	this->Price = price;
}

void Product_Laptop::setRAM(int ram)
{
	this->RAM = ram;
}

void Product_Laptop::setQuantity(int quantity)
{
	this->Quantity = quantity;
}

int Product_Laptop::getSKU() const
{
	return SKU;
}

const char * Product_Laptop::getBrand() const
{
	return Brand;
}

const char * Product_Laptop::getModel() const
{
	return Model;
}

const char * Product_Laptop::getOS() const
{
	return OS;
}

const char * Product_Laptop::getBrandOfCPU() const
{
	return BrandOfCPU;
}

double Product_Laptop::getScreenSize() const
{
	return ScreenSize;
}

double Product_Laptop::getPrice() const
{
	return Price;
}

int Product_Laptop::getRAM() const
{
	return RAM;
}

int Product_Laptop::getQuantity() const
{
	return Quantity;
}

ostream & operator<<(ostream & out, const Product_Laptop & laptop)
{
	out << "SKU: " << laptop.getSKU() << endl;
	out << "Brand: " << laptop.getBrand() << endl;
	out << "Model: " << laptop.getModel() << endl;
	out << "OS: " << laptop.getOS() << endl;
	out << "Brand Of CPU: " << laptop.getBrandOfCPU() << endl;
	out << "Screen size: " << laptop.getScreenSize() << endl;
	out << "Price: " << laptop.getPrice() << endl;
	out << "RAM: " << laptop.getRAM() << endl;
	out << "Quantity: " << laptop.getQuantity() << endl;
	out << endl;
	return out;
}
