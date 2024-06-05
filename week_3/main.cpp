
#include <string>
#include <iostream>
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

class Queue
{
public:
	int counter;
	Node *front;
	Node *rear;

	Queue()
	{
		counter = 0;
		front = nullptr;
		rear = nullptr;
	}

	void enqueue(string data)
	{
		Node *newNode = new Node(data, rear);
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

		cout << "##########################" << endl;
		cout << "Added a node: " << data << endl;
		cout << "Front is now: " << front->getData() << endl;
		cout << "Rear is now: " << rear->getData() << endl;
		if (front->getBehind() != nullptr) cout << "Front's behind is now: " << front->getBehind()->getData() << endl;
		cout << "##########################" << endl;

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

		cout << "##########################" << endl;
		cout << "Removed a node: " << data << endl;
		if (front != nullptr) cout << "Front is now: " << front->getData() << endl;
		else cout << "Queue is now empty." << endl;
		if (rear != nullptr) cout << "Rear is now: " << rear->getData() << endl;
		if (front != nullptr && front->getBehind() != nullptr) cout << "Front's behind is now: " << front->getBehind()->getData() << endl;
		cout << "##########################" << endl;

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
		front->insertFromFront(data, distance-1);
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
		rear->insertFromRear(data, distance-1);
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

			cout << "##########################" << endl;
			cout << "Removed a node: " << data << endl;
			if (front != nullptr) cout << "Front is now: " << front->getData() << endl;
			else cout << "Queue is now empty." << endl;
			if (rear != nullptr) cout << "Rear is now: " << rear->getData() << endl;
			if (front != nullptr && front->getBehind() != nullptr) cout << "Front's behind is now: " << front->getBehind()->getData() << endl;
			cout << "##########################" << endl;

			return data;
		}

		// Otherwise, start looking for the right spot and remove.
		string data;
		front->removeFromFront(&data, distance);
		counter--;

		cout << "##########################" << endl;
		cout << "Removed a node: " << data << endl;
		if (front != nullptr) cout << "Front is now: " << front->getData() << endl;
		else cout << "Queue is now empty." << endl;
		if (rear != nullptr) cout << "Rear is now: " << rear->getData() << endl;
		if (front != nullptr && front->getBehind() != nullptr) cout << "Front's behind is now: " << front->getBehind()->getData() << endl;
		cout << "##########################" << endl;

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

			cout << "##########################" << endl;
			cout << "Removed a node: " << data << endl;
			if (front != nullptr) cout << "Front is now: " << front->getData() << endl;
			else cout << "Queue is now empty." << endl;
			if (rear != nullptr) cout << "Rear is now: " << rear->getData() << endl;
			if (front != nullptr && front->getBehind() != nullptr) cout << "Front's behind is now: " << front->getBehind()->getData() << endl;
			cout << "##########################" << endl;

			return data;
		}

		// Otherwise, start looking for the right spot and remove.
		string data;
		rear->removeFromRear(&data, distance);
		counter--;

		cout << "##########################" << endl;
		cout << "Removed a node: " << data << endl;
		if (front != nullptr) cout << "Front is now: " << front->getData() << endl;
		else cout << "Queue is now empty." << endl;
		if (rear != nullptr) cout << "Rear is now: " << rear->getData() << endl;
		if (front != nullptr && front->getBehind() != nullptr) cout << "Front's behind is now: " << front->getBehind()->getData() << endl;
		cout << "##########################" << endl;

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


int main()
{
	Queue *queue = new Queue();

	// Test the queue for Assignment 3.
	queue->enqueue("Item 1");
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 1." << endl;
	cout << endl;
	queue->enqueue("Item 2");
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 2." << endl;
	cout << endl;
	queue->enqueue("Item 3");
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 3." << endl;
	cout << endl;

	cout << "Peek 1: " << queue->peek() << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;

	cout << "Peek 2: " << queue->peek() << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Dequeue 1: " << endl << queue->dequeue() << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 2." << endl;
	cout << endl;
	cout << "Peek 3: " << queue->peek() << endl;
	cout << "Should return Item 2." << endl;
	cout << endl;
	cout << "Dequeue 2: " << endl << queue->dequeue() << endl;
	cout << "Should return Item 2." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 1." << endl;
	cout << endl;
	cout << "Dequeue 3: " << endl << queue->dequeue() << endl;
	cout << "Should return Item 3." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 0." << endl;
	cout << endl;
	cout << "Dequeue 4: " << endl << queue->dequeue() << endl;
	cout << "Should return 'Queue is empty.'" << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 0." << endl;
	cout << endl;
	cout << "Peek 4: " << queue->peek() << endl;
	cout << "Should return 'Queue is empty.'" << endl;
	cout << endl;

	queue->enqueue("Item 0");
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 1." << endl;
	cout << endl;
	cout << "Peek 5: " << queue->peek() << endl;
	cout << "Should return Item 0." << endl;
	cout << endl;
	cout << "Clearing the queue." << endl;
	queue->clear();
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 0." << endl;
	cout << "Peek 6: " << queue->peek() << endl;
	cout << "Should return 'Queue is empty.'" << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;

	// Test the queue for Assignment 4.
	queue->enqueue("Item 1");
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 1." << endl;
	cout << endl;
	cout << "Peek 7: " << queue->peek() << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;

	cout << "Insert 1" << endl;
	queue->insertFromFront("Item 2", 0);
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 2." << endl;
	cout << endl;
	cout << "Peek 8: " << queue->peek() << endl;
	cout << "Should return Item 2." << endl;
	cout << endl;

	cout << "Insert 2" << endl;
	queue->insertFromFront("Item 3", 1);
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 3." << endl;
	cout << endl;
	cout << "Peek 9: " << queue->peek() << endl;
	cout << "Should return Item 2." << endl;
	cout << endl;

	cout << "Insert 3" << endl;
	queue->insertFromRear("Item 4", 1);
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 4." << endl;
	cout << endl;
	cout << "Peek 10: " << queue->peek() << endl;
	cout << "Should return Item 2." << endl;
	cout << endl;
	cout << "Peek Rear 1: " << queue->peekFromRear(0) << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Peek Rear 2: " << queue->peekFromRear(1) << endl;
	cout << "Should return Item 4." << endl;
	cout << endl;
	cout << "Peek Rear 3: " << queue->peekFromRear(2) << endl;
	cout << "Should return Item 3." << endl;
	cout << endl;
	cout << "Peek Rear 4: " << queue->peekFromRear(3) << endl;
	cout << "Should return Item 2." << endl;
	cout << endl;

	cout << "Dequeue 1: " << endl << queue->dequeue() << endl;
	cout << "Should return Item 2." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 3." << endl;
	cout << endl;
	cout << "Peek 11: " << queue->peek() << endl;
	cout << "Should return Item 3." << endl;
	cout << endl;
	cout << "Peek Rear 5: " << queue->peekFromRear(0) << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Peek Rear 6: " << queue->peekFromRear(1) << endl;
	cout << "Should return Item 4." << endl;
	cout << endl;
	cout << "Peek Rear 7: " << queue->peekFromRear(2) << endl;
	cout << "Should return Item 3." << endl;
	cout << endl;
	cout << "Peek Rear 8: " << queue->peekFromRear(3) << endl;
	cout << "Should return 'Distance is invalid.'" << endl;
	cout << endl;
	cout << "Peek Front 1: " << queue->peekFromFront(0) << endl;
	cout << "Should return Item 3." << endl;
	cout << endl;
	cout << "Peek Front 2: " << queue->peekFromFront(1) << endl;
	cout << "Should return Item 4." << endl;
	cout << endl;
	cout << "Peek Front 3: " << queue->peekFromFront(2) << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Peek Front 4: " << queue->peekFromFront(3) << endl;
	cout << "Should return 'Distance is invalid.'" << endl;
	cout << endl;

	cout << "Dequeue 2: " << endl << queue->dequeue() << endl;
	cout << "Should return Item 3." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 2." << endl;
	cout << endl;
	cout << "Peek 12: " << queue->peek() << endl;
	cout << "Should return Item 4." << endl;
	cout << endl;

	queue->enqueue("Item 5");
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 3." << endl;
	cout << endl;
	cout << "Peek 13: " << queue->peek() << endl;
	cout << "Should return Item 4." << endl;
	cout << endl;

	queue->enqueue("Item 6");
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 4." << endl;
	cout << endl;
	cout << "Peek 14: " << queue->peek() << endl;
	cout << "Should return Item 4." << endl;
	cout << endl;

	cout << "Peek Front 5: " << queue->peekFromFront(0) << endl;
	cout << "Should return Item 4." << endl;
	cout << endl;
	cout << "Peek Front 6: " << queue->peekFromFront(1) << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Peek Front 7: " << queue->peekFromFront(2) << endl;
	cout << "Should return Item 5." << endl;
	cout << endl;
	cout << "Peek Front 8: " << queue->peekFromFront(3) << endl;
	cout << "Should return Item 6." << endl;
	cout << endl;
	cout << "Peek Front 9: " << queue->peekFromFront(4) << endl;
	cout << "Should return 'Distance is invalid.'" << endl;
	cout << endl;
	cout << "Peek Front 10: " << queue->peekFromFront(5) << endl;
	cout << "Should return 'Distance is invalid.'" << endl;
	cout << endl;

	cout << "Remove from front (0) 1: " << endl << queue->removeFromFront(0) << endl;
	cout << "Should return Item 4." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 3." << endl;
	cout << endl;
	cout << "Peek 15: " << queue->peek() << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;

	cout << "Remove from front (1) 2: " << endl << queue->removeFromFront(1) << endl;
	cout << "Should return Item 5." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 2." << endl;
	cout << endl;
	cout << "Peek 16: " << queue->peek() << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Peek Rear 9: " << queue->peekFromRear(0) << endl;
	cout << "Should return Item 6." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 2." << endl;
	cout << endl;
	cout << "Remove from rear (0) 3: " << endl << queue->removeFromRear(0) << endl;
	cout << "Should return Item 6." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 1." << endl;
	cout << endl;
	cout << "Peek 17: " << queue->peek() << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Peek Rear 10: " << queue->peekFromRear(0) << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Remove from rear (1) 4: " << endl << queue->removeFromRear(1) << endl;
	cout << "Should return 'Distance is invalid.'" << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 1." << endl;
	cout << endl;
	cout << "Peek 18: " << queue->peek() << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Peek Rear 11: " << queue->peekFromRear(0) << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Remove from rear (0) 5: " << endl << queue->removeFromRear(0) << endl;
	cout << "Should return Item 1." << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 0." << endl;
	cout << endl;
	cout << "Peek 19: " << queue->peek() << endl;
	cout << "Should return 'Queue is empty.'" << endl;
	cout << endl;
	cout << "Peek Rear 12: " << queue->peekFromRear(0) << endl;
	cout << "Should return 'Queue is empty.'" << endl;
	cout << endl;
	cout << "Remove from rear (0) 6: " << endl << queue->removeFromRear(0) << endl;
	cout << "Should return 'Queue is empty.'" << endl;
	cout << endl;
	cout << "Count: " << queue->count() << endl;
	cout << "Should return 0." << endl;
	cout << endl;
	cout << "Peek 20: " << queue->peek() << endl;
	cout << "Should return 'Queue is empty.'" << endl;
	cout << endl;
	cout << "Peek Rear 13: " << queue->peekFromRear(0) << endl;
	cout << "Should return 'Queue is empty.'" << endl;
	cout << endl;




	cout << "Program complete." << endl;

	return 0;
}