#ifndef STATICARRAY_H
#define STATICARRAY_H

template <typename T, int CAP>
class StaticArray
{
	T value[CAP]; // T datatype CAP compasity
	T dummy;

public:
	StaticArray();
	int capacity() const { return CAP; }
	const T& operator[ ] (int) const; // getter
	T& operator[ ] (int); // setter
};

template <typename T, int CAP>
StaticArray<T, CAP>::StaticArray() // consturctor
{
	for (int i = 0; i < CAP; i++)
		value[i] = T();
	dummy = T();
}

template <typename T, int CAP>
const T& StaticArray<T, CAP>::operator[ ] (int index) const // getter
{
	if (index < 0 || index >= CAP) return dummy;
	return value[index];
}

template <typename T, int CAP>
T& StaticArray<T, CAP>::operator[ ] (int index) // setter
{
	if (index < 0 || index >= CAP) return dummy;
	return value[index];
}

#endif