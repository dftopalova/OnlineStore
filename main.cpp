#include<iostream>
#include "Store.h"
#include "Product_Laptop.h"
using namespace std;

void ShowMenu()
{
	cout << endl;
	cout << "A. Add new product " << endl;
	cout << "X. Delete product " << endl;
	cout << "C. Change product" << endl;
	cout << "D. Display products" << endl;
	cout << "Q. Quit" << endl;
	cout << endl;
}

int main()
{
	Store store(10);

	char command;
	ShowMenu();
	cout << "Choose an option: ";
	cin >> command;
	while (command != 'Q')
	{
		switch (command)
		{
		case 'A':
		{
			int sku;
			cout << "SKU: ";
			cin >> sku;

			cout << "Brand: ";
			char* buffBrand = new char[100];
			cin.ignore();
			cin.getline(buffBrand, 100);

			cout << "Model: ";
			char* buffModel = new char[100];
			cin.getline(buffModel, 100);

			cout << "OS: ";
			char* buffOS = new char[100];
			cin.getline(buffOS, 100);

			int size;
			cout << "Screen size: ";
			cin >> size;

			double price;
			cout << "Price: ";
			cin >> price;

			cout << "RAM: ";
			int ram;
			cin >> ram;

			cout << "Brand of the CPU: ";
			char* buffCPU = new char[100];
			cin.ignore();
			cin.getline(buffCPU, 100);

			cout << "Quantity: ";
			int quantity;
			cin >> quantity;

			Product_Laptop laptop(sku, buffBrand, buffModel, buffOS, buffCPU, size, price, ram, quantity);
			store.add(laptop);
			delete[] buffBrand;
			delete[] buffCPU;
			delete[] buffModel;
			delete[] buffOS;
			break;
		}
		case 'X':
		{
			int sku;
			cout << "Write the SKU of the product to delete: " << endl;
			cin >> sku;
			store.remove(sku);
			break;
		}
		case 'C':
		{
			int sku;
			cout << "Write the SKU of the product to change: " << endl;
			cin >> sku;
			store.change(sku);
			break;
		}
		case 'D':
		{
			store.print();
			break;
		}
		default:
			break;
		}

		ShowMenu();
		cout << "Choose an option: ";
		cin >> command;
	}

	system("pause");
	return 0;
}
