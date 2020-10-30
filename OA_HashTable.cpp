#include "StdAfx.h"
#include "OA_HashTable.h"
#include <iostream>
using namespace std;

OA_HashTable::OA_HashTable(int size) :
	size_(size), table_(new Node[size])
{

}

OA_HashTable::~OA_HashTable(void)
{
	delete[]table_;
}

bool
OA_HashTable::search(int key)const
{
	int a = firstFunction(key) % size_,
		b = secondFunction(key) % size_;
	int count = 0;
	while (count < size_) {
		if (table_[a].status_ == FREE)
			return false;
		if (table_[a].status_ == OCCUPIED && table_[a].key_ == key)
			return true;
		a = (a + b) % size_;
		++count;
	}
	return false;
}

void
OA_HashTable::insert(int key)
{
	if (search(key))
		return;
	int a = firstFunction(key) % size_,
		b = secondFunction(key) % size_;
	int count = 0;
	while (count < size_) {
		if (table_[a].status_ != OCCUPIED) {
			table_[a].key_ = key;
			table_[a].status_ = OCCUPIED;
			return;
		}
		a = (a + b) % size_;
		++count;
	}
}

void
OA_HashTable::remove(int key)
{
	if (!search(key))
		return;
	int a = firstFunction(key) % size_,
		b = secondFunction(key) % size_;
	while (true)
	{
		if (table_[a].status_ == OCCUPIED && table_[a].key_ == key) {
			table_[a].status_ = DELETED;
			return;
		}
		a = (a + b) % size_;
	}
}

void
OA_HashTable::print()const
{
	cout << endl;
	for (int i = 0; i<size_; i++) {
		cout << "pos=" << i << ": ";
		if (table_[i].status_ == OCCUPIED)
			cout << table_[i].key_ << endl;
		else
			if (table_[i].status_ == FREE)
				cout << "FREE" << endl;
			else
				cout << "DELETED" << endl;
	}
	cout << endl;
}
