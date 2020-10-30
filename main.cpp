// OA_Hashing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OA_HashTable.h"
#include <iostream>
using namespace std;

int main()
{
	cout << endl << "***** OPEN ADDRESS HASHING *****" << endl;
	OA_HashTable table(8);

	cout << endl << "////////////////////////////////////////////////" << endl;
	cout << endl << "*** solution to problem 2-a) ***" << endl;
	cout << endl << "1, 2, 3, 4, 5, 6, 7 are inserted:" << endl;
	table.insert(1);
	table.insert(2);
	table.insert(3);
	table.insert(4);
	table.insert(5);
	table.insert(6);
	table.insert(7);
	table.print();
	cout << "////////////////////////////////////////////////" << endl;

	cout << endl << "1 and 6 are deleted, then 6 is inserted again:" << endl;
	table.remove(1);
	table.remove(6);
	table.insert(6);
	table.print();
	system("pause");
	return 0;
}

