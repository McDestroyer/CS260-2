
Queue Variables:
	Front (pointer): Points to the node at the front of the queue.
	Rear (pointer): Points to the node at the rear of the queue.
	Counter (int): The number of Nodes in the queue.

Queue Functions:
	Enqueue(Data):
		Add an element to the rear of the queue.
		Steps:
			Create a new node object and fill it with the given data.
			Take the original rear var ptr, give it to the new node.
			Replace the rear var contents with the new node.
			Navigate to the old rear node and hand it a reference to the new one to make it double-linked.
			Add one to the node counter.
	Dequeue:
		Remove and return the element from the front of the queue.
		Steps:
			If the queue isn't empty:
				Take the front node and extract it's stored data and the ptr to the node behind it.
				Free the front node.
				If there's a previous node:
					Set the front var to be the previously behind node.
					Set the new front node's pointer ahead var to be nullptr.
				If there was no previous node:
					Set the front and rear vars to be nullptr.
				Remove one from the node counter.
			Otherwise, fail in some way or just return null.
	Peek:
		Return the element at the front of the queue without removing it.
		Steps:
			Access the front variable and get its data.
	IsEmpty:
		Check if the queue is empty.
		Steps:
			Check if front node is nullptr.
	IsFull:
		Check if the queue is full.
		Steps:
			Check if counter var >= the max size.
			Maybe count instead?
	Count:
		Count the nodes in the queue.
		Steps:
			Set the counter var to 0.
			Fire a recursive function in the front node which increments the counter var via pointer and fires the counter in the next node until there are no more.
	Insert[Forward/Backward](Data, Distance):
		Insert a new node the given distance from the front or back depending on which function is called.
		Steps:
			Fire the relevant function in the relevant (front/rear) node, handing off the data and distance.
	Remove[Forward/Backward](ptr, Distance):
		Remove a node the given distance from the front or back depending on which function is called and set the ptr's referenced var to its data.
		Steps:
			Fire the relevant function in the relevant (front/rear) node, handing off the pointer and distance.



Node Variables:
	Data (string): Contains whatever data you wanted to store, in string format for this example.
	Ahead (pointer): Points to the node ahead of it.
	Behind (pointer): Points to the node behind it.

Node Functions:
	Init(Data, Ahead, Behind=nullptr):
		Sets up the function with the pointer to the node ahead and the data it contains, as well as possibly a behind node.
	InsertBackward(Data, Distance):
		Pass data recursively backward from the front, decrementing the distance var each time.
		Upon activation with a distance of 0, run Insert().
	InsertForward(Data, Distance):
		Do the exact same thing as InsertBackward() but passing the data in the opposite direction.
	Insert(Data):
		Create a node with the ahead node as it's ahead node, the current node as it's rear node, and the passed data as its data.
		Set the ahead var of the current node to the new node.
	RemoveBackward(Ptr, Distance):
		Move recursively backward from the front, passing on the pointer and decrementing the distance var each time.
		Upon activation with a distance of 0, run Remove() and return the value.
	RemoveForward(Ptr, Distance):
		Do the exact same thing as RemoveBackward() but moving in the opposite direction.
	Remove(Ptr):
		Set the next var of the previous node to the next of the current node.
		Repeat but backwards for the rear of the next.
		Set the variable referenced by Ptr to the data stored by the current node.
		Free() the current node.
	Count(CounterPtr):
		Add one to counter via the pointer.
		If there's a node behind, fire Count() in it.