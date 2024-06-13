// Path: week_7/queuequeue.hpp
#include <iostream>
#include <string>
using namespace std;

#include "queuequeuenode.hpp"
#include "queue.hpp"


class QueueQueue
{
public:
	int counter;
	QueueQueueNode* front;
	QueueQueueNode* rear;

	QueueQueue()
	{
		counter = 0;
		front = nullptr;
		rear = nullptr;
	}

	void enqueue(string key, Queue *data)
	{
		QueueQueueNode* newQueueQueueNode = new QueueQueueNode(key, data, rear);
		if (rear != nullptr)
		{
			rear->setBehind(newQueueQueueNode);
		}
		else
		{
			front = newQueueQueueNode;
		}
		rear = newQueueQueueNode;
		counter++;

	}

	Queue *dequeue()
	{
		// Make sure it's not empty.
		if (front == nullptr) return (new Queue());

		// Extract the data and new front.
		Queue *data = front->getData();
		QueueQueueNode* oldFront = front;
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

	void insertFromFront(string key, Queue *data, int distance = 0)
	{
		// If the queue is empty or the distance is the last node, just enqueue.
		if (front == nullptr || distance == counter)
		{
			enqueue(key, data);
			return;
		}
		// If the distance is 0, insert a new node at the front.
		if (distance == 0)
		{
			QueueQueueNode* newQueueQueueNode = new QueueQueueNode(key, data, nullptr, front);
			front->setAhead(newQueueQueueNode);
			front = newQueueQueueNode;
			counter++;
			return;
		}
		// Otherwise, start looking for the right spot and insert.
		front->insertFromFront(key, data, distance - 1);
		counter++;
	}

	void insertFromRear(string key, Queue *data, int distance = 0)
	{
		// If the queue is empty or the distance 0, just enqueue.
		if (rear == nullptr || distance == 0)
		{
			enqueue(key, data);
			return;
		}
		// If the distance is the last node, insert a new node at the front.
		if (distance == counter)
		{
			QueueQueueNode* newQueueQueueNode = new QueueQueueNode(key, data, nullptr, front);
			front->setAhead(newQueueQueueNode);
			front = newQueueQueueNode;
			counter++;
			return;
		}
		// Otherwise, start looking for the right spot and insert.
		rear->insertFromRear(key, data, distance - 1);
		counter++;
	}

	Queue *removeFromFront(int distance = 0)
	{
		// Make sure it's not empty.
		if (front == nullptr) throw "Queue is empty!";

		// Make sure the distance is valid.
		if (distance < 0 || distance >= counter) throw "Distance is invalid.";

		// If the distance is 0, dequeue.
		if (distance == 0 || front == rear) return dequeue();

		if (distance == counter - 1)
		{
			// Extract the data and new front.
			Queue *data = front->getData();
			QueueQueueNode* oldFront = front;
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
		Queue *data;
		front->removeFromFront(&data, distance);
		counter--;

		return data;
	}

	Queue *removeFromRear(int distance = 0)
	{
		// Make sure it's not empty.
		if (front == nullptr) throw "Queue is empty!";

		// Make sure the distance is valid.
		if (distance < 0 || distance >= counter) throw "Distance is invalid.";

		// If the distance is 0, dequeue.
		if (distance == counter - 1 || front == rear) return dequeue();

		if (distance == 0)
		{
			// Extract the data and new rear.
			Queue *data = rear->getData();
			QueueQueueNode* oldRear = rear;
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
		Queue *data;
		rear->removeFromRear(&data, distance);
		counter--;

		return data;
	}

	Queue *peek()
	{
		// Make sure it's not empty.
		if (front == nullptr) throw "Queue is empty!";

		return front->getData();
	}

	Queue *peekFromFront(int distance = 0)
	{
		// Make sure it's not empty.
		if (front == nullptr) throw "Queue is empty!";

		// Make sure the distance is valid.
		if (distance >= counter || distance < 0) throw "Distance is invalid.";

		if (distance == 0) return front->getData();

		// Start looking for the right spot and peek.
		QueueQueueNode* ptr = front;
		for (int i = 0; i < distance; i++) ptr = ptr->getBehind();

		return ptr->getData();
	}

	Queue *peekFromRear(int distance = 0)
	{
		// Make sure it's not empty.
		if (front == nullptr) throw "Queue is empty!";

		// Make sure the distance is valid.
		if (distance >= counter || distance < 0) throw "Distance is invalid.";

		if (distance == 0) return rear->getData();

		// Start looking for the right spot and peek.
		QueueQueueNode* ptr = rear;
		for (int i = 0; i < distance; i++) ptr = ptr->getAhead();

		return ptr->getData();
	}

	string list()
	{
		string list = "[";
		for (QueueQueueNode* ptr = front; ptr != nullptr; ptr = ptr->getBehind())
		{
			list += ptr->getKey() + ", ";
		}
		return list.substr(0, list.size() - 2) + "]";
	}

	//void sort()
	//{
	//	if (front != nullptr)
	//	{
	//		// Traverse the list.
	//		for (QueueQueueNode* ptr = front; ptr->getBehind() != nullptr; ptr = ptr->getBehind())
	//		{
	//			// Compare the current node with the rest of the list.
	//			for (QueueQueueNode* ptr2 = ptr->getBehind(); ptr2 != nullptr; ptr2 = ptr2->getBehind())
	//			{
	//				// Swap if the current node is greater than the next node.
	//				if (ptr->getKey() > ptr2->getKey())
	//				{
	//					string temp = ptr->getKey();
	//					ptr->setKey(ptr2->getKey());
	//					ptr2->setKey(temp);

	//					Queue *temp2 = ptr->getData();
	//					ptr->setData(ptr2->getData());
	//					ptr2->setData(temp2);
	//				}
	//			}
	//		}
	//	}
	//}

	//void insertSorted(string data)
	//{
	//	// If the queue is empty, just enqueue.
	//	if (front == nullptr)
	//	{
	//		enqueue(data);
	//		return;
	//	}

	//	// Traverse the list.
	//	for (QueueQueueNode* ptr = front; ptr != nullptr; ptr = ptr->getBehind())
	//	{
	//		// If the current node is greater than the data, insert the data before the current node.
	//		if (ptr->getData() > data)
	//		{
	//			if (ptr == front)
	//			{
	//				insertFromFront(data);
	//				counter++;
	//				return;
	//			}
	//			ptr->insertAhead(data);
	//			counter++;
	//			return;
	//		}
	//	}

	//	// If the data is greater than all the nodes, insert the data at the end.
	//	enqueue(data);
	//}

	Queue *removeByKey(string key)
	{
		// Make sure it's not empty.
		if (front == nullptr) return NULL;

		// If the key is at the front, dequeue.
		if (front->getKey() == key) return dequeue();

		// Traverse the list.
		for (QueueQueueNode* ptr = front; ptr != nullptr; ptr = ptr->getBehind())
		{
			// If the key is found, remove it.
			if (ptr->getKey() == key)
			{
				Queue *removedData;
				ptr->remove(&removedData);

				counter--;
				return removedData;
			}
		}

		return NULL;
	}

	Queue *peekByKey(string key)
	{
		// Make sure it's not empty.
		if (front == nullptr) return NULL;

		// Traverse the list.
		for (QueueQueueNode* ptr = front; ptr != nullptr; ptr = ptr->getBehind())
		{
			// If the key is found, return the data.
			if (ptr->getKey() == key) return ptr->getData();
		}

		// If the key is not found, return NULL.
		return NULL;
	}

	int getIndexOf(string key)
	{
		// Make sure it's not empty.
		if (front == nullptr) return -1;

		// Traverse the list.
		int index = 0;
		for (QueueQueueNode* ptr = front; ptr != nullptr; ptr = ptr->getBehind())
		{
			// If the key is found, return the index.
			if (ptr->getKey() == key) return index;
			index++;
		}

		return -1;
	}

	void add(string key, string data, bool replace = true)
	{
		Queue* queue;
		
		try
		{
			queue = peekByKey(key);
			if (queue == NULL)
			{
				enqueue(key, new Queue());
				queue = peekByKey(key);
			}
		}
		catch ( ... )
		{
			enqueue(key, new Queue());
			queue = peekByKey(key);
		}

		if (replace)
		{
			queue->clear();
		}

		queue->enqueue(data);



		/*try
		{
			if (replace)
			{
				try {
					peekByKey(key)->clear();
				}
				catch ( ... )
				{
					enqueue(key, new Queue());
				}
			}
			peekByKey(key)->enqueue(data);
		}
		catch ( ... )
		{
			enqueue(key, new Queue());
			cout << "Adding " << data << " to " << key << endl;
			if (replace)
			{
				peekByKey(key)->clear();
			}
			enqueue(key, new Queue());
			peekByKey(key)->enqueue(data);
		}*/
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

	~QueueQueue()
	{
		while (front != nullptr)
		{
			dequeue();
		}
	}
};