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
  myReadFile.open("PhoneBook.txt");
  cout<<"Raw File:"<<"\n";
  while(!myReadFile.eof()) // To get you all the lines.
  {	 
	    getline(myReadFile,lastname); // Saves the line in STRING.
	    getline(myReadFile,firstname);
	    getline(myReadFile,Uin);
	    getline(myReadFile,ph);
		getline(myReadFile,space);
//		cout<<"\n"<<lastname<<"\n"<<firstname<<"\n"<<Uin<<"\n"<<ph<<"\n";
		Record newRec = Record(lastname,firstname,Uin,ph);
		int num = get_index(lastname[0]);
		phoneBook[num].insertOrderly(newRec); //phoneBook[num]=DoublyLinkedList.insertOrderly(newRec);
  }
  myReadFile.close();
  display(phoneBook);
  search(phoneBook);
  return 0;
}

void display(vector<DoublyLinkedList<Record>> phoneBook)
{	
	cout<<"File:"<<"\n";
	for(int i=0;i<phoneBook.size();i++)
	{
		cout<<"\n"<<phoneBook[i];
	}
}

/*
*/
int get_index(char c)
{
	int num = c-65;
	return num;
}

void check_case(string& bring)
{
	int i =0;
	bring[i]=(toupper(bring[0]));
	for(i=1;i<bring.length();i++)
		bring[i]=(tolower(bring[i]));
}
//Function to search through the PhoneBook
void search(vector<DoublyLinkedList<Record>> phoneBook)
{
	string lastname=" ", firstname=" ", UIN=" ",ph=" ",space=" ";
	cout<<"\nEnter the last name\n";
	cin>>lastname;

	check_case(lastname);
	cout<<lastname<<endl;
	int num = get_index(lastname[0]);
	int j=0;
	int yum = DoublyLinkedListLength(phoneBook[num]);

	vector<DListNode<Record>> rec;
	DListNode<Record>* node;
	if(yum==0)
	{	
		cout<<"\nThere is no person with that Last name";
		search(phoneBook);
	}
//SEARCH for LASTNAME
	node = phoneBook[num].getFirst();
	int i=0;
	for(j=0;j<yum-1;j++)
	{	
		if(node->getElem().get_last_name()==lastname)
		{
			rec.push_back(node->getElem());
			cout<<rec[i].getElem()<<endl;
			i++;
			}
		node =node->getNext();
	}
	if(i==0)
	{
		cout<<"There is no person with that last_name\n";
		search(phoneBook);
	}
	else if (i==1)
	{
		cout<<"\nThe details of the person that you asked for:\n";
		cout<<rec[0].getElem();
	}
	
//SEARCH for FIRSTNAME	
	else
	{	
		cout<<"\nPlease Enter the First name:\n";
		cin>>firstname;
		check_case(firstname);
		vector <DListNode<Record>> rec1;
		string f_itr;
		i=0;
		for(j=0;j<rec.size();j++)
		{	
			f_itr = rec[j].getElem().get_first_name();
			if(f_itr==firstname)
			{
				i++;
				rec1.push_back(rec[j].getElem());
			}
		}
		
		if(i==0)
		{
			cout<<"\nThere is no person with that first_name";
			search(phoneBook);
		}
		else if (i==1)
	    {
			cout<<"\nThe details of the person that you asked for:\n";
			cout<<rec1[0].getElem();
	    }
		
//SEARCH for UIN
		else
		{
			cout<<"\nPlease Enter the UIN:\n";
			cin>>UIN;
			string UIN_itr;
			for(j=0;j<rec1.size();j++)
			{	
				UIN_itr = rec1[j].getElem().get_UIN();
				if(UIN_itr==UIN)
				{
					cout<<"\nThe details of the person that you asked for:\n"<<rec1[j].getElem();
					return;
				}
			}
			cout << "We couldn't find anythin.\n";
			search(phoneBook);
		}
	}
}


//int List(vector<TemplateDoublyLinkedList<Record>> phone_Book);