#include <iostream>
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

	void setData(string newData)
	{
		storedData = newData;
	}

	// Functions:

	void insertFromFront(string data, int distance = 0)
	{
		if (distance == 0)
		{
			insertBehind(data);
			return;
		}
		behind->insertFromFront(data, distance - 1);
	}

	void insertFromRear(string data, int distance = 0)
	{
		if (distance == 0)
		{
			insertAhead(data);
			return;
		}
		ahead->insertFromRear(data, distance - 1);
	}

	void insertAhead(string data) {
		ahead = new Node(data, ahead, this);
		if (ahead->getAhead() != nullptr) ahead->getAhead()->setBehind(ahead);
	}

	void insertBehind(string data)
	{
		behind = new Node(data, this, behind);
		if (behind->getBehind() != nullptr) behind->getBehind()->setAhead(behind);
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
		if (ahead != nullptr) ahead->setBehind(behind);
		if (behind != nullptr) behind->setAhead(ahead);
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