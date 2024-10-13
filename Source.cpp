//Product market

#include<iostream>
using namespace std;

class Product {
	static int next_ID;
	int ID;

	
	string name;
	string description;
	float price;
	float discount;
	
public:
	Product(string name,string description,float price,float discount) {
		ID = ++next_ID;
		Set_name(name);
		Set_description(description);
		Set_price(price);
		Set_discount(discount);
	}

	int Get_ID() {
		return ID;
	}
	string Get_name() {
		return name;
	}
	string Get_description() {
		return description;
	}
	float Get_price() {
		return price;
	}
	float Get_discount() {
		return discount;
	}

	

	void Set_name(string name) {
		this->name = name;
	}
	void Set_description(string description) {
		this->description = description;
	}

	void Set_price(float price) {
		if (price>=0) {
			this->price = price;
		}
		else {
			cout << endl;
			cout << "Price cannot be negative" << endl;
		}
		
	}

	void Set_discount(float discount) {
		if (discount >= 0) {
			this->discount = discount;
		}
		else {
			cout << endl;
			cout << "Discount cannot be negative" << endl;
		}
	}


	

	float Get_Price_Discount() {
		if (discount != 0) {
			return price - ((price * discount) / 100);
		}
		else {
			return price;
		}
	}

	


	void Reset_ID(int new_ID) {
		ID = new_ID;
	}
	
};
int Product::next_ID = 0;
class Stock {
	Product* products[100];
	int count;
	

public:
	Stock() {
		count = 0;
		
	}



	void Show_Stock() {
		cout << endl;
		cout << "--------------------------------- Product List ---------------------------------" << endl;
		cout << endl;
		for (int i = 0; i < count; i++) {
			cout << endl;
			cout << "ID: " << products[i]->Get_ID()
				<< ", Name: " << products[i]->Get_name()
				<< ", Description: " << products[i]->Get_description()
				<< ", Price: $" << products[i]->Get_Price_Discount()
				<< ", Discount: " << products[i]->Get_discount() << "%" << endl;
		}
	}
	

	void Add_Product(string name, string description, float price, float discount) {
		products[count++] = new Product(name, description, price, discount);
		cout << endl;
		
	}

	void Delete_Product(int id) {
		for (size_t i = 0; i < count; i++)
		{
			if (products[i]->Get_ID() == id) {
				delete products[i];
				for (size_t j = i; j < count - 1; j++)
				{
					products[j] = products[j + 1];
				}

				products[count - 1] = nullptr;
				count--;

				for (int k = 0; k < count; k++) {
					products[k]->Reset_ID(k + 1);
				}
				cout << endl;
				cout << "Product with ID " << id << " has been deleted." << endl;
				return;
			}

			
		}
		cout << "No product found with ID " << id << endl;
	}

	void Search_Product(int id) {
		for (size_t i = 0; i < count; i++)
		{
			if (products[i]->Get_ID() == id) {
				cout << endl;
				cout << "--------------------------------- Product List ---------------------------------" << endl;
				cout << endl;
					cout << "ID: " << products[i]->Get_ID()
						<< ", Name: " << products[i]->Get_name()
						<< ", Description: " << products[i]->Get_description()
						<< ", Price: $" << products[i]->Get_Price_Discount()
						<< ", Discount: " << products[i]->Get_discount() << "%" << endl;
				
			}
		}
	}

	void Change_Product_Discount(int id,float discount) {
		for (size_t i = 0; i < count; i++)
		{
			if (products[i]->Get_ID() == id) {
				
				products[i]->Set_discount(discount);

			}
		}
	}

	void Get_Product(int id,int num) {
		for (size_t i = 0; i < count; i++)
		{
			if (products[i]->Get_ID() == id) {

				cout << "Amount : " << num *  products[i]->Get_Price_Discount();
				return;
			}
		}


	}

	void Update_Product(string name, string description, float price, float discount,int id) {
		for (size_t i = 0; i < count; i++)
		{
			if (products[i]->Get_ID() == id) {

				products[i]->Set_name(name);
				products[i]->Set_description(description);
				products[i]->Set_price(price);
				products[i]->Set_discount(discount);

			}
		}
	}

	void Clean_Arrays() {
		for (size_t i = 0; i < count; i++)
		{
			delete products[i];
		}
	}


};

int main() {
	Stock manager;
	
	cout << "Select one: " << endl;
	cout << endl;
	cout << "1 -> Show Products" << endl;
	cout << "2 -> Add Product" << endl;
	cout << "3 -> Delete Product" << endl;
	cout << "4 -> Search Product" << endl;
	cout << "5 -> Change discount" << endl;
	cout << "6 -> Get Product" << endl;
	cout << "7 -> Update Product" << endl;
	cout << "8 -> Exit" << endl;
	
	manager.Add_Product("Bread", "Freshly baked whole grain bread", 1.5, 0);
	manager.Add_Product("Milk", "Organic full-fat milk", 1.20, 5.0);
	manager.Add_Product("Cheese", "Aged cheddar cheese", 3.75, 10.0);

	while (true) {
		char select;
		cout << endl;
		cout << "Enter select : ";
		cin >> select;
		
		switch (select)
		{
		case '1': {
			manager.Show_Stock();
			cout << endl;
			
			break;
		}
			

		case '2': {
			cout << endl;
			cout << "------------------------------------------------Product Registration------------------------------------------------" << endl;
			cout << endl;
			string name, description;
			float price, discount;
			cout << "Enter product name : ";
			cin >> name;
			cout << "Enter product description : ";
			cin >> description;
			cout << "Enter price : $ ";
			cin >> price;
			cout << "Enter discount (as percentage) : ";
			cin >> discount;
			cout << endl;
			manager.Add_Product(name, description, price, discount);
			cout << "The product was successfully added" << endl;
			break;
		}
			

		case '3': {
			int id;
			cout << endl;
			cout << "Enter product ID : ";
			cin >> id;
			manager.Delete_Product(id);
			
			break;
		}
			
		case '4':{
			int id;
			cout << endl;
			cout << "Enter product ID : ";
			cin >> id;
			manager.Search_Product(id);

			break;
		}
        
		case '5': {
			float discount;
			int id;
			cout << endl;
			cout << "Enter product ID : ";
			cin >> id;
			cout << "Enter new discount : ";
			cin >> discount;
			manager.Change_Product_Discount(id, discount);
			cout << endl;
			cout << "The product was successfully changed" << endl;
			break;
		}

		case '6': {
			int id,num;
			cout << endl;
			cout << "Enter product ID : ";
			cin >> id;
			cout << "How many do you want to buy ? : ";
			cin >> num;
			manager.Get_Product(id, num);
			break;
		}
		case '7':{
			int id;
			cout << endl;
			cout << "Enter product ID : ";
			cin >> id;
			string name, description;
			float price, discount;
			cout << "Enter product name : ";
			cin >> name;
			cout << "Enter product description : ";
			cin >> description;
			cout << "Enter price : $ ";
			cin >> price;
			cout << "Enter discount (as percentage) : ";
			cin >> discount;
			manager.Update_Product(name, description, price, discount,id);
			cout << endl;
			cout << "The product was successfully update" << endl;
			break;
		}

		case '8': {
			cout << endl;
			cout << "-----------------------------------------------------Exit-----------------------------------------------------";
			cout << endl;
			manager.Clean_Arrays();
			exit(1);
			break;
		}
		default:
			cout << endl;
			cout << "Please select correct one" << endl;
			break;
		}
		
		
		
	}
	return 0;
}

	


	

