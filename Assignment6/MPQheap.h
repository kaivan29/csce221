#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

class Item			//Item class that will used to define objects which will have key and elem as its member variables
{
	private:
		int key;		//key is the miles of the city in this case		
		string elem;	// elem is the name of the cities in this case
		int loc;
		friend class MPQarray;  //MPQarray is friends with class Item so that it can use its member variables
		friend class MPQheap;	//MPQheap is friends with class Item so that it can use its member variables
	public:
		Item() {key =0; elem = " "; loc =0;}  //Default constructor
		Item(int k, string e, int lo):key(k),elem(e), loc(lo){}  //Parameterized constructor
		
		int getKey(){return key;}				//returns the key - miles
		string getElem(){return elem;}			//returns the elem - city
		int getLoc(){return loc;}
		void setKey(int k){key=k;}				//if we want to change the key, we will have to do it through a public function as it is a private member
		void setElem(string e){elem=e;}			//if we want to change the elem, we will have to do it through a public function as it is a private member
		void setLoc(int lo){loc=lo;}
		void print(){cout<<"\n"<<key<<","<<elem;}		//If we want to print the Item as a whole
};

class Locator
{
	private:
		int itemIndex;
		friend class MPQheap;
	public:
		Locator(int index =0):itemIndex(index){}
		
		int index(){return itemIndex;}
		void print(){cout<<"\n"<<itemIndex<<endl;}
};

class MPQheap		//Class for Minimum Priority queue using an heap
{
	private:
		Item* hp = new Item[41];  //Heap of type Item of capacity 40
		Locator* locVec = new Locator[41];
		friend class Graph;
	public:
		int size =0;			//size of the heap
		int get_size(){return size;}
		int comp = 0;			//number of comparisons done while removing an element
		int loc_size = 0;
		bool isEmpty(){return size==0;}			//To check if the heap is empty or not
		void insertItem(int key, string elem, int loc);		//To insert the Item into the heap
		void createPriorityQueue();				//To create the Priority queue reading the input from the textfiles
		Item minKey(){return hp[0];};			//returns the smallest Item in the heap
		void removeKey();						//removes the smallest Item in the heap and updates the data structure
		void decreaseKey(int key, string elem);  //changes the key of the Item with particular element in the heap and updates the data structure
		void print()		//prints the minimum priority queue implemented using heap
		{
			for(int i=0;i<size;i++)
			{
//				if(hp[i].getKey()!=1000000)
					cout<<"\n"<<hp[i].getKey()<<","<<hp[i].getElem()<<","<<hp[i].getLoc();//<<", city Id:"<<locVec[i].index();
			}
		}
		void print_id()
		{
			for(int i=0;i<loc_size;i++)
				cout<<"\ncity Id:"<<locVec[i].index();
		}
		void walkUp(int k, string e, int s, int lo); //After we insert, we perform a walkup of the item
		void walkDown();		//After we remove the smallest element, we perform a walkdown of the item
		
		void setloc();
};

//Insert Item
void MPQheap::insertItem(int key, string elem, int loc) //To insert the item is just O(1), but the walup takes O(logn), hence O(logn)
{
	if(size==0)
	{
		hp[0] = Item(key,elem,loc);
		locVec[hp[0].getLoc()] = Locator(0);
		size++;
	}
	else
	{
		Item p(key,elem, loc);
		hp[size]=p;	
		locVec[hp[size].getLoc()] = Locator(size);
		size++;
		//Now we will perform Walk-up
		walkUp(key, elem, size-1, loc); //O(logn)
		comp=0;
		loc_size = size;

	}
}
//Walkup to support insert Item
void MPQheap::walkUp(int k, string e, int s, int lo)
{	
	Item n(k,e, lo);
	while(hp[(s-1)/2].getKey()>k) //compares the child with the parent, if true will go up till the root
	{	//if true, swapping takes place
		hp[s].setKey(hp[(s-1)/2].getKey());
		hp[s].setElem(hp[(s-1)/2].getElem());
		hp[s].setLoc(hp[(s-1)/2].getLoc());
		hp[(s-1)/2].setKey(k);
		hp[(s-1)/2].setElem(e);
		hp[(s-1)/2].setLoc(lo);
//		locVec[hp[s].getLoc()] = Locator((s-1)/2);
//		locVec[hp[(s-1)/2].getLoc()] = Locator(s);
		s=(s-1)/2;
		comp++;		//Number of comparisons
	}
}

void MPQheap::setloc()
{
	for(int i =0; i<size;i++)
	{
		locVec[hp[i].getLoc()] = Locator(i);
	}
}

//remove Item aeni maa ne
void MPQheap::removeKey()	//To remove the smalles key is O(1) as it is the root. But the walkdown takes O(logn). Hence, O(logn)
{
	//we swap the root with the last element
	hp[0].setKey(hp[size-1].getKey());
	hp[0].setElem(hp[size-1].getElem());
	hp[0].setLoc(hp[size-1].getLoc());
	hp[size-1].setKey(hp[size].getKey()); //TO make the last element after the remove null
	hp[size-1].setElem(hp[size].getElem()); //To make the last element after the remove null
	hp[size-1].setLoc(0);//hp[size].getLoc());
	size--;	//Decreasing the size of the queue
	walkDown(); //O(logn)
	cout<<"\nNumber of comparisons done to remove the key: "<<comp<<endl;
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
			int lo = hp[n].getLoc();
			//We choose the smallest of the left and the right child
			if(hp[2*n+1].getKey()<hp[2*n+2].getKey()||(2*n+2)>=size)
			{
				//We check if the parent is bigger than the left children
				if(hp[2*n+1].getKey()<hp[n].getKey())
				{	
					comp++;
					hp[n].setKey(hp[2*n+1].getKey());
					hp[n].setElem(hp[2*n+1].getElem());
					hp[n].setLoc(hp[2*n+1].getLoc());
					hp[2*n+1].setKey(k);
					hp[2*n+1].setElem(e);
					hp[2*n+1].setLoc(lo);
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
					hp[n].setLoc(hp[2*n+2].getLoc());
					hp[2*n+2].setKey(k);
					hp[2*n+2].setElem(e);
					hp[2*n+2].setLoc(lo);
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
	walkUp(key, elem, count, 0); //O(logn)
	walkDown();			//O(logn)
	cout<<"\nNumber of comparisons to restructure heap: "<<comp<<endl;
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
	string index;
	int lo=11;
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
			if(line[i]==',')
				break;
			index += line[i];
		}
		int lo = stoi(index);
		i=i+2;
		for(i;i<line.size();i++)
		{
			miles += line[i];
		}
		int key = stoi(miles);
		insertItem(key,city,lo); //inserting the miles as key and city as element i.e as an Item in the queue 
		miles = "";
		city = "";
		index= "";
	}
}
