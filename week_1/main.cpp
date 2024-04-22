// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class MarbleBag
// {

// 	private:
// 	vector<string> contents;

// 	public:

// 	void addToBag(const string& marble)
// 	{
// 		contents.push_back(marble);
// 	}

// 	int getSize() const
// 	{
// 		return contents.size();
// 	}

// 	void printContents() const
// 	{
// 		for (const string &marble : contents)
// 		{
// 			cout << "-- " << marble << endl;
// 		}
// 	}

// 	void printContents() const
// 	{
// 		cout << "Bag contents:" << endl;
// 		for (const string &marble : contents)
// 		{
// 			cout << "-- " << marble << endl;
// 		}
// 	}
// };


void main()
{
	cout << "Hello, World!" << endl;
}

class Marble
{
private:

	string color;
	int size;

public:

	Marble(const string& color, const int size)
	{
		this->color = color;
		this->size = size;
	}

	string getColor() const
	{
		return color;
	}

	int getSize() const
	{
		return size;
	}
};

class MarbleBag
{
private:
	int quantity = 0;
	int capacity = 25;
	Marble* contents[];

public:
	void addMarble(Marble& marble)
	{
		if (quantity >= capacity)
		{
			cout << "The bag is full." << endl;
			return;
		}
		contents[quantity] = &marble;
		quantity++;
	}

	void removeMarble(int index)
	{
		if (index >= 0 && index < quantity)
		{
			delete contents[index];
			for (int i = index; i < quantity - 1; i++)
			{
				contents[i] = contents[i + 1];
			}
			quantity--;
			return;
		}
		else
		{
			cout << "Invalid index." << endl;
			return;
		}
	}

	void printContents() const
	{
		cout << "Bag contents:" << endl;
		for (int i = 0; i < quantity; i++)
		{
			cout << "-- " << contents[i]->getSize() << "mm " << contents[i]->getColor() << endl;
		}
	}

	int getSize() const
	{
		return quantity;
	}

	Marble* getMarble(int index) const
	{
		if (index >= 0 && index < quantity)
		{
			return contents[index];
		}
		else
		{
			return nullptr;
		}
	}

	~MarbleBag()
	{
		for (int i = 0; i < quantity; i++)
		{
			delete contents[i];
		}
	}

};
