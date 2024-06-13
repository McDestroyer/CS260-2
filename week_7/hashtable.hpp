
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

#include "queuequeue.hpp"


class HashTable
{
	bool smart;
	QueueQueue* queue;

	public:

	/**
	* Create a new hash table.
	* @param smartMode [bool] Whether or not to enable smart mode. Smart mode allows for multiple values to be stored under a single key.
	*/
	HashTable(bool smartMode = false)
	{
		queue = new QueueQueue();
		smart = smartMode;

	}

	~HashTable()
	{
		delete queue;
	}

	/**
	* Add a key-value pair to the hash table. Does NOT overwrite existing keys.
	* @param key [string] The key to add the value to.
	* @param value [string] The value to add.
	*/
	void add(string key, string value)
	{
		if (!smart)
		{
			queue->removeByKey(key);
		}
		queue->add(key, value, !smart);
	}

	/**
	* Set the value of a key at a specific index. Overwrites existing values if they exist.
	* @param key [string] The key to set the value of.
	* @param value [string] The value to set.
	* @param index [int] The index to set the value at. If -1, replace all values of the key with a single copy of the value. Only used in smart mode.
	*/
	void set(string key, string value, int index = -1)
	{
		// Guarantee the queue exists.
		
		if (queue->peekByKey(key) != NULL)
		{
			queue->enqueue(key, new Queue());
		}


		// If smart mode is enabled, replace the value at the specified index.
		if (index != -1 && smart)
		{
			if (queue->peekByKey(key)->count() <= index)
			{
				queue->add(key, value);
				return;
			}
			queue->peekByKey(key)->removeFromFront(index);
			queue->peekByKey(key)->insertFromFront(value, index);
		}
		// Otherwise, just replace the key.
		else
		{
			queue->removeByKey(key);
			queue->add(key, value);
			cout << "Set key '" << key << "' to value: '" << value << "'" << endl;
		}

	}

	/**
	* Get the value of a key at a specific index.
	* @param key [string] The key to get the value of.
	* @param index [int] The index to get the value from. Only used in smart mode.
	* @return [string] The value of the key at the specified index.
	*/
	string get(string key, int index = 0)
	{
		if (smart)
		{
			if (queue->peekByKey(key) == NULL)
			{
				throw invalid_argument("Value does not exist.");
				return "";
			}
			return queue->peekByKey(key)->peekFromFront(index);
		}
		if (queue->peekByKey(key) == NULL)
		{
			throw invalid_argument("Value does not exist.");
			return "";
		}
		return queue->peekByKey(key)->peek();
	}

	/**
	* Get the number of values in a key.
	* @param key [string] The key to get the count of.
	* @return [int] The number of values in the key.
	*/
	int overlapSize(string key)
	{
		return queue->peekByKey(key)->count();
	}

	/**
	* Get a list of the keys in the hash table.
	* @param key [string] The key to get the count of.
	* @return [int] The number of values in the key.
	*/
	string listKeys()
	{
		return queue->list();
	}

	/**
	* Get a list of the values in the hash table. Only used in smart mode, but can be used in dumb mode.
	* @param key [string] The key to get the count of.
	* @return [int] The number of values in the key.
	*/
	string listValues(string key)
	{
		return queue->peekByKey(key)->list();
	}

	/**
	* Get the number of keys in the hash table.
	* @return [int] The number of keys in the hash table.
	*/
	int size()
	{
		return queue->count();
	}

	/**
	* Remove a key-value pair from the hash table.
	* @param key [string] The key to remove the value from.
	* @param index [int] The index to remove the value from. If -1, remove all values of the key. Only used in smart mode.
	*/
	void remove(string key, int index = -1)
	{
		if (index != -1 && smart)
		{
			queue->peekByKey(key)->removeFromFront(index);
		}
		else
		{
			queue->removeByKey(key);
		}
	}





};