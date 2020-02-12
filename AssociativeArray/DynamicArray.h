#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<algorithm>
using namespace std;

template <class V>
class DynamicArray

{
	V *values;
	int cap;
	V dummy;

public:
	DynamicArray(int = 2);
	DynamicArray(const DynamicArray &);
	~DynamicArray() { delete[] values; }
	int capacity() const { return cap; }
	void capacity(int);
	V operator[](int) const;
	V &operator[](int);
	DynamicArray &operator=(const DynamicArray &);
};

template <class V>
DynamicArray<V>::DynamicArray(int cap)
{
	this->cap = cap;
	values = new V[cap];
	for (int index = 0; index < cap; index++)
	{
		values[index] = V();
	}
}

template <class V>
V DynamicArray<V>::operator[](int index) const
{
	if (index < 0 || index >= cap)
		return V();
	return values[index];
}

template <class V>
V &DynamicArray<V>::operator[](int index)
{
	if (index < 0)
	{
		return dummy;
	}

	else if (index >= cap)
	{
		capacity(2 * index);
	}
	return values[index];
}

template <class V>
void DynamicArray<V>::capacity(int newCap)
{
	V *temp = new V[newCap];
	int limit = min(newCap, cap);
	for (int i = 0; i < limit; i++)
	{
		temp[i] = values[i];
	}
	for (int i = limit; i < cap; i++)
	{
		temp[i] = V();
	}
	delete[] values;
	values = temp;
	cap = newCap;
}

template <class V>
DynamicArray<V>::DynamicArray(const DynamicArray &original)
{
	cap = original.cap;
	values = new V[cap];

	for (int i = 0; i < cap; i++)
	{
		values[i] = original.values[i];
	}
}

template <class V>
DynamicArray<V> & DynamicArray<V>::operator=(const DynamicArray &original)
{
	if (this != &original)
	{
		delete[] values;
		cap = original.cap;
		values = new V[cap];

		for (int i = 0; i < cap; i++)
		{
			values[i] = original.values[i];
		}
	}
	return *this;
};

#endif


