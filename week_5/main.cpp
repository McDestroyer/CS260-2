
#include <string>
#include <iostream>
using namespace std;

#include "queue.hpp"


int main()
{
	Queue *queue = new Queue();

	// Test the queue for Assignment 5.

	// Add some data to the queue.
	// This is a list of NATO phonetic alphabet words.
	queue->enqueue("Zulu");
	queue->enqueue("Delta");
	queue->enqueue("Romeo");
	queue->enqueue("Victor");
	queue->enqueue("Foxtrot");
	queue->enqueue("Golf");
	queue->enqueue("Whiskey");
	queue->enqueue("Yankee");
	queue->enqueue("Quebec");
	queue->enqueue("India");
	queue->enqueue("Juliet");
	queue->enqueue("Kilo");
	queue->enqueue("Lima");
	queue->enqueue("November");
	queue->enqueue("Oscar");
	queue->enqueue("Papa");
	queue->enqueue("Echo");
	queue->enqueue("Alpha");
	queue->enqueue("Bravo");
	queue->enqueue("Charlie");
	queue->enqueue("Sierra");
	queue->enqueue("Tango");
	queue->enqueue("Uniform");
	queue->enqueue("Hotel");
	queue->enqueue("X-Ray");
	queue->enqueue("Mike");

	// Add some more items: greek letters.
	queue->enqueue("Nu");
	queue->enqueue("Xi");
	queue->enqueue("Omicron");
	queue->enqueue("Iota");
	queue->enqueue("Gamma");
	queue->enqueue("Zeta");
	queue->enqueue("Lambda");
	queue->enqueue("Pi");
	queue->enqueue("Chi");
	queue->enqueue("Psi");
	queue->enqueue("Omega");
	queue->enqueue("Sigma");
	queue->enqueue("Tau");
	queue->enqueue("Theta");
	queue->enqueue("Upsilon");
	queue->enqueue("Phi");
	queue->enqueue("Eta");
	queue->enqueue("Beta");
	queue->enqueue("Kappa");
	queue->enqueue("Epsilon");
	queue->enqueue("Mu");
	queue->enqueue("Rho");

	// Display the unsorted list.
	cout << queue->list() << endl << endl;
	
	// Sort the list.
	queue->sort();

	// Display the sorted list.
	cout << queue->list() << endl << endl;

	// Insert a new item.
	queue->insertSorted("Aaa");
	queue->insertSorted("Bbb");
	queue->insertSorted("Zzz");
	queue->insertSorted("Yyy");
	queue->insertSorted("Mmm");
	queue->insertSorted("Alpha");
	queue->insertSorted("Delta");

	// Display the sorted list.
	cout << queue->list() << endl << endl;

	// Clear the list.
	queue->clear();

	// Display the list.
	cout << queue->list() << endl << endl;

	// Insert a new item to the empty list.
	queue->insertSorted("Aaa");
	queue->insertSorted("Bbb");
	queue->insertSorted("zzz");
	queue->insertSorted("Yyy");
	queue->insertSorted("Mmm");
	queue->insertSorted("Alpha");
	queue->insertSorted("Delta");

	// Display the sorted list.
	cout << queue->list() << endl << endl;

	// Remove a few items.
	cout << queue->getIndexOf("Aaa") << endl;
	cout << queue->removeByName("Aaa") << endl;
	cout << queue->getIndexOf("zzz") << endl;
	cout << queue->removeByName("zzz") << endl;
	cout << queue->getIndexOf("Delta") << endl;
	cout << queue->removeByName("Delta") << endl;
	cout << queue->getIndexOf("Aaa") << endl;
	cout << queue->removeByName("Aaa") << endl;

	// Display the sorted list.
	cout << queue->list() << endl << endl;


	// :)
	cout << "Program complete! :)" << endl;
	return 0;
}