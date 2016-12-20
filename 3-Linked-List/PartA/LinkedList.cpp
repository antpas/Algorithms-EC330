//    Anthony Pasquariello
//    BUID: U04061063
//	  Source, I used the discussion session linked list example for assistance

#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()      // Constructor: Inits an empty singly-linked list
{
	head = new Node;
	head = NULL;
	listSize = 0;
}

LinkedList::~LinkedList()      // Destructor: Destroys the singly-linked list 
{
	Node* current = head;
	while(current-> next) 
	{
   		Node* next = current->next;
    	delete current;
    	current = next;
	}
}

int LinkedList::size()        // Returns the size of the singly-linked list
{
	return listSize;
}

bool LinkedList::contains(int x)  // Returns true if x is in the list, otherwise returns false
{
	Node* current = head;
	while(current) //This will check all the elements (event the last one)
	{
    	if(current->data == x) //Check if current is equal to x
    		return true;
    	current = current->next;
	}
	return false;
}

bool LinkedList::add(int x)    // Adds x if not already in the list and returns true, otherwise returns false
{

	if(listSize == 0) // If there isn't a LinkedList yet
	{
		Node* temp = new Node;
		temp->data = x;
		temp->next = NULL;
		head = temp;
		listSize++;
		return true;
	}

	if(contains(x)) //If there's already a number that's same
		return false;

	Node* current = head;
    while(current->next)   //Traverse to end of linked list
	{
   		current = current->next;
	}
    Node* added = new Node;
	added->data = x;
	added->next = NULL;
	current->next = added;
	listSize++;
	return true;
}

bool LinkedList::remove(int x) // Removes x if in the list and returns true, otherwise returns false
{
	if(!contains(x)) //If it doesn't contain 
		return false;

	if(head->data == x) //If we're removing the head (special case)
	{
		Node* temp = NULL;
		temp = head;
		delete head;
		head = temp->next;
		listSize--;
		return true;
	}
	
	Node* current = head;
	Node* temp = NULL;
	while(current) 
	{
	    if(current->data == x) 
	    {
	    	temp->next = current->next;
	    	delete current;
	    	listSize--;
	    	return true;
	    }
	    temp = current;
		current = current->next;		
	}
	return false;
}
void LinkedList::print()       // Prints the content of the singly-linked list
{
	Node* current = head;
	while(current) 
	{
   		cout << current->data;
   		cout << " ";
   		current = current->next;
	}
	cout << endl;
}
