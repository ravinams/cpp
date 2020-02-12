#ifndef ASSOCIATIVEARRAY_H
#define ASSOCIATIVEARRAY_H
#include<algorithm>
#include<queue>
using namespace std;

template <typename K, typename V>
class AssociativeArray
{
	struct Node
	{
		K key;
		V value;
		bool inUse;
	};

	Node* values;
	int siz;
	int cap;
	void capacity(int);

	public:
	AssociativeArray(int = 2);  //DONE! 
	AssociativeArray(const AssociativeArray<K, V> &);  //DONE!  
	AssociativeArray<K, V>& operator=(const AssociativeArray<K, V> &); //DONE!
	~AssociativeArray() { delete[] values; }  //DONE!
	V operator[](const K&) const;  // or const V& as return type  //DONE! //TEST DONE!
	V& operator[](const K&);  //DONE! //TEST DONE!
	bool containsKey(const K&) const;  //DONE! //TEST DONE!
	void deleteKey(const K&);  //DONE! //TEST DONE!
	queue<K> keys() const;  //DONE!
	int size() const { return siz; }  //DONE! //TEST DONE!
	void clear();  //DONE! //TEST DONE!
};

//==================================================================================
// The Main Constructor
//==================================================================================
template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(int cap)
{
	this->cap = cap;
	values = new Node[cap];
	for (int i = 0; i < cap; i++)
	{
		values[i].key = K();
		values[i].value = V();
		values[i].inUse = false;
	}
}

//==================================================================================
// The Copy Constructor
//==================================================================================
template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V> &original)
{
	cap = original.cap;
	values = new Node[cap];
	for (int i = 0; i < cap; i++)
	{
		values[i].key = original.values[i].key;
		values[i].value = original.values[i].value;
		values[i].inUse = original.values[i].inUse;
	}
	siz = original.siz;

}

//==================================================================================
// The Assignment Operator
//==================================================================================
template<typename K, typename V>
AssociativeArray<K,V> & AssociativeArray<K,V>::operator=(const AssociativeArray &original)
{
	if (this != &original)
	{
		delete[] values;
		cap = original.cap;
		values = new Node[cap];

		for (int i = 0; i < cap; i++)
		{
			values[i].key = original.values[i].key;
			values[i].value = original.values[i].value;
			values[i].inUse = original.values[i].inUse;
		}
		siz = original.siz;
	}
	return *this;
}

//==================================================================================
// The Square Bracket Operator Getter
//==================================================================================
template <typename K, typename V>
V AssociativeArray<K, V>::operator[](const K& index) const
{
	for (int i = 0; i < cap; ++i)
	{
		if (values[i].inUse && values[i].key == index)
		{
			return values[i].value;
		}
	}
	return V();
}

//==================================================================================
// The Square Bracket Operator Setter
//==================================================================================
template <typename K, typename V>
V& AssociativeArray<K,V>::operator[](const K& key)
{
	int indexOfFirstUnusedKey = cap; // =cap indicates no not in-use in found (yet)
	for (int index = 0; index < cap; index++) //where "cap" is a private data member
	{
		if (values[index].inUse)
		{
			if (values[index].key == key) // K must support ==
				return values[index].value;
		}
		else if (indexOfFirstUnusedKey == cap) // no not in-use found yet
			indexOfFirstUnusedKey = index;
	}

	// If we get this far, no matching key was found
	if (indexOfFirstUnusedKey == cap) capacity(2 * cap); // Need more Nodes
	values[indexOfFirstUnusedKey].key = key;
	values[indexOfFirstUnusedKey].value = V();
	values[indexOfFirstUnusedKey].inUse = true;
	++siz;
	return values[indexOfFirstUnusedKey].value; // This is how the value gets set
}

//==================================================================================
// The containsKey Getter
//==================================================================================
template <typename K, typename V>
bool AssociativeArray<K,V>::containsKey(const K& key) const
{
	for (int index = 0; index < cap; index++) //where "cap" is a private data member
	{
		if (values[index].inUse)
		{
			if (values[index].key == key) // K must support ==
				return true;
		}
	}
}

//==================================================================================
// The deleteKey Setter
//==================================================================================
template <typename K, typename V>
void AssociativeArray<K,V>::deleteKey(const K& key)
{
	for (int index = 0; index < cap; index++) //where "cap" is a private data member
	{
		if (values[index].inUse)
		{
			if (values[index].key == key) // K must support ==
			{
				values[index].inUse = false;
				--siz;
				break;
			}
		}
	}
}

//==================================================================================
// The Keys getter
//==================================================================================
template <typename K, typename V>
queue<K> AssociativeArray<K,V>::keys() const
{
	queue<K> k_queue;
	for (int i = 0; i < cap; ++i)
		if (values[i].inUse)
			k_queue.push(values[i].key);
	return k_queue;
}

//==================================================================================
// The clear setter
//==================================================================================
template <typename K, typename V>
void AssociativeArray<K, V>::clear()
{
	for (int index = 0; index < cap; index++) //where "cap" is a private data member
	{
		values[index].inUse = false;
	}
	siz = 0;
}

//==================================================================================
// The capacity setter
//==================================================================================
template <typename K, typename V>
void AssociativeArray<K, V>::capacity(int newCap)
{
	Node *temp = new Node[newCap];
	int limit = min(newCap,cap);
	for (int i = 0; i < limit; i++)
	{
		temp[i] = values[i];
	}
	for (int i = limit; i < cap; i++)
	{
		temp[i].value = V();
		temp[i].key = K();
	}
	delete[] values;
	values = temp;
	cap = newCap;
}

#endif