#include<iostream>
#include <conio.h>
#include "HashTable.h"
using namespace std;

int HashTable::hashCode(int key){
	return key % SIZE;
}
void HashTable::insert(int data) {
   //get the hash 
   bool Notpresent = true;
   int i = 1;
   int hashIndex = hashCode(data);
   //move in array until an empty or deleted cell
   while(DataTable[hashIndex].filled != false){
      //go to next cell
      if(DataTable[hashIndex].data == data)
      		Notpresent = false;
		//go to next i^2 cell of ith index
      hashIndex += i*i;
      hashIndex %= SIZE;
      if(isFull()){
      	cout<<"Table is Full!"<<endl;
      	return;
	  }
	  i++;
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
   int i = 1, j = 1;
   //move in array until an empty or deleted cell
   while(DataTable[hashIndex].data != data && DataTable[hashIndex].filled != false){
      //go to next cell
      if(j == SIZE+1)
      	break;
    //go to next i^2 cell of ith index
      hashIndex+= i*i;
	  hashIndex %= SIZE;
	  j++; i++;
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
   int i = 1, j = 1;
   //move in array until an empty or deleted cell
   while(DataTable[hashIndex].data != data && DataTable[hashIndex].filled != false){
      if(j == SIZE+1)
      	break;
    //go to next i^2 cell of ith index
      hashIndex+= i*i;
      hashIndex %= SIZE;
      j++; i++;
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
