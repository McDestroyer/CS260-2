#include <string>
using namespace std;

class Node
{
public:
	Node* ahead;
	Node* behind;
	string storedData;

	Node(string data, Node* nodeAhead, Node* nodeBehind = nullptr)
	{
		ahead = nodeAhead;
		behind = nodeBehind;
		storedData = data;
	}

	// Getters/Setters:

	Node* getAhead()
	{
		return ahead;
	}

	void setAhead(Node* newAhead)
	{
		ahead = newAhead;
	}

	Node* getBehind()
	{
		return behind;
	}

	void setBehind(Node* newBehind)
	{
		behind = newBehind;
	}

	string getData()
	{
		return storedData;
	}

	// Functions:

	void insertFromFront(string data, int distance = 0)
	{
		if (distance == 0)
		{
			insert(data);
			return;
		}
		behind->insertFromFront(data, distance - 1);
	}

	void insertFromRear(string data, int distance = 0)
	{
		if (distance == 0)
		{
			insert(data);
			return;
		}
		ahead->insertFromRear(data, distance - 1);
	}

	void insert(string data) {
		ahead = new Node(data, ahead, this);

	}

	void removeFromFront(string* ptr, int distance = 0)
	{
		if (distance == 0)
		{
			remove(ptr);
			return;
		}
		behind->removeFromFront(ptr, distance - 1);
	}

	void removeFromRear(string* ptr, int distance = 0)
	{
		if (distance == 0)
		{
			remove(ptr);
			return;
		}
		ahead->removeFromRear(ptr, distance - 1);
	}

	void remove(string* ptr)
	{
		ahead->setBehind(behind);
		behind->setAhead(ahead);
		*ptr = storedData;
		free(this);
	}

	void count(int* ptr)
	{
		*ptr += 1;
		if (behind != nullptr)
		{
			behind->count(ptr);
		}
	}



};


class Queue
{
public:
	int counter = 0;
	Node* front = nullptr;
	Node* rear = nullptr;

	Queue()
	{
		counter = 0;
		front = nullptr;
		rear = nullptr;
	}

	void enqueue(string data)
	{
		Node *newNode = new Node(data, rear);
		rear->setBehind(newNode);
		rear = newNode;
		counter++;
	}

	string dequeue()
	{
		// Make sure it's not empty.
		if (front == nullptr) return NULL;

		// Extract the data and new front.
		string data = front->getData();
		Node* oldFront = front;
		front = oldFront->getBehind();

		// If that was the last node, update rear too.
		if (front == nullptr) rear = nullptr;
		// Otherwise, set the new front to lead nowhere.
		else front->setAhead(nullptr);

		// Get rid of the old node.
		free(oldFront);

		// Decrement the counter.
		counter--;
	}

	string peek()
	{
		// Make sure it's not empty.
		if (front == nullptr) return NULL;

		return front->getData();
	}
};
