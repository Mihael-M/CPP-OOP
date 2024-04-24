#include "DynamicArrayOfPointers.h"

void DynamicArrayOfPointers::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] data[i];
	}
	delete[] data;
	this->size = 0;
}

void DynamicArrayOfPointers::copy(const DynamicArrayOfPointers& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->data = new A*[other.size];
	for (size_t i = 0; i < this->capacity; i++)
	{
		if (other.data[i] == nullptr)
			data[i] = nullptr;
		else
			this->data[i] = new A(*other.data[i]);
	}
}

void DynamicArrayOfPointers::resize(size_t newCapacity)
{
	A** newDataPtr = new A * [newCapacity] {nullptr};
	this->capacity = newCapacity;
	for (size_t i = 0; i < capacity; i++)
	{
		newDataPtr[i] = data[i];
		
	}
	delete[] data;
	data = newDataPtr;
	
}

void DynamicArrayOfPointers::move(DynamicArrayOfPointers&& other)
{
	
	data = other.data;
	other.data = nullptr;
	capacity = other.capacity;
	size = other.size;
	other.size = 0;

}

int DynamicArrayOfPointers::getFirstFreeIndex() const
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (data[i] == nullptr)
		{
			return i;
		}
	}

	return -1;
}

DynamicArrayOfPointers::DynamicArrayOfPointers()
{
	capacity = 8;
	data = new A * [capacity] {nullptr};
}

DynamicArrayOfPointers::DynamicArrayOfPointers(const DynamicArrayOfPointers& other)
{
	copy(other);
}

DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(const DynamicArrayOfPointers& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

DynamicArrayOfPointers::DynamicArrayOfPointers(DynamicArrayOfPointers&& other) noexcept
{
	move(std::move(other));
}

DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(DynamicArrayOfPointers&& other) noexcept
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}
	return *this;
}

const A*& DynamicArrayOfPointers::operator[](size_t index) const
{
	return data[index];
}

A* DynamicArrayOfPointers::operator[](size_t index)
{
	return data[index];
}

bool DynamicArrayOfPointers::containsAt(unsigned ind) const
{
	return ind < capacity && data[ind] != nullptr;
}

void DynamicArrayOfPointers::setAtIndex(const A& obj, size_t index)
{
	if (size >= capacity)
		resize(capacity * 2);

	if (containsAt(index))
		*data[index] = obj;

	else {

		data[index] = new A(obj);
		size++;
	}

}
void DynamicArrayOfPointers::setAtIndex(A&& obj, size_t index)
{
	if (size >= capacity)
		resize(capacity * 2);

	if (containsAt(index))
		*data[index] = obj;

	else {

		data[index] = new A(std::move(obj));
		size++;
	}

}

size_t DynamicArrayOfPointers::getSize() const
{
	return this->size;
}

void DynamicArrayOfPointers::popBack()
{
	if (getSize() == 0)
		return;
	if (containsAt(size-1)) {
		delete[] data[size-1];
		size--;
	}
}

void DynamicArrayOfPointers::removeAt(size_t index)
{
	if (index >= size)
		return;

	if (containsAt(index)) {
		delete[] data[index];
		data[index] = nullptr;
		size--;
	}
}

void DynamicArrayOfPointers::addAtFirstFreeIndex(const A& current)
{
	if (size >= capacity)
		resize(capacity * 2);

	size_t index = getFirstFreeIndex();
	data[index] = new A(current);
	size++;


}

void DynamicArrayOfPointers::addAtFirstFreeIndex(A&& obj)
{
	if (size >= capacity)
		resize(capacity * 2);

	size_t index = getFirstFreeIndex();
	data[index] = new A(std::move(obj));
	size++;
}
