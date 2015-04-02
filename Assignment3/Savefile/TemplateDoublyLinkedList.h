#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Record.h"
#ifndef TEMPLATEDOUBLYLINKEDLIST_H_
#define TEMPLATEDOUBLYLINKEDLIST_H_
// extend range_error from <stdexcept>

using namespace std;

struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

template <class T> 
class DoublyLinkedList; // class declaration

// list node
template <class T>
class DListNode {
private: T obj;
  DListNode<T> *prev, *next;
  friend class DoublyLinkedList<T>;
public:
  DListNode(T e=T(), DListNode<T> *p = NULL, DListNode<T> *n = NULL)
    : obj(e), prev(p), next(n) {}
  T getElem() const { return obj; }
  DListNode<T> * getNext() const { return next; }
  DListNode<T> * getPrev() const { return prev; }
};

// doubly linked list
template <class T>
class DoublyLinkedList {
protected: DListNode<T> header, trailer;
public:
  DoublyLinkedList<T>() : header(T()), trailer(T()) // constructor
  { header.next = &trailer; trailer.prev = &header; }
  
  DoublyLinkedList(const DoublyLinkedList<T>& dll) // copy constructor
  {
  // Initialize the list
  header.next = &trailer; //header -> next = trailer
  trailer.prev = &header; //trailer -> prev = header
  
  // Copy from dll
  DListNode<T> *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    this -> insertFirst(current->getElem());
	current = current->getNext(); //iterate
  }
  }
  
  ~DoublyLinkedList() // destructor
  {
  DListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}
  
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll) // assignment operator
  {
  // Delete the whole list
  DListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
  /* Complete this function */
  
  // Copy from dll
  DListNode<T> *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    this -> insertFirst(current->getElem());
	current = current->getNext(); //iterate
  /* Complete this function */
}
}
  
  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; } 
  
  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; }
  
  // return if the list is empty
  bool isEmpty() const { return header.next == &trailer; }
  
  T first() const // return the first object
  { 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return header.next->obj;
}
  
  T last() const // return the last object
  {
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev->obj;
}
  
  void insertFirst(T newobj) // insert to the first of the list
  { 
  DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
 }
  
  T removeFirst() // remove the first node
  { 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode<T> *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  T obj = node->obj;
  delete node;
  return obj;
}
  
  void insertLast(T newobj) // insert to the last of the list
  {
  DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}
  
  T removeLast() // remove the last node
  {
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode<T> *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  delete node;
  return obj;
}

//insertOrderly
  void insertOrderly(const T& obj) //We will be sending object of type Record
	{	
		if(this->isEmpty())
		{
			this->insertFirst(obj);
		}
		DListNode<T> *node = new DListNode<T>(obj); //The node that I want to insert
		DListNode<T> *p = this->getFirst(); //This is my iterator
		while(p->getElem() < obj)    //To go through the current list we have
		{	
			if(p==this->getAfterLast())
			{
				this->insertLast(obj);
				return;
			}
			p = p -> getNext();
		}
		node->next=p;
		node->prev = p->prev;
		p->prev->next=node;//this.previous.next=N; //using this gives an error here
		p->prev=node;//this.previous=N;
	}
};

template<class T>
int DoublyLinkedListLength(DoublyLinkedList<T>& dll) {
  DListNode<T> *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    current = current->getNext(); //iterate
  }
  return count;
}

// output operator
template<class T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll){
  
  /* Complete this function */
  DListNode<T> *current = dll.getFirst(); //Using the helper functions because the member variables are private
  if(dll.isEmpty())
  {}
  else{
	while(current != dll.getAfterLast()) {
		out<<current->getElem()<<" ";
		current = current->getNext(); //iterate
	}
	}
  return out;
}
#endif