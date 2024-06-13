#include <iostream>
#include <string>
using namespace std;

#include "queue.hpp"


class QueueQueueNode
{
public:
	string name;
	QueueQueueNode* ahead;
	QueueQueueNode* behind;
	Queue* storedData;

	QueueQueueNode(string key, Queue* data, QueueQueueNode* nodeAhead, QueueQueueNode* nodeBehind = nullptr)
	{
		ahead = nodeAhead;
		behind = nodeBehind;
		storedData = data;
		name = key;
	}

	// Getters/Setters:

	QueueQueueNode* getAhead()
	{
		return ahead;
	}

	void setAhead(QueueQueueNode* newAhead)
	{
		ahead = newAhead;
	}

	QueueQueueNode* getBehind()
	{
		return behind;
	}

	void setBehind(QueueQueueNode* newBehind)
	{
		behind = newBehind;
	}

	Queue* getData()
	{
		return storedData;
	}

	void setData(Queue* newData)
	{
		storedData = newData;
	}

	// Functions:

	void insertFromFront(string name, Queue* data, int distance = 0)
	{
		if (distance == 0)
		{
			insertBehind(name, data);
			return;
		}
		behind->insertFromFront(name, data, distance - 1);
	}

	void insertFromRear(string name, Queue* data, int distance = 0)
	{
		if (distance == 0)
		{
			insertAhead(name, data);
			return;
		}
		ahead->insertFromRear(name, data, distance - 1);
	}

	void insertAhead(string name, Queue* data) {
		ahead = new QueueQueueNode(name, data, ahead, this);
		if (ahead->getAhead() != nullptr) ahead->getAhead()->setBehind(ahead);
	}

	void insertBehind(string name, Queue* data)
	{
		behind = new QueueQueueNode(name, data, this, behind);
		if (behind->getBehind() != nullptr) behind->getBehind()->setAhead(behind);
	}

	void removeFromFront(Queue** ptr, int distance = 0)
	{
		if (distance == 0)
		{
			remove(ptr);
			return;
		}
		behind->removeFromFront(ptr, distance - 1);
	}

	void removeFromRear(Queue** ptr, int distance = 0)
	{
		if (distance == 0)
		{
			remove(ptr);
			return;
		}
		ahead->removeFromRear(ptr, distance - 1);
	}

	void remove(Queue** ptr)
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

	string getKey()
	{
		return name;
	}

	void setKey(string newKey)
	{
		name = newKey;
	}

};