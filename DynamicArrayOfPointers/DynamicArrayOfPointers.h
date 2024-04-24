#pragma once
#include<iostream>
struct A {
	int x = 3;
	int y = 2;

};

class DynamicArrayOfPointers {
private:
	A** data;
	size_t capacity;
	size_t size = 0;
	void free();
	void copy(const DynamicArrayOfPointers& other);
	void resize(size_t newCapacity);
	void move(DynamicArrayOfPointers&& other);
	int getFirstFreeIndex() const;
public:

	DynamicArrayOfPointers();
	DynamicArrayOfPointers(const DynamicArrayOfPointers& other);
	DynamicArrayOfPointers& operator=(const DynamicArrayOfPointers& other);

	DynamicArrayOfPointers(DynamicArrayOfPointers&& other)noexcept;
	DynamicArrayOfPointers& operator=(DynamicArrayOfPointers&& other) noexcept;

	const A*& operator[](size_t index) const;
	A* operator[](size_t index);
	bool containsAt(unsigned ind) const;
	void setAtIndex(const A& obj, size_t index);
	void setAtIndex(A&& obj, size_t index);
	size_t getSize() const;
	void popBack();
	void removeAt(size_t index);
	void addAtFirstFreeIndex(const A& current);
	void addAtFirstFreeIndex(A&& obj);

};
