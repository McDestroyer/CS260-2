// Path: week_5/queue.hpp
#include <iostream>
#include <string>
using namespace std;

#include "node.hpp"

#pragma once


class Queue
{
public:
	int counter;
	Node* front;
	Node* rear;

	Queue()
	{
		counter = 0;
		front = nullptr;
		rear = nullptr;
	}

	void enqueue(string data)
	{
		Node* newNode = new Node(data, rear);
		if (rear != nullptr)
		{
			rear->setBehind(newNode);
		}
		else
		{
			front = newNode;
		}
		rear = newNode;
		counter++;

	}

	string dequeue()
	{
		// Make sure it's not empty.
		if (front == nullptr) return "Queue is empty.";

		// Extract the data and new front.
		string data = front->getData();
		Node* oldFront = front;
		front = oldFront->getBehind();

		// Get rid of the old node.
		free(oldFront);

		// If that was the last node, update rear too.
		if (front == nullptr) rear = nullptr;
		// Otherwise, set the new front to lead nowhere.
		else front->setAhead(nullptr);

		// Decrement the counter.
		counter--;

		return data;
	}

	void insertFromFront(string data, int distance = 0)
	{
		// If the queue is empty or the distance is the last node, just enqueue.
		if (front == nullptr || distance == counter)
		{
			enqueue(data);
			return;
		}
		// If the distance is 0, insert a new node at the front.
		if (distance == 0)
		{
			Node* newNode = new Node(data, nullptr, front);
			front->setAhead(newNode);
			front = newNode;
			counter++;
			return;
		}
		// Otherwise, start looking for the right spot and insert.
		front->insertFromFront(data, distance - 1);
		counter++;
	}

	void insertFromRear(string data, int distance = 0)
	{
		// If the queue is empty or the distance 0, just enqueue.
		if (rear == nullptr || distance == 0)
		{
			enqueue(data);
			return;
		}
		// If the distance is the last node, insert a new node at the front.
		if (distance == counter)
		{
			Node* newNode = new Node(data, nullptr, front);
			front->setAhead(newNode);
			front = newNode;
			counter++;
			return;
		}
		// Otherwise, start looking for the right spot and insert.
		rear->insertFromRear(data, distance - 1);
		counter++;
	}

	string removeFromFront(int distance = 0)
	{
		// Make sure it's not empty.
		if (front == nullptr) return "Queue is empty.";

		// Make sure the distance is valid.
		if (distance < 0 || distance >= counter) return "Distance is invalid.";

		// If the distance is 0, dequeue.
		if (distance == 0 || front == rear) return dequeue();

		if (distance == counter - 1)
		{
			// Extract the data and new front.
			string data = front->getData();
			Node* oldFront = front;
			front = oldFront->getBehind();

			// Get rid of the old node.
			free(oldFront);

			// If that was the last node, update rear too.
			if (front == nullptr) rear = nullptr;
			// Otherwise, set the new front to lead nowhere.
			else front->setAhead(nullptr);

			// Decrement the counter.
			counter--;

			return data;
		}

		// Otherwise, start looking for the right spot and remove.
		string data;
		front->removeFromFront(&data, distance);
		counter--;

		return data;
	}

	string removeFromRear(int distance = 0)
	{
		// Make sure it's not empty.
		if (front == nullptr) return "Queue is empty.";

		// Make sure the distance is valid.
		if (distance < 0 || distance >= counter) return "Distance is invalid.";

		// If the distance is 0, dequeue.
		if (distance == counter - 1 || front == rear) return dequeue();

		if (distance == 0)
		{
			// Extract the data and new rear.
			string data = rear->getData();
			Node* oldRear = rear;
			rear = oldRear->getAhead();

			// Get rid of the old node.
			free(oldRear);

			// If that was the last node, update front too.
			if (rear == nullptr) front = nullptr;
			// Otherwise, set the new rear to lead nowhere.
			else rear->setBehind(nullptr);

			// Decrement the counter.
			counter--;

			return data;
		}

		// Otherwise, start looking for the right spot and remove.
		string data;
		rear->removeFromRear(&data, distance);
		counter--;

		return data;
	}

	string peek()
	{
		// Make sure it's not empty.
		if (front == nullptr) return "Queue is empty.";

		return front->getData();
	}

	string peekFromFront(int distance = 0)
	{
		// Make sure it's not empty.
		if (front == nullptr) return "Queue is empty.";

		// Make sure the distance is valid.
		if (distance >= counter || distance < 0) return "Distance is invalid.";

		if (distance == 0) return front->getData();

		// Start looking for the right spot and peek.
		Node* ptr = front;
		for (int i = 0; i < distance; i++) ptr = ptr->getBehind();

		return ptr->getData();
	}

	string peekFromRear(int distance = 0)
	{
		// Make sure it's not empty.
		if (front == nullptr) return "Queue is empty.";

		// Make sure the distance is valid.
		if (distance >= counter || distance < 0) return "Distance is invalid.";

		if (distance == 0) return rear->getData();

		// Start looking for the right spot and peek.
		Node* ptr = rear;
		for (int i = 0; i < distance; i++) ptr = ptr->getAhead();

		return ptr->getData();
	}

	string list()
	{
		string list = "[";
		for (Node* ptr = front; ptr != nullptr; ptr = ptr->getBehind())
		{
			list += ptr->getData() + ", ";
		}
		return list.substr(0, list.size()-2) + "]";
	}

	void sort()
	{
		if (front != nullptr)
		{
			// Traverse the list.
			for (Node* ptr = front; ptr->getBehind() != nullptr; ptr = ptr->getBehind())
			{
				// Compare the current node with the rest of the list.
				for (Node* ptr2 = ptr->getBehind(); ptr2 != nullptr; ptr2 = ptr2->getBehind())
				{
					// Swap if the current node is greater than the next node.
					if (ptr->getData() > ptr2->getData())
					{
						string temp = ptr->getData();
						ptr->setData(ptr2->getData());
						ptr2->setData(temp);
					}
				}
			}
		}
	}

	void insertSorted(string data)
	{
		// If the queue is empty, just enqueue.
		if (front == nullptr)
		{
			enqueue(data);
			return;
		}

		// Traverse the list.
		for (Node* ptr = front; ptr != nullptr; ptr = ptr->getBehind())
		{
			// If the current node is greater than the data, insert the data before the current node.
			if (ptr->getData() > data)
			{
				if (ptr == front)
				{
					insertFromFront(data);
					counter++;
					return;
				}
				ptr->insertAhead(data);
				counter++;
				return;
			}
		}

		// If the data is greater than all the nodes, insert the data at the end.
		enqueue(data);
	}

	string removeByName(string data)
	{
		// Make sure it's not empty.
		if (front == nullptr) return "Queue is empty.";

		// If the data is at the front, dequeue.
		if (front->getData() == data) return dequeue();

		// Traverse the list.
		for (Node* ptr = front; ptr != nullptr; ptr = ptr->getBehind())
		{
			// If the data is found, remove it.
			if (ptr->getData() == data)
			{
				string removedData = "";
				ptr->remove(&removedData);

				counter--;
				return removedData;
			}
		}

		return data + " not found.";
	}

	int getIndexOf(string data)
	{
		// Make sure it's not empty.
		if (front == nullptr) return -1;

		// Traverse the list.
		int index = 0;
		for (Node* ptr = front; ptr != nullptr; ptr = ptr->getBehind())
		{
			// If the data is found, return the index.
			if (ptr->getData() == data) return index;
			index++;
		}

		return -1;
	}

	int count()
	{
		int num = 0;

		if (front != nullptr) front->count(&num);
		counter = num;

		return num;
	}

	void clear()
	{
		while (front != nullptr)
		{
			dequeue();
		}
	}

	~Queue()
	{
		while (front != nullptr)
		{
			dequeue();
		}
	}
};