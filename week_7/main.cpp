

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

#include "hashtable.hpp"


int main()
{
	HashTable* hashTable = new HashTable(false);

	cout << "Hash Table Created" << endl;
	cout << "Setting Values" << endl;
	cout << endl;
	hashTable->set("hello", "world");
	hashTable->set("foo", "bar");
	hashTable->set("foo", "baz");
	cout << endl;

	cout << "Values Set" << endl;
	cout << "Getting Values. baz should have overwritten bar." << endl;
	cout << endl;

	cout << hashTable->get("hello") << " (Should be 'world')" << endl;
	cout << hashTable->get("foo") << " (Should be 'baz')" << endl;
	cout << endl;

	cout << "Values Got" << endl;
	cout << "Listing Keys" << endl;
	cout << endl;

	cout << hashTable->listKeys() << endl;
	cout << endl;

	cout << "Keys Listed" << endl;
	cout << "Removing Value foo" << endl;
	cout << endl;

	hashTable->remove("foo");

	cout << "Value Removed" << endl;
	cout << "Getting Value foo" << endl;
	cout << endl;

	try
	{
		cout << hashTable->get("foo") << endl;
		cout << endl;
		cout << "Value Found (This is bad)" << endl;
	}
	catch (const invalid_argument& _)
	{
		cout << "Value Not Found (This is good)" << endl;
	}
	cout << endl;

	cout << "Value Got" << endl << endl;

	cout << "##############################################" << endl;
	cout << "Success" << endl;
	cout << "##############################################" << endl << endl;

	delete hashTable;

	cout << "Testing smart hash table" << endl;

	HashTable* smartHashTable = new HashTable(true);

	cout << "Hash Table Created" << endl;
	cout << "Setting Values" << endl;
	cout << endl;

	smartHashTable->add("hello", "world");
	smartHashTable->add("foo", "bar");
	smartHashTable->add("foo", "baz");
	cout << endl;

	cout << smartHashTable->listKeys() << endl;

	cout << "Values Set" << endl;
	cout << "Getting Values. baz should NOT have overwritten bar." << endl;
	cout << endl;

	cout << smartHashTable->get("hello") << " (Should be 'world')" << endl;
	cout << smartHashTable->get("foo") << " (Should be 'bar')" << endl;
	cout << smartHashTable->get("foo", 1) << " (Should be 'baz' because I'm getting the 2nd index of the key)" << endl;
	cout << endl;

	cout << "Values Got" << endl;
	cout << "Listing Keys" << endl;
	cout << endl;

	cout << smartHashTable->listKeys() << endl;
	cout << endl;

	cout << "Keys Listed" << endl;
	cout << "Listing 'foo' Values" << endl;
	cout << endl;

	cout << smartHashTable->listValues("foo") << " (Should be ['bar', 'baz'])" << endl;
	cout << endl;

	cout << "Values Listed" << endl;


	return 0;
}