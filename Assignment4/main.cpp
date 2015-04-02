#include <iostream>
#include <fstream>
#include "binarysearchtree.h"
#include<queue>
#include<math.h>

using namespace std;
//To output the tree level by level
void OutputTreeLevelByLevel(BinarySearchTree T)
{
	queue<BinaryNode*> q; //Queue that stores the nodes of the tree
	BinaryNode empty;
	int count =0;
	int line =0;
	int x =0;
	int d = T.depth();
	q.push(T.getRoot());
	while (!q.empty())	//To access each node and print them
	{
		BinaryNode *node = q.front();
		q.pop();
		count++;
		line++;
	//output a node (you need to determine whether to output a newline) 
		if(node->Key()==0)
			cout<<"X";
		else
			cout<<node->Key();
			
		if(pow(2,x)==line)		//If we have encountered the end of the level, we need to go the next level
		{
			cout<<endl;
			line = 0;
			x=T.sc(node->Key());
		}
			
		if(node->getLeft()==NULL)
			q.push(&empty);		//We insert 0's where there is no node so that when we print the non-existing nodes we print them as X
		else
			q.push(node->getLeft());
			
		if(node->getRight()==NULL)
			q.push(&empty);		//We insert 0's where there is no node so that when we print the non-existing nodes we print them as X
		else
			q.push(node->getRight());
		if(count==pow(2,d)-1)
			break;
}
}


int main()
{
	BinarySearchTree bt;
	string file;
	cout<<"Please enter the name of the file you want to read"<<endl;
	cin>>file;
	ifstream myfile(file);
	ofstream my_file("output.txt");	//To read the contents of the file and store it in a Binary Tree
	string line;
	if(myfile.is_open()) //if the file does not open it will print out an error
	{	
		if(my_file.is_open())
		{
			while(getline(myfile,line))
			{
	//			cout<<line<<endl;
				if(line!=" ")
				{
					int number = stoi(line);	//Convert the string into an integer
					bt.insert(number);
					int h = bt.sc(number);
					my_file<<number<<" ["<<h<<"], ";
				}
			}
			my_file.close();
		}
		myfile.close();
	}
	cout<<"\nThe Total number of nodes is "<<bt.nodes()<<endl;	//Total number of nodes in the tree
	cout<<endl;

//	bt.print_tree();
if(bt.nodes()<=16)
{
	cout<<"The tree in order:\n";
	OutputTreeLevelByLevel(bt);
}
else
	cout<<"The tree is too large to be printed.\n";
//	cout<<"\nThe tree in order:\n";
	cout<<endl;
	int number=0;
	
	
	cout<<"In which way you want the tree to be printed, Enter the number:"<<endl;
	cout<<"1. In order Traversal"<<endl;
	cout<<"2. Pre order Traversal"<<endl;
	cout<<"3. Post order Traversal"<<endl;
	cin>>number;
	if(number==1){
	cout<<"\nIn Order Traversal:"<<endl;
	if(bt.nodes()>16)cout<<"Output is in the text file named example as the number of nodes of the tree is more than 16"<<endl;
	bt.inorder();
	cout<<"\nAverage Search Cost="<<bt.avg()<<endl;
	}
	else if(number==2){
	cout<<"\nPre Order Traversal:"<<endl;
	if(bt.nodes()>16)cout<<"Output is in the text file named example as the number of nodes of the tree is more than 16"<<endl;
	bt.preorder();
	cout<<"\nAverage Search Cost="<<bt.avg()<<endl;
	}
	else{
	cout<<"\nPost Order Traversal:"<<endl;
	if(bt.nodes()>16)cout<<"Output is in the text file named example as the number of nodes of the tree is more than 16"<<endl;
	bt.postorder();
	cout<<"\nAverage Search Cost="<<bt.avg()<<endl;
	}
	
	cout<<"\nEnter the number you want to remove:"<<endl;
	cin>>number;
	bt.remove(number);	
	cout<<"\nIn Order Traversal:"<<endl;
	if(bt.nodes()>16)cout<<"Output is in the text file named example as the number of nodes of the tree is more than 16"<<endl;
	bt.inorder();
//	bt.printTree();	
}