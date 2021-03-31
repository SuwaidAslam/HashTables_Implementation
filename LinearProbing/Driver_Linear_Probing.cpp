#include <iostream>
#include <conio.h>
#include "HashTable.h"
using namespace std;
int main() {
	HashTable hashTable;
	bool Runing = true;
	int option = 0;
	while(Runing)
	{
		system("CLS");
		cout << "\t\t\tHash Table -> Linear Probing\n";
		cout << "\t\t\t\t1-Insert\n";
		cout << "\t\t\t\t2-Delete\n";
		cout << "\t\t\t\t3-Display\n";
		cout << "\t\t\t\t4-Search\n";
		cout << "\t\t\t\t5-Exit\n";
		cout << "Enter Option: ";
		cin >> option;
		switch(option) {
		case 1:
			int op;
			do{
				int v;
				cout<<"Enter Value: ";
				cin>>v;
				hashTable.insert(v);
				cout<<"Insert one more?(1/0): ";
				cin>>op;
			}while(op==1);
			break;
		case 2:
			int n;
			cout<<"Enter Element Value to be deleted: ";
			cin>>n;
			hashTable.Delete(n);
			getch();
			break;
		case 3:
			hashTable.display();
			getch();
			break;
		case 4:
			int a;
			cout<<"Enter Value to be Search: ";
			cin>>a;
			hashTable.Search(a);
			getch();
			break;
		case 5:
			Runing = false;
			cout << "Press Any key to Continue...!";
			getch();
			break;
		default:
			cout << "Invalid Choice!";
			getch();
		}
	}
	
   return 0;
}
