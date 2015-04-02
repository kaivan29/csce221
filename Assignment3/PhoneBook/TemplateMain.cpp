#include "TemplateDoublyLinkedList.h"
#include "Record.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void display(vector<DoublyLinkedList<Record>> phoneBook);
int get_index(char c);
void search(vector<DoublyLinkedList<Record>> phoneBook);

int main () 
{
  vector<DoublyLinkedList<Record>> phoneBook(26); //Creating the vector phoneBook of DoublyTemplateLinkedList type
  string firstname, lastname, Uin, ph, space;  //To take input from the textfile;
  
  ifstream myReadFile;
  cout<< "\nEnter the name of the textfile you want to read.\n";
  string text = " ";
  cin >> text;
  myReadFile.open(text);
  cout<<"Raw File:"<<"\n";
  while(!myReadFile.eof()) // To get you all the lines.
  {	 
	    getline(myReadFile,lastname); // Saves the line in STRING.
	    getline(myReadFile,firstname);
	    getline(myReadFile,Uin);
	    getline(myReadFile,ph);
		getline(myReadFile,space);
		Record newRec = Record(lastname,firstname,Uin,ph);
		int num = get_index(lastname[0]);
		phoneBook[num].insertOrderly(newRec); //phoneBook[num]=DoublyLinkedList.insertOrderly(newRec);
  }
  myReadFile.close();
  cout<<"\nThe phoneBook has the following contents:\n";
  display(phoneBook); //To display the elements on the screen
  search(phoneBook);  //For the user to search through the files
  return 0;
}

//Function to display the whole List
void display(vector<DoublyLinkedList<Record>> phoneBook)
{	
	cout<<"File:"<<"\n";
	for(int i=0;i<phoneBook.size();i++)
	{
		cout<<"\n"<<phoneBook[i];
	}
	cout<<"\nLet us search through the phoneBook \n";
}

//To get the index of the first charachter in order to store it in the vector
int get_index(char c)
{
	int num = c-65;
	return num;
}

//Function to search through the PhoneBook
void search(vector<DoublyLinkedList<Record>> phoneBook)
{
	vector<Record> l_names; //vector to store the last names
	vector<Record> f_names; //vector to store the first names narrowed down from the last names
	string lastname, firstname, UIN;
	cout<<"\nEnter the last name:\n";
	cin>>lastname;
	
	//To convert the first alphabet to capital and the others to small case in case the user enters in a different format
	lastname[0] =(toupper(lastname[0]));
	int num = get_index(lastname[0]);
	int i =1;
	while (lastname[i])
	{
		lastname[i]=(tolower(lastname[i]));
		i++;
	}
	
	int listLength = DoublyLinkedListLength(phoneBook[num]);
	if(listLength==0)		//If the user enters a last name that is not there in the list, say it is at an empty linked list, we just tell the user to enter a valid last name again
	{	
		cout<<"\nThere is no person with that Last name \n";
		cout<<"\nLet us start the search again: **** If you want to end press ctrl+Z\n";
		search(phoneBook);
	}
//SEARCH for LASTNAME
	DListNode<Record>* node = phoneBook[num].getFirst(); //We created a node of type Record to iterate through the list.
	
	while(node!=phoneBook[num].getAfterLast())    //Iteration from beginning of the list till the end
	{
		string temp=node->getElem().get_last_name(); //To check if the obj at node is equal to the last name user wants
		if(temp==lastname)
		{
			l_names.push_back(node->getElem());		//If search found we save it into the vector
		}
		node = node->getNext();						//Iterate
	}
	if(l_names.size()==0)							//Incase there is no value in the vector that would imply there was no such Last name in the phoneBook
	{
		cout<<"There is no person with that last_name\n";
		search(phoneBook);
	}
	else if (l_names.size()==1)						//Incase we find the unique last name, we print out the whole node for the user
	{
		cout<<"\nThe details of the person that you asked for:\n";
		cout<<l_names[0];
	}
	
//SEARCH for FIRSTNAME	
	else										//If there are multiple same last names!
	{	
		cout<<"\nPlease Enter the First name:\n";
		cin>>firstname;
		
		//To convert the first alphabet to capital and the others to small case in case the user enters in a different format
		firstname[0] =(toupper(firstname[0]));
		num = get_index(firstname[0]);
		i =1;
		while (firstname[i])
		{
			firstname[i]=(tolower(firstname[i]));
			i++;
		}
		
		//we check the possiblities just like we did for last name
		for(int i =0; i<l_names.size();i++)
		{	
			string temp=l_names[i].get_first_name();
			if(temp==firstname)
			{
				f_names.push_back(l_names[i]);
			}
		}
		if(f_names.size()==0)
		{
			cout<<"\nThere is no person with that first_name";
			cout<<"\nLet us start the search again: **** If you want to end press ctrl+Z\n";
			search(phoneBook);
		}
		else if (f_names.size()==1)
	    {
			cout<<"\nThe details of the person that you asked for:\n";
			cout<<f_names[0];
	    }
		
//SEARCH for UIN
		else					//If there are multiple same first names
		{
			cout<<"\nPlease Enter the UIN:\n";
			cin>>UIN;
			
			for(int i=0;i<f_names.size();i++)
			{	
				string temp = f_names[i].get_UIN();
				if(temp==UIN)
				{
					cout<<"\nThe details of the person that you asked for:\n"<<f_names[i];
					return;
				}
			}
			cout << "We couldn't find anythin.\n";
			cout<<"\nLet us start the search again: **** If you want to end press ctrl+Z\n";
			search(phoneBook);
		}
	}
}


//int List(vector<TemplateDoublyLinkedList<Record>> phone_Book);