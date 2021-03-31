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
   int hashIndex = hashCode(data);
   if(isFull()){
   	cout<<"Table is Full!";
   	return ;
   }
   //if collision occures add a node
   if(DataTable[hashIndex].filled)
   {
   	node *temp = new node;
   	temp->data = data;
   	temp->next = NULL;
   	if(DataTable[hashIndex].next == NULL)
   		DataTable[hashIndex].next = temp;
   	else{
   		node *temp1 = DataTable[hashIndex].next;
   		while(temp1->next!=NULL)
   			temp1 = temp1->next;
		temp1->next = temp;
	}
   }
   else{
	   DataTable[hashIndex].filled = true;
	   DataTable[hashIndex].data = data;
	   DataTable[hashIndex].key = hashIndex;
   }
}
void HashTable::display(){
	for(int i=0;i<SIZE; i++){
		if(DataTable[i].data != -1){
			cout<<"=> "<<DataTable[i].data<<" ";
			if(DataTable[i].next != NULL){
				node *tmp = DataTable[i].next;
				while(tmp!=NULL){
					cout<<tmp->data<<" ";
					tmp = tmp->next;
				}
			}
			cout<<endl;
		}
	}
}
void HashTable::Search(int data){
	//get the hash 
   int hashIndex = hashCode(data);
	if(DataTable[hashIndex].data !=data)
	{
	   	node *temp1 = DataTable[hashIndex].next;
	   	if(temp1 != NULL){
	   	while(temp1->next!=NULL && temp1->data != data)
	   		temp1 = temp1->next;
		if(temp1->data == data){
			cout<<"Value of the Element: "<<temp1->data<<endl;
   			cout<<"Index of the Element: "<<DataTable[hashIndex].key;
		}
		else
			cout<<"Element Does not exist!"<<endl;	
	}
	else
		cout<<"Element Does not exist!"<<endl;	
	}
	else{
		cout<<"Value of the Element: "<<DataTable[hashIndex].data<<endl;
   		cout<<"Index of the Element: "<<DataTable[hashIndex].key;
	}
}
void HashTable::Delete(int data){
	//get the hash 
   int hashIndex = hashCode(data);
   if(DataTable[hashIndex].data !=data)
	{
	   	node *temp1 = DataTable[hashIndex].next;
	   	node *last = NULL;
	   	while(temp1->next!=NULL && temp1->data != data){
	   		last = temp1;
	   		temp1 = temp1->next;
		}
		if(temp1->data == data && last != NULL){
			last->next = temp1->next;
			delete temp1;
		}
		else if(temp1->data == data && last == NULL){
			 DataTable[hashIndex].next = temp1->next;
			delete temp1;
		}
		else
			cout<<"Element Does not exist!"<<endl;
	}
	else if(DataTable[hashIndex].filled && DataTable[hashIndex].data ==data){
		DataTable[hashIndex].data = -2;
   		DataTable[hashIndex].filled = false;
	}
	else
		cout<<"Item Not Found!"<<endl;
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
