//    Anthony Pasquariello
//    BUID: U04061063
//    Source, I used the discussion session linked list example for assistance
#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <iostream>
using namespace std;

/* A singly-linked list Node<T> */
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

/* A class for a singly-linked list */
template <typename T>
class LinkedList
{
public:
  LinkedList();       // Constructor: Inits an empty singly-linked list
  ~LinkedList();      // Destructor: Destroys the singly-linked list 
  int size();         // Returns the size of the singly-linked list
  bool contains(const T&);  // Returns true if x is in the list, otherwise returns false
  bool add(const T&);    // Adds x if not already in the list and returns true, otherwise returns false
  bool remove(const T&); // Removes x if in the list and returns true, otherwise returns false
  void print();       // Prints the content of the singly-linked list

private:
  Node<T> *head;         // Pointer to head of singly-linked list
  int listSize;       // Size of singly-linked list
};

//This is the ".cpp" part. 
template <typename T>
LinkedList<T>::LinkedList()      // Constructor: Inits an empty singly-linked list
{
  head = new Node<T>;
  head = NULL;
  listSize = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()      // Destructor: Destroys the singly-linked list 
{
  Node<T>* current = head;
  while(current-> next) 
  {
      Node<T>* next = current->next;
      delete current;
      current = next;
  }
}

template <typename T>
int LinkedList<T>::size()        // Returns the size of the singly-linked list
{
  return listSize;
}

template <typename T>
bool LinkedList<T>::contains(const T& x)  // Returns true if x is in the list, otherwise returns false
{
  Node<T>* current = head;
  while(current) //This will check all the elements (event the last one)
  {
      if(current->data == x) //Check if current is equal to x
        return true;
      current = current->next;
  }
  return false;
}

template <typename T>
bool LinkedList<T>::add(const T& x)    // Adds x if not already in the list and returns true, otherwise returns false
{

  if(listSize == 0) // If there isn't a LinkedList yet
  {
    Node<T>* temp = new Node<T>;
    temp->data = x;
    temp->next = NULL;
    head = temp;
    listSize++;
    return true;
  }

  if(contains(x)) //If there's already a number that's same
    return false;

  Node<T>* current = head;
    while(current->next)   //Traverse to end of linked list
  {
      current = current->next;
  }
  Node<T>* added = new Node<T>;
  added->data = x;
  added->next = NULL;
  current->next = added;
  listSize++;
  return true;
}

template <typename T>
bool LinkedList<T>::remove(const T& x) // Removes x if in the list and returns true, otherwise returns false
{
  if(!contains(x)) //If it doesn't contain 
    return false;

  if(head->data == x) //If we're removing the head (special case)
  {
    Node<T>* temp = NULL;
    temp = head;
    delete head;
    head = temp->next;
    listSize--;
    return true;
  }
  
  Node<T>* current = head;
  Node<T>* temp = NULL;
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

template <typename T>
void LinkedList<T>::print()       // Prints the content of the singly-linked list
{
  Node<T>* current = head;
  while(current) 
  {
      cout << current->data;
      cout << " ";
      current = current->next;
  }
  cout << endl;
}


#endif /* LinkedList_h */
