#include "DoublyLinkedList.h"
#include <stdexcept>
// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};
// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll) //Big O(n)
{
  // Initialize the list
  header =0;
  trailer = 0;
  header.next = &trailer; 
  trailer.prev = &header; 
  
  // Copy from dll
  DListNode *current = dll.getFirst();
  while(current != dll.getAfterLast()    //We are moving through the list from current node to the trailer, as getAfterLast() returns trailer  
  {										//So the loop goes on until current reaches the value of trailer
    this -> insertFirst(current->getElem());
	current = current->getNext();		//iterate
  }
 // header = dll.prev; //wrong because dll is not a node but the whole list with many nodes
}
// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll) //Big O(n)
{
  // Delete the whole list
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) //We are moving through the list from current node to the trailer, as getAfterLast() returns trailer 
  {
    prev_node = node;
    node = node->next;
    delete prev_node;		//Deleting the previous node, so that there is no garbage node generated
  }
  header.next = &trailer;
  trailer.prev = &header;
  
  // Copy from dll
  DListNode *current = dll.getFirst();
  while(current != dll.getAfterLast())//We are moving through the list from current node to the trailer, as getAfterLast() returns trailer  
  {										//So the loop goes on until current reaches the value of trailer   count++;
    this -> insertFirst(current->getElem());
	current = current->getNext();		//iterate
}
}
// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj)
{ 
  DListNode *newNode = new DListNode(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}
// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
  DListNode *newNode = new DListNode(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}
// remove the first object of the list
int DoublyLinkedList::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}
// remove the last object of the list
int DoublyLinkedList::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}
// destructor
DoublyLinkedList::~DoublyLinkedList()
{
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}
// return the first object
int DoublyLinkedList::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return header.next->obj;
}
// return the last object
int DoublyLinkedList::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev->obj;
}
// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll) {
  DListNode *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    current = current->getNext(); //iterate
  }
  return count;
}
// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll) //Big O(n)
{
  DListNode *current = dll.getFirst(); //Using the helper functions because the member variables are private
  while(current != dll.getAfterLast())  //We are moving through the list from current node to the trailer, as getAfterLast() returns the node before trailer  
	{								//So the loop goes on until current reaches the value of trailer		out<<current->obj<<" ";
    out<<current->getElem()<<" ";
    current = current->getNext(); //iterate
  }
  return out;
}
