#ifndef HASHTABLE_H
#define HASHTABLE_H

const int SIZE = 13;
struct DataElement{
	bool filled = false;
	int data = -1;
	int key;
};
class HashTable{
	private:
		DataElement DataTable[SIZE];
	public:
		int hashCode(int);
		void insert(int);
		void display();
		void Delete(int);
		void Search(int);
		bool isFull();
};
#endif
