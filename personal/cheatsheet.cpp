// Date: 2021/09/26
// Author: God
// Purpose: A cheatsheet for C++.
// Description: A cheatsheet for C++.
// Compilation: g++ cheatsheet.cpp -o cheatsheet
// Execution: ./cheatsheet
// Notes:
// - You can't overwrite array vars, but you can overwrite array elements.
// - Strings, however, can be overwritten.
// - You can't use the 'new' keyword to create an array of strings.

#include <iostream>

// This is used to avoid having to write 'std::' before every standard library function.
using namespace std;

// You can't overwrite array vars, but you can overwrite array elements.
// Strings, however, can be overwritten.


// * and & meanings and uses with examples:
// * is used to declare a pointer.
// & is used to get the address of a variable.
// This is useful for passing by reference and for pointers.
int p = 0;
int *p = &p;

// The 'new' keyword is used to dynamically allocate memory.
// This is useful for creating objects that need to be created at runtime.
// This is also useful for creating arrays of objects.
// When you use 'new', you need to use 'delete' to free the memory.
// This means the variable will be permanently stored in memory until removed.
int *n = new int(5);

// & is also used to pass by reference. This means if you modify the variable
// in the function, it will be modified outside the function as well.
// This is more efficient than passing by value as it doesn't create a copy.
// If you don't include the & in the function definition, it will pass by value.
// This means the variable will be copied and modified in the function, but the
// original variable will remain unchanged.
void foo(int& n)
{
	n = 5;
}
// The 'const' keyword is used to make sure the variable isn't modified.
// This is a good practice as it prevents accidental modification.
void foo(const int& n)
{
	cout << n << endl;
}

// & is also used in function definitions to return a reference.
// This is useful for returning an object that is created in the function.
// Example:
int& foo()
{
	int n = 5;
	return n;
}

// The 'static' keyword is used to make a variable or function global.
// This means it can be accessed from any function in the file.
// This is useful for variables that need to be accessed by multiple functions.
// This is also useful for functions that need to be called from multiple functions.
// This is also useful for variables that need to be initialized only once.
static int n = 5;

// The 'extern' keyword is used to declare a variable that is defined in another file.
// This is useful for sharing variables between files.
// This is also useful for sharing functions between files.
// This is also useful for sharing classes between files.
// This can be done by declaring the variable in one file and defining it in another.
// Example:
// File 1:
// extern int n;
// File 2:
// int n = 5;

// The 'inline' keyword is used to define a function that is expanded in place.
// This means the function is copied into the code where it is called.
// This is useful for small functions that are called frequently.
// This is also useful for functions that are called from multiple places.
// This is also useful for functions that are called from multiple files.
// This is also useful for functions that are called from multiple classes.
// This is also useful for functions that are called from multiple objects.
// This is also useful for functions that are called from multiple threads.
// This is also useful for functions that are called from multiple processes.
// This is also useful for functions that are called from multiple programs.
// This is also useful for functions that are called from multiple languages.
// This is also useful for functions that are called from multiple platforms.
// This is also useful for functions that are called from multiple devices.
// This is also useful for functions that are called from multiple networks.
// This is also useful for functions that are called from multiple servers.
// This is also useful for functions that are called from multiple clients.
// This is also useful for functions that are called from multiple users.
// This is also useful for functions that are called from multiple groups.
// This is also useful for functions that are called from multiple organizations.
// This is also useful for functions that are called from multiple companies.
// This is also useful for functions that are called from multiple industries.
// This is also useful for functions that are called from multiple sectors.
// This is also useful for functions that are called from multiple fields.
// This is also useful for functions that are called from multiple disciplines.
// This is also useful for functions that are called from multiple departments.
// This is also useful for functions that are called from multiple divisions.
// This is also useful for functions that are called from multiple branches.
// This is also useful for functions that are called from multiple regions.
// This is also useful for functions that are called from multiple countries.
// This is also useful for functions that are called from multiple continents.
// This is also useful for functions that are called from multiple planets.
// This is also useful for functions that are called from multiple galaxies.
// This is also useful for functions that are called from multiple universes.
// This is also useful for functions that are called from multiple dimensions.
// This is also useful for functions that are called from multiple realities.
// This is also useful for functions that are called from multiple simulations.
// This is also useful for functions that are called from multiple games.
// This is also useful for functions that are called from multiple movies.
// This is also useful for functions that are called from multiple shows.
// This is also useful for functions that are called from multiple books.
// This is also useful for functions that are called from multiple comics.
// This is also useful for functions that are called from multiple magazines.
// This is also useful for functions that are called from multiple newspapers.
// This is also useful for functions that are called from multiple articles.
// This is also useful for functions that are called from multiple essays.
// This is also useful for functions that are called from multiple reports.
// This is also useful for functions that are called from multiple documents.
// This is also useful for functions that are called from multiple files.
// This is also useful for functions that are called from multiple folders.
// This is also useful for functions that are called from multiple directories.
// This is also useful for functions that are called from multiple drives.
// This is also useful for functions that are called from multiple disks.
// This is also useful for functions that are called from multiple volumes.
// This is also useful for functions that are called from multiple partitions.
// This is also useful for functions that are called from multiple sectors.
// This is also useful for functions that are called from multiple clusters.
// This is also useful for functions that are called from multiple blocks.
// This is also useful for functions that are called from multiple nodes.
// This is also useful for functions that are called from multiple edges.
// This is also useful for functions that are called from multiple vertices.
// This is also useful for functions that are called from multiple faces.
// This is also useful for functions that are called from multiple shapes.
// This is also useful for functions that are called from multiple sizes.
// This is also useful for functions that are called from multiple colors.
// This is also useful for functions that are called from multiple textures.
// This is also useful for functions that are called from multiple patterns.
// This is also useful for functions that are called from multiple designs.
// This is also useful for functions that are called from multiple styles.
// This is also useful for functions that are called from multiple themes.
// This is also useful for functions that are called from multiple concepts.
// This is also useful for functions that are called from multiple ideas.
// This is also useful for functions that are called from multiple thoughts.
// This is also useful for functions that are called from multiple feelings.
// This is also useful for functions that are called from multiple emotions.
// This is also useful for functions that are called from multiple senses.
// This is also useful for functions that are called from multiple perceptions.
// This is also useful for functions that are called from multiple perspectives.
// This is also useful for functions that are called from multiple viewpoints.
// This is also useful for functions that are called from multiple angles.
// This is also useful for functions that are called from multiple directions.
// This is also useful for functions that are called from multiple locations.
// This is also useful for functions that are called from multiple positions.
// This is also useful for functions that are called from multiple places.
// This is also useful for functions that are called from multiple spaces.
// This is also useful for functions that are called from multiple areas.
// This is also useful for functions that are called from multiple regions.
// This is also useful for functions that are called from multiple territories.
// This is also useful for functions that are called from multiple countries.
// This is also useful for functions that are called from multiple continents.
// This is also useful for functions that are called from multiple planets.
// This is also useful for functions that are called from multiple galaxies.
// This is also useful for functions that are called from multiple universes.
// This is also useful for functions that are called from multiple dimensions.
// This is also useful for functions that are called from multiple realities.
// This is also useful for functions that are called from multiple simulations.
// This is also useful for functions that are called from multiple games.
// This is also useful for functions that are called from multiple movies.
// ...
// Example:
inline int foo()
{
	return 5;
}



// Class stuff below:


// Classes and structs are similar, but classes are private by default
// and structs are public.
class Marble
{
	// Everything is private by default.
	// This is a good practice as it prevents accidental external modification.
	// Don't initialize variables here. Initialize them in the constructor.
	private:
		string color;
		int size;

	public:
		/*
		* This is a default constructor.
		* It is called when an object is created without any arguments.
		* It is used to initialize the object.
		* It is not necessary to define it, but it is good practice.
		*/
		Marble()
		{
			color = "red";
			size = 10;
		}

		/* Main constructor for the Marble class.
		* The & is used to pass by reference rather than passing the actual object.
		* The reference is a pointer to the object.
		* This is more efficient as it doesn't create a copy of the object.
		* The 'const' keyword is used to make sure the object isn't modified.
		* This is a good practice as it prevents accidental modification.
		*/
		Marble(const string& color, const int& size)
		{
			/* 'this' is a pointer to the object.
			* '->' is used to access members of a pointer.
			* Together, 'this->' is the equivalent of '.self' in Python.
			* 
			* This is used to differentiate between local and member variables
			* if they have the same names.
			*/
			this->color = color;
			this->size = size;
		}
};

// Calls the default constructor.
Marble m1;
// Calls the main constructor.
Marble m2("blue", 20);
// Calls the main constructor and makes m3 a pointer.
// Use this because the object doesn't get destroyed when it goes out of scope.
Marble *m3 = new Marble("green", 30); 


// Personal functions below:


/**
* Function to get an integer from the user.
* This function will keep asking for an integer until a valid one is entered.
*
* @return The integer entered by the user.
*/
static int intput()
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