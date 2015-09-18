#include <iostream>
//#include "Item.h"
//#include "MPQarray.h"
#include "MPQheap.h"

using namespace std;

int main()
{
	//MPQ using unsorted array
	MPQarray p;
/*	p.insertItem(2,"hello");
	p.insertItem(3,"how");
	p.insertItem(1,"are");
	p.insertItem(4,"you");
	p.print();
 */	
	//Creating a priorityqueue
	p.createPriorityQueue();
	p.print();
	//decreaseKey
	p.decreaseKey(10,"Boston");
	p.print();
	//minKey
	cout<<endl<<"Minimum:";
	Item l = p.minKey();
	l.print();
	//removeKey
	for(int i =0;i<40;i++)
	{
		p.removeKey();
		p.print();
		cout<<endl<<"Minimum:";
		Item l = p.minKey();
		l.print();
	}
	//MPQ using heap
	MPQheap h;
/*	h.insertItem(10,"hello");
	h.insertItem(5,"how");
	h.insertItem(1,"are");
	h.insertItem(8,"molly");
	h.insertItem(6,"cherry");
	h.print();
	cout<<endl;
*/
	//Creating a priorityqueue
	h.createPriorityQueue();
	h.print();
	cout<<endl;
	//decreaseKey
	h.decreaseKey(102,"Indianapolis");
	h.print();
	cout<<endl;
	//remove key
	for(int i =0;i<40;i++)
	{
		h.removeKey();
		h.print();
		cout<<endl<<"Minimum:";
		Item l = h.minKey();
		l.print();
	}
}