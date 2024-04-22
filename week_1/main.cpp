// main.cpp : Defines the entry point for the application.
//

#include "main.h"

using namespace std;

/**
* Class representing a Marble with a color and size.
*/
class Marble
{
private:

	string color;
	int size;

public:

	/**
	* Constructor for the Marble class.
	*
	* @param color The color of the marble.
	* @param size The size of the marble.
	*/
	Marble(const string& color, const int& size)
	{
		this->color = color;
		this->size = size;
	}

	/**
	* Function to get the color of the marble.
	*
	* @return The color of the marble.
	*/
	string getColor() const
	{
		return color;
	}

	/**
	* Function to get the size of the marble.
	*
	* @return The size of the marble.
	*/
	int getSize() const
	{
		return size;
	}
};

/**
* Class representing a bag of Marbles with a certain capacity.
*/
class MarbleBag
{
private:
	int quantity = 0;
	int capacity = 5;
	Marble* contents[];

public:

	/**
	* Function to add a marble to the bag.
	*
	* @param marble The marble to add.
    */
	void addMarble(Marble *marble)
	{
		if (quantity >= capacity)
		{
			cout << "The bag is full." << endl;
			return;
		}
		contents[quantity] = marble;
		quantity++;
	}

	/**
	* Function to remove a marble from the bag.
	*
	* @param index The index of the marble to remove.
	*/
	void removeMarble(int index)
	{
		if (index >= 0 && index < quantity)
		{
			// Delete the marble at the given index.
			delete contents[index];

			// Shift all the marbles after the removed one back one place.
			for (int i = index; i < quantity - 1; i++)
			{
				contents[i] = contents[i + 1];
			}

			// Decrement the quantity.
			quantity--;
			return;
		}
		else if (quantity == 0)
		{
			cout << "The bag is empty." << endl;
			return;
		}
		else
		{
			cout << "Invalid index." << endl;
			return;
		}
	}

	/**
	* Function to print the contents of the bag.
	* This will print the number of marbles in the bag, and then print each marble.
 	*/
	void printContents() const
	{
		if (quantity == 0)
		{
			cout << "The bag is empty." << endl;
			return;
		}
		cout << "The bag contains " << quantity << "/" << capacity << " marbles." << endl;
		cout << "Bag contents:" << endl;
		for (int i = 0; i < quantity; i++)
		{
			cout << "-- " << contents[i]->getSize() << "mm " << contents[i]->getColor() << endl;
		}
	}

	/**
	* Function to get the number of marbles in the bag.
	* 
	* @return The number of marbles in the bag.
	*/
	int getSize() const
	{
		return quantity;
	}

	/**
	* Function to get a marble from the bag.
	* 
	* @param index The index of the marble to get.
	* 
	* @return The marble at the given index, or nullptr if the index is invalid.
	* 
	* @see Marble
	*/
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

	/**
	* Destructor for the MarbleBag class.
	* This will delete all the marbles in the bag.
 	*/
	~MarbleBag()
	{
		for (int i = 0; i < quantity; i++)
		{
			delete contents[i];
		}
	}

};

/**
* Function to get an integer from the user.
* This function will keep asking for an integer until a valid one is entered.
* 
* @return The integer entered by the user.
*/
static int inputInt()
{
	while (true)
	{
		cout << flush;
		int n;
		if (cin >> n)
		{
			return n;
		}
		else
		{
			cout << "Error! Bad input! Ignoring..." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid integer." << endl;
		}
	}
}

void main()
{
	cout << "Hello!" << endl;
	// Initialize stuff and add a couple of default marbles.
	MarbleBag bag;

	Marble *m1 = new Marble("red", 10);
	bag.addMarble(m1);
	Marble *m2 = new Marble("blue", 15);
	bag.addMarble(m2);

	bag.printContents();

	// Main loop.
	while (true)
	{
		// Print the menu.
		cout << "What do you want to do?" << endl;
		cout << "1. Add a marble" << endl;
		cout << "2. Remove a marble" << endl;
		cout << "3. Print bag contents" << endl;
		cout << "4. Get a marble" << endl;
		cout << "5. Exit" << endl;

		int choice = inputInt();

		// I would have used a switch statement here, but it was throwing an error to do with
		// the variables initialized inside the one of the cases no being initialized in the others.
		if (choice == 1) // Add a marble.
		{
			cout << "Adding a marble." << endl;
			cout << "What color do you want? ";
			string color;
			cin >> color;
			cout << "What size do you want (in mm)? ";
			int size = inputInt();
			Marble* m = new Marble(color, size);
			cout << "Adding marble of size " << m->getSize() << "mm and color " << m->getColor() << "." << endl;
			bag.addMarble(m);
		}
		else if (choice == 2) // Remove a marble.
		{
			cout << "Removing a marble." << endl;
			cout << "What index do you want to remove? ";
			int index = inputInt();
			bag.removeMarble(index);
		}
		else if (choice == 3) // Print bag contents.
		{
			bag.printContents();
		}
		else if (choice == 4) // Print a specific marble.
		{
			cout << "What marble do you want?" << endl;
			int index = inputInt();
			Marble *m = bag.getMarble(index);
			if (m != nullptr)
			{
				cout << "Marble of size " << m->getSize() << "mm and color " << m->getColor() << "." << endl;
			}
			else
			{
				cout << "Invalid index." << endl;
			}
		}
		else if (choice == 5) // Exit.
		{
			cout << "Goodbye!" << endl;
			return;
		}
		else // Invalid choice.
		{
			cout << "Invalid choice." << endl;
		}
	}
	return;
}