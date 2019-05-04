#include "Store.h"

Store::Store()
	:count(1), lastFreePosition(0)
{
	this->products = new Product_Laptop[count];
}

Store::Store(int Count)
{
	this->count = Count;
	this->lastFreePosition = 0;
	this->products = new Product_Laptop[count];
}

Store::Store(const Store & other)
{
	this->count = other.count;
	this->lastFreePosition = other.lastFreePosition;
	this->products = new Product_Laptop[count];
	for (int i = 0; i < getLastFreePosition(); i++)
	{
		products[i] = other.products[i];
	}
}

Store & Store::operator=(const Store & other)
{
	if (this != &other)
	{
		this->count = other.count;
		this->lastFreePosition = other.lastFreePosition;
		delete[] products;
		this->products = new Product_Laptop[count];
		for (int i = 0; i < getLastFreePosition(); i++)
		{
			products[i] = other.products[i];
		}
	}
	return *this;
}

Store::~Store()
{
	delete[] products;
}

int Store::getLastFreePosition() const
{
	return lastFreePosition;
}

void Store::add(Product_Laptop & product)
{
	for (int i = 0; i < getLastFreePosition(); i++)
	{
		if (product.getSKU() == products[i].getSKU())
		{
			cout << endl << "The SKU, that you have just entered already exists!" << endl;
			cout << "The product will not be added in the store!" << endl;
			return;
		}
	}
	if (lastFreePosition == -1)
	{
		lastFreePosition++;
		products[lastFreePosition] = product;
		return;
	}
	if (lastFreePosition == count)
	{
		resizeStore();
	}
	products[lastFreePosition++] = product;
}

void Store::remove(int sku)
{
	int ind = -1;
	for (int i = 0; i < getLastFreePosition(); i++)
	{
		if (products[i].getSKU() == sku)
			ind = i;
	}
	if (ind < 0)
	{
		cout << "No such a SKU!" << endl;
		return;
	}
	if (ind == 0 && lastFreePosition == 1)
	{
		count = 0;
		lastFreePosition = 0;
		return;
	}
	if (ind == lastFreePosition - 1)
	{
		count = ind;
		lastFreePosition = ind;
		return;
	}
	for (int i = ind; i < lastFreePosition - 1; i++)
	{
		products[i] = products[i + 1];
	}
	lastFreePosition--;
}

void Store::change(int sku)
{
	bool isThere = false;
	int ind = -1;
	for (int i = 0; i < getLastFreePosition(); i++)
	{
		if (products[i].getSKU() == sku)
		{
			isThere = true;
			ind = i;
		}
	}

	if (isThere)
	{
		cout << "New brand: ";
		char* newBrand = new char[100];
		cin.ignore();
		cin.getline(newBrand, 100);
		products[ind].setBrand(newBrand);

		cout << "New model: ";
		char* newModel = new char[100];
		cin.getline(newModel, 100);
		products[ind].setModel(newModel);

		cout << "New OS: ";
		char* newOS = new char[100];
		cin.getline(newOS, 100);
		products[ind].setOS(newOS);

		int size;
		cout << "New screen size: ";
		cin >> size;
		products[ind].setScreenSize(size);

		double price;
		cout << "New price: ";
		cin >> price;
		products[ind].setPrice(price);

		cout << "New RAM: ";
		int ram;
		cin >> ram;
		products[ind].setRAM(ram);

		cout << "New brand of the CPU: ";
		char* buffCPU = new char[100];
		cin.ignore();
		cin.getline(buffCPU, 100);
		products[ind].setBrandOfCPU(buffCPU);

		cout << "New quantity: ";
		int quantity;
		cin >> quantity;
		products[ind].setQuantity(quantity);

		delete[] newBrand;
		delete[] newModel;
		delete[] buffCPU;
		delete[] newOS;
	}
	else
		cout << "There is no such SKU!" << endl;
}

void Store::print()
{
	for (int i = 0; i < getLastFreePosition(); i++)
	{
		cout << products[i];
	}
	cout << endl;
	cout << "Count of the products in the store = " << getLastFreePosition() << endl;
}

void Store::resizeStore()
{
	Product_Laptop* newArr = new Product_Laptop[2 * count];
	for (int i = 0; i < getLastFreePosition(); i++)
	{
		newArr[i] = products[i];
	}
	delete[] products;
	products = newArr;
	this->count = 2 * count;
}
