#pragma once

//*** THE REPETITIONS ARE NOT ALLOWED ***//
class OA_HashTable
{
	enum Status { FREE, OCCUPIED, DELETED };

	struct Node {
		int		key_;
		Status	status_;
		Node(int key = 0, Status status = FREE) :key_(key), status_(status) {}
	};
	//the values of these functions should be taken modulo size_
	static int firstFunction(int key) { return key * key + 1; }
	static int secondFunction(int key) { return (key << 1) + 1; }

public:
	OA_HashTable(int size);
	~OA_HashTable(void);


	/*1*/ bool  search(int key)const;	//. . . should be implemented . . .

										//precondition: search(key)==false
	/*2*/ void  insert(int key);		//. . . should be implemented . . .

										//precondition: search(key)==true
	/*3*/ void  remove(int key);		//. . . should be implemented . . .

	void  print()const;

private:
	Node * table_;
	int					size_;		//should be a power of 2
};

