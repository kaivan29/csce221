#include<iostream>
#include<string>
#include "MPQarray.h"

using namespace std;

class MPQheap		//Class for Minimum Priority queue using an heap
{
	private:
		Item* hp = new Item[41];  //Heap of type Item of capacity 40
	public:
		int size =0;			//size of the heap
		int comp = 0;			//number of comparisons done while removing an element
		bool isEmpty(){return size==0;}			//To check if the heap is empty or not
		void insertItem(int key, string elem);		//To insert the Item into the heap
		void createPriorityQueue();				//To create the Priority queue reading the input from the textfiles
		Item minKey(){return hp[0];};			//returns the smallest Item in the heap
		void removeKey();						//removes the smallest Item in the heap and updates the data structure
		void decreaseKey(int key, string elem);  //changes the key of the Item with particular element in the heap and updates the data structure
		void print()		//prints the minimum priority queue implemented using heap
		{
			for(int i=0;i<size;i++)
				cout<<"\n"<<hp[i].getKey()<<","<<hp[i].getElem();
		}
		
		void walkUp(int k, string e, int s); //After we insert, we perform a walkup of the item
		void walkDown();		//After we remove the smallest element, we perform a walkdown of the item
};

//Insert Item
void MPQheap::insertItem(int key, string elem) //To insert the item is just O(1), but the walup takes O(logn), hence O(logn)
{
	if(size==0)
	{
		hp[0] = Item(key,elem);
		size++;
	}
	else
	{
		Item p(key,elem);
		hp[size]=p;	
		size++;
		//Now we will perform Walk-up
		walkUp(key, elem, size-1); //O(logn)
		comp=0;
	}
}
//Walkup to support insert Item
void MPQheap::walkUp(int k, string e, int s)
{	
	Item n(k,e);
	while(hp[(s-1)/2].getKey()>k) //compares the child with the parent, if true will go up till the root
	{	//if true, swapping takes place
		hp[s].setKey(hp[(s-1)/2].getKey());
		hp[s].setElem(hp[(s-1)/2].getElem());
		hp[(s-1)/2].setKey(k);
		hp[(s-1)/2].setElem(e);
		s=(s-1)/2;
		comp++;		//Number of comparisons
	}
}

//remove Item aeni maa ne
void MPQheap::removeKey()	//To remove the smalles key is O(1) as it is the root. But the walkdown takes O(logn). Hence, O(logn)
{
	//we swap the root with the last element
	hp[0].setKey(hp[size-1].getKey());
	hp[0].setElem(hp[size-1].getElem());
	hp[size-1].setKey(hp[size].getKey()); //TO make the last element after the remove null
	hp[size-1].setElem(hp[size].getElem()); //To make the last element after the remove null
	size--;	//Decreasing the size of the queue
	walkDown(); //O(logn)
	cout<<"\nNumber of comparisons: "<<comp<<endl;
	comp=0;
}
//Walk down
void MPQheap::walkDown()
{
	int n = 0, count=0;
	while(count==0)
	{
		if((2*n+1)>=size) //If we go to a position where no children exists, we break of the loop
			break;

		else
		{
			int k = hp[n].getKey();
			string e = hp[n].getElem();
			//We choose the smallest of the left and the right child
			if(hp[2*n+1].getKey()<hp[2*n+2].getKey()||(2*n+2)>=size)
			{
				//We check if the parent is bigger than the left children
				if(hp[2*n+1].getKey()<hp[n].getKey())
				{	
					comp++;
					hp[n].setKey(hp[2*n+1].getKey());
					hp[n].setElem(hp[2*n+1].getElem());
					hp[2*n+1].setKey(k);
					hp[2*n+1].setElem(e);
					n=2*n+1;
				}
				else
					break; //If the parent is not bigger, the walkdown is to terminated
			}
			else
			{
				//We check if the parent is bigger than the right children
				if(hp[2*n+2].getKey()<hp[n].getKey())
				{	
					comp++;
					hp[n].setKey(hp[2*n+2].getKey());
					hp[n].setElem(hp[2*n+2].getElem());
					hp[2*n+2].setKey(k);
					hp[2*n+2].setElem(e);
					n=2*n+2;
				}
				else
					break;
			}
		}
	}
}
//decreaseKey
void MPQheap::decreaseKey(int key, string elem)
{
	cout<<"\n";
	int count = -1;
	for(int i=0;i<size;i++)
	{	
		if(hp[i].getElem()==elem)
		{
			hp[i].setKey(key);
			count=i;
		}
	}
	if(count==-1)
	{
		cout<<"Sorry The element is not in the priority queue"<<"\n";
	}
	else
	{
	walkUp(key, elem, count); //O(logn)
	walkDown();			//O(logn)
	cout<<"\nNumber of comparisons: "<<comp<<endl;
	comp=0;
	}
}
//
void MPQheap::createPriorityQueue() //O(n) for n elements
{
	string line;
	string file = "data.txt";
	string city;
	string miles;
	
	ifstream myfile(file);

	while( getline(myfile, line))
	{
		int i=0;
		while(line[i]!=',') //If we encounter a comma in the line, we will take the string before that and save it in the string city
		{
			city+=line[i];
			i++;
		}
		i = i+2;
		for(i;i<line.size();i++)
		{
			miles += line[i];
		}
		int key = stoi(miles);
		insertItem(key,city); //inserting the miles as key and city as element i.e as an Item in the queue 
		miles = "";
		city = "";
	}
}
