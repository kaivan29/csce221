#include <iostream>
#include <fstream>
#include <cstddef>
#include <vector>
#include "binarynode.h"

using namespace std;

class BinarySearchTree
{
	private: 
		BinaryNode *root;		//The root of the tree
		int count=0; int n=0; int c=0;
		int prin[10][10];
		void deleteTree(BinaryNode *node);
		BinaryNode* insert(int x, BinaryNode *node, int count);		//To insert the node into the tree we are building
		BinaryNode* inorder(BinaryNode* node);			//To sort the the elements of the tree using in-order algortihm
		BinaryNode* preorder(BinaryNode *node);			//To sort the the elements of the tree using pre-order algortihm
		BinaryNode* postorder(BinaryNode *node);		//To sort the the elements of the tree using post-order algortihm
		BinaryNode* findMin(BinaryNode *node);			//To find the minimum value in the tree
		BinaryNode* removeMin(BinaryNode *node);		//To remove the minimum value in the tree
		BinaryNode* remove(int x, BinaryNode *node);	//To remove the particular element the user wants to remove
		int height(int x, BinaryNode *node);			//To
		int depth(BinaryNode* node);					//To calculate the depth of the particular node from its root
		
		// some private functions will be here
	public: // constructor
//1
		BinarySearchTree()
		{
			root = NULL;
		}
//2
		BinaryNode* getRoot()	//Returns the root of the tree
		{
			return root;
		}
//3
		bool isEmpty()		//To check if the tree is empty or not
		{
			return root==NULL;
		}
//4		//insert
		void insert(int x)	//User only has to give the element that calls the insert by passing the element root and the count that we need to find the searchcost 
		{	
			root = insert(x,root,0);
		}
//5		//in-order
		void inorder()
		{
			inorder(root);
		}
//6		//pre-order
		void preorder()
		{
			preorder(root);
		}
//7		//post-order
		void postorder()
		{
			postorder(root);
		}
//7		
		double avg()		//To calculate the average searchcost
		{
			double average = double(count)/double(n);
			return average;
		}
//8		
		int nodes()			//Number of nodes present in the tree
		{
			return n;
		}
//9		
		void remove(int x)
		{
			root = remove(x,root);
		}
//10
		int sc(int x) 
		{	
			int h =0;
			if(root == NULL)
				h=1;
			else
				h = height(x,root);
			return h+1;
		//cout<<"["<<h+1<<"] ,";
		}
//11
		int depth()
		{
			int d = depth(root);
			return d;
		}
};

//private functions
//1
void BinarySearchTree::deleteTree(BinaryNode *node)
{
	if(node==NULL)
		return;
	else if(node->left != NULL)
		deleteTree(node->left);
	else if(node->right != NULL)
		deleteTree(node->right);
	delete node;
}
//2
BinaryNode *BinarySearchTree::insert(int x, BinaryNode *node, int c_root) //throw(DuplicateItem)
{
	if (node == NULL)
	{
		n++; //number of nodes
		c_root++; //searchcost
		node = new BinaryNode(x,c_root);
		cout<<"\nKey = "<<node->key;
		cout<<"   SearchCost="<<node->searchCost;
		count +=node->searchCost; //total count
//		print[node->searchCost].push_back(node->key);
		c_root = 0;
//		std::cout<<"SearchCost:"<<sc(x)<<std::endl;
	}
	else if (x < node->Key()) 
	{
		c_root++;
		node->left = insert(x, node->left,c_root);
	}
	else if (x > node->Key())
	{
		c_root++;
		node->right = insert(x, node->right,c_root);
	}
	return node;
}

//3. searchcost
int BinarySearchTree::height(int x, BinaryNode *node)
{
	while(node!=NULL)
	{
		if(x<node->key)
		{
			node=node->left;
			c++;
		}
		else if(x>node->key)
		{
			node=node->right;
			c++;
		}
		else
		{
			int a = c;
			c=0;
			return a;
		}
	}
}
//4
ofstream myfile("example.txt"); //has the elements of the tree whose nodes are greater than 16
BinaryNode *BinarySearchTree::inorder(BinaryNode *node)
{
	if(node->left!=NULL)inorder(node->left);
	int s = sc(node->key);
	if(n<=16)
	{
		cout<<node->key;
		cout<<"["<<s<<"]"<<",";
	}
	else
	{
		if(myfile.is_open())
			{
				myfile<<node->key<<" ["<<s<<"]\n";
			}
	}
	if(node->right!=NULL)inorder(node->right);
}
//5
BinaryNode *BinarySearchTree::preorder(BinaryNode *node)
{
	int s = sc(node->key);
	if(n<=16)
	{
		cout<<node->key;
		cout<<"["<<s<<"]"<<",";
	}
	else
	{
		if(myfile.is_open())
			{
				myfile<<node->key<<" ["<<s<<"]\n";
			}
	}
	//	cout<<"["<<node->searchCost<<"]"<<",";
	if(node->left!=NULL)preorder(node->left);
	if(node->right!=NULL)preorder(node->right);
}
//6
BinaryNode *BinarySearchTree::postorder(BinaryNode *node)
{
	if(node->left!=NULL)postorder(node->left);
	if(node->right!=NULL)postorder(node->right);
	int s = sc(node->key);
	if(n<=16)
	{
		cout<<node->key;
		cout<<"["<<s<<"]"<<",";
	}
	else
	{
		if(myfile.is_open())
			{
				myfile<<node->key<<" ["<<s<<"]\n";
			}
	}
	//	cout<<"["<<node->searchCost<<"]"<<",";
}
//7
BinaryNode *BinarySearchTree::findMin(BinaryNode *node)
{
	if(node == NULL)
	{
		cout<<"Item not found"<<endl;
		return node;
	}
	else{
		while(node->left!=NULL)node = node->left;
		return node;
	}
}
//8
BinaryNode *BinarySearchTree::removeMin(BinaryNode *node)
{
	if(node==NULL)
	{
		cout<<"Item not found";
		return node;
	}
	if(node->left!=NULL)
		node->left = removeMin(node->left);
	else{
		BinaryNode *t = node;
		node = node->right;
		delete t;
	}
	return node;
}
//9
BinaryNode *BinarySearchTree::remove(int x, BinaryNode *node)
{
	if(node == NULL)
	{
		cout<<"Item not found";
		return node;
	}
	else{
		if(x<node->key)
			node->left=remove(x,node->left);
		else if(x>node->key)
			node->right=remove(x,node->right);
		else if(node->left!=NULL&&node->right!=NULL)
		{
			node->key=findMin(node->right)->key;
			node->right=removeMin(node->right);
		}
		else //node with one child
		{
			BinaryNode *t=node;
			node =(node->left!=NULL)?node->left : node->right;
			delete t;
		}
			return node;
}
}
//10
int BinarySearchTree::depth(BinaryNode* node)
{
   if (node==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = depth(node->left);
     int rheight = depth(node->right);
 
     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
} 

