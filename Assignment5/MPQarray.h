#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Item			//Item class that will used to define objects which will have key and elem as its member variables
{
	private:
		int key;		//key is the miles of the city in this case		
		string elem;	// elem is the name of the cities in this case
		friend class MPQarray;  //MPQarray is friends with class Item so that it can use its member variables
		friend class MPQheap;	//MPQheap is friends with class Item so that it can use its member variables
	public:
		Item() {key =0; elem = " ";}  //Default constructor
		Item(int k, string e):key(k),elem(e){}  //Parameterized constructor
		
		int getKey(){return key;}				//returns the key - miles
		string getElem(){return elem;}			//returns the elem - city
		void setKey(int k){key=k;}				//if we want to change the key, we will have to do it through a public function as it is a private member
		void setElem(string e){elem=e;}			//if we want to change the elem, we will have to do it through a public function as it is a private member
		void print(){cout<<"\n"<<key<<","<<elem;}		//If we want to print the Item as a whole
};

class MPQarray			//Class for Minimum Priority queue using an unsorted array
{
	private:
		Item* ar = new Item[41]; //Unsorted array of type Item of capacity 41
	public:
		int size =0;			//size of the unsorted array
		bool isEmpty();			//To check if the array is empty or not
		void insertItem(int k, string e); //To insert the Item into the array
		void createPriorityQueue();			//To create the Priority queue reading the input from the textfiles
		Item minKey();						//returns the smallest Item in the array
		void removeKey();					//removes the smallest Item in the array and updates the data structure
		void decreaseKey(int k, string e);		//changes the key of the Item with particular element
		void print()							//prints the minimum priority queue implemented using an unsorted array
		{
			for(int i=0;i<size;i++)
				cout<<"\n"<<ar[i].getKey()<<","<<ar[i].getElem();
		}
};
		
bool MPQarray::isEmpty() //O(1)
{
	if(size==0)
		return true;
}
void MPQarray::insertItem(int k, string e) //O(1)
{
		Item p = Item(k,e);
		ar[size]=p;			//inserted one after the other at the back of the array
		++size;
}

Item MPQarray::minKey()		//O(n)
{
	Item temp = ar[0];
	for(int i=1;i<size;i++) //searches the queue to find the minimum queue
	{
		if(temp.getKey()>ar[i].getKey()) //compares the elements
			temp = ar[i];
	}
	return temp;
}

void MPQarray::removeKey() //O(n)
{
	cout<<"\n";
	int count = 0;
	int key = ar[0].getKey();
	int comp = 0;
	for(int i=1;i<size;i++) //first to find the minimum key
	{	
		comp++;				//number of comparisons done to find the minimum key in the queue/array
		if(key>ar[i].getKey())
		{
			key = ar[i].getKey();
			count = i;
		}
	}

	for(int i=count;i<size;i++)  //to remove the item and update the data structure; also the last element was made null
	{
		ar[i] = ar[i+1];
	}
	size = size-1; //decreasing the size of the array
	cout<<"\nThe number of comparisons: "<<comp<<endl; 
}

void MPQarray::decreaseKey(int k, string e) //O(n)
{
	cout<<"\n";
	int count = -1;
	for(int i=0;i<size;i++)
	{	
		if(ar[i].getElem()==e)
		{
			ar[i].setKey(k);		//changing the key of the item
			count=1;
		}
	}
	if(count!=1) //If the item is not found
		cout<<"Sorry The element is not in the priority queue"<<"\n";
}

void MPQarray::createPriorityQueue()	//O(n) for n elements 
{
	string line;
	string file = "data.txt";
	string city;
	string miles;
	
	ifstream myfile(file);

	while( getline(myfile, line)) //reading each line from the file
	{
		int i=0;
		while(line[i]!=',') //If we encounter a comma in the line, we will take the string before that and save it in the string city
		{
			city+=line[i];		//adding charachter after charachter
			i++;
		}
		i = i+2;
		for(i;i<line.size();i++)	//string after the city are the miles
		{
			miles += line[i];
		}
		int key = stoi(miles);
		insertItem(key,city);		//inserting the miles as key and city as element i.e as an Item in the queue
		miles = "";					//made null so that next string can be added onto it
		city = "";
	}
}
