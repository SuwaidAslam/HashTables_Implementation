#include "HashTable.h"
#include<iostream>
#include <conio.h>
using namespace std;

int HashTable::hashCode(int key){
	return key % SIZE;
}
void HashTable::insert(int data) {
   //get the hash 
   bool Notpresent = true;
   int hashIndex = hashCode(data);
   //move in array until an empty or deleted cell
   while(DataTable[hashIndex].filled != false){
      //go to next cell
      if(DataTable[hashIndex].data == data)
      		Notpresent = false;
      ++hashIndex;
      hashIndex %= SIZE;
      if(isFull()){
      	cout<<"Table is Full!"<<endl;
      	return;
	  }
   }
   if(Notpresent){
	   DataTable[hashIndex].filled = true;
	   DataTable[hashIndex].data = data;
	   DataTable[hashIndex].key = hashIndex;
   }
   else
   	cout<<"Eelement Already exist in Table!"<<endl;
}
void HashTable::display(){
	cout<<"Data: ";
	for(int i=0;i<SIZE; i++){
		if(DataTable[i].data != -1)
			cout<<DataTable[i].data<<" ";
	}
}
void HashTable::Search(int data){
	//get the hash 
   int hashIndex = hashCode(data);
   int j = 1;
   //move in array until an empty or deleted cell
   while(DataTable[hashIndex].data != data && DataTable[hashIndex].filled != false){
      //go to next cell
      if(j == SIZE+1)
      	break;
      ++hashIndex;
	  hashIndex %= SIZE;
	  j++;
   }
   if(DataTable[hashIndex].filled == false || j == SIZE+1)
   			cout<<"Not Found!"<<endl;
	else{
		cout<<"Value of the Element: "<<DataTable[hashIndex].data<<endl;
   		cout<<"Index of the Element: "<<DataTable[hashIndex].key;
	}
}
void HashTable::Delete(int data){
	//get the hash 
   int hashIndex = hashCode(data);
   int j = 1;
   //move in array until an empty or deleted cell
   while(DataTable[hashIndex].data != data && DataTable[hashIndex].filled != false){
      //go to next cell
      if(j == SIZE+1)
      	break;
      ++hashIndex;
      hashIndex %= SIZE;
      j++;
   }
   if(DataTable[hashIndex].filled == false || j == SIZE+1)
   			cout<<"Not Found!"<<endl;
	else{
		DataTable[hashIndex].data = -1;
   		DataTable[hashIndex].filled = false;
	}
}
bool HashTable::isFull(){
	int counter = 0;
	for(int i=0;i<SIZE; i++){
		if(DataTable[i].data != -1)
			counter++;
	}
	if(counter == SIZE)
		return true;
	else
		return false;
}
