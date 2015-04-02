#include <iostream>
#include <cstddef>

class BinaryNode
{
	private:
		friend class BinarySearchTree;		
		int key; int searchCost;		//key is the value stored in the node. searchcost is the number of searches made to find that particular number
		BinaryNode *left,*right, *parent;
	public:
		BinaryNode(int el=0, int sc=0, BinaryNode *lt=NULL, BinaryNode *rt=NULL, BinaryNode *pt=NULL):key(el),searchCost(sc),left(lt),right(rt),parent(pt){}
	//functions
		BinaryNode *getLeft() {return left;}		//To get the left child of the node
		BinaryNode *getRight() {return right;}		//To get the right child of the node
		BinaryNode *getParent() {return parent;}
		bool isRoot(){return parent == NULL;}		//To check if the node is a parent
		int Key(){return key;}						//To get the value in the node
};
