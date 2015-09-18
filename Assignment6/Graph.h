#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "MPQheap.h"
#include <stack>

using namespace std;

class Edge;
class Vertex;

class Graph{

private:
	vector<Vertex*> vertList;
	vector<Edge*> edgeList;
public:
	Graph(string filename) {
    //
    //  The vertex with ID x is stored at vertList[x-1]; 
    //  for example, vertex 1 in vertList[0], vertex 2 in vertList[1] and so on. 
    //
		ifstream ifs(filename.c_str());
		int vertnum;
		ifs>>vertnum;
		for(int i=0;i<vertnum;i++) // push all vertices into the vertex vector before assigning the in and out list
		{
			Vertex *vert = new Vertex(i+1);
			vertList.push_back(vert);
		}
		int svert,evert,weit; 
		ifs>>svert; 
		while(svert!=-1)
		{
			ifs>>evert; 
			while(evert!=-1)
			{
				ifs>>weit; // one weight means one edge
                Edge *tempedge = new Edge(vertList[svert-1],vertList[evert-1],weit); // new edge
				edgeList.push_back(tempedge);				
				vertList[svert-1]->outList.push_back(tempedge);
				vertList[evert-1]->inList.push_back(tempedge);
				ifs>>evert; 
			}
			ifs>>svert; 
		}
		ifs.close();
	}
	~Graph() {
		for(int i = 0; i < vertList.size(); i++)
			delete vertList[i];
		for(int i = 0; i < edgeList.size(); i++)
			delete edgeList[i];
	}
  int getSize() {
    return vertList.size();
  }
  
  // There is no need of addEdge and addVertex if using the constructor
  
  vector<Vertex*> getVertices(){ return vertList;}
  vector<Edge*> getOutEdges(int vertID){return vertList[vertID-1]->getOutEdges();}
  vector<Edge*> getInEdges(int vertID){return vertList[vertID-1]->getInEdges();}
  Vertex* getVertex(int vertID){return vertList[vertID-1];}
  Edge* getEdge(int sVertID, int dVertID)
  {
	  for(int i=0;i<getSize();i++)
	  {
		if(edgeList[i]->getsVertP()->getID() == sVertID && edgeList[i]->geteVertP()->getID() == dVertID)
		 return edgeList[i];
	  }
  }
  
  void PrintGraph(); // print out all the edges in the entire graph
  void Djikstra(int source, int dest);
};


//***************************************
void Graph::PrintGraph() //to print the graph in the form of adjacency list form from the file that we read in
{
	for(int i=0; i<getSize(); i++)
	{	
		cout<<vertList[i]->getID()<<" ";
		for( int j=0; j<vertList[i]->getOutEdges().size(); j++)		//the number of adjacent edges is tell where the loop should run till
		{	
			cout<<" "<<vertList[i]->getOutEdges()[j]->geteVertP()->getID()<< " ";
			cout<<vertList[i]->getOutEdges()[j]->getWeight();
		}
		cout<<endl;
	}
}



void Graph::Djikstra(int source, int dest)  //to get the shortest tree path and the shortest path between a source and destination given by the user
{
	int d[getSize()];	//to store the weight of the vertex
	int m[getSize()];	//to store the parent of the vertex
	int j = 0;
	int weight = 0;
	MPQheap h;	//MPQ used to store the elements and then removeMin() from it
	MPQheap p;
	//initialize each and every source
	for(int i =0; i<getSize(); ++i)
	{
		d[i] = 1000000;
		string elem = to_string(i+1);
		h.insertItem( d[i], elem, j);
		j++;
	}
//		h.print();
		d[source] = 0;
		m[source] = -1; //root has no parent;
		h.decreaseKey(d[source], to_string(source));
		h.setloc();
//		h.print();
	while(h.isEmpty()!=true)
	{	
		//for MPQ h
		Item l = h.minKey();
		h.removeKey();
		h.setloc();
		//for MPQ p
		p.insertItem(l.getKey(), l.getElem(), l.getLoc());
		//for checking the weight of the vertices and the edges
		int u = stoi(l.getElem());
		for( int j=0; j<getVertices()[stoi(l.getElem())-1]->getOutEdges().size(); j++)
		{	
			int v = getVertices()[stoi(l.getElem())-1]->getOutEdges()[j]->geteVertP()->getID();
			weight = getOutEdges(u)[j]->getWeight();//getEdge(u,v)->getWeight();
			if(weight > 0)
			{
				if(d[v]>d[u]+ weight)
				{//true
					d[v] = d[u]+weight; //change the d[] of the vertex v
					h.decreaseKey(d[v], to_string(v));	//restructure the heap
					m[v] = u;			//make u the parent of the v
					//join both the vertex
				}
			}
			else
				break;
		}
		if(weight < 0)
		{
			break;
		}
	}
	if(weight < 0)
	{
		cout<<"\nSorry the weight between one of the edged in the graph is negative and Dijkstra does not work with negative edges or negative cycle\n";
	}
	else
	{
		cout<<"The shortest path tree is: "<<endl;
	//to get the shortest path
	//We check if the source is connected to the shortest path tree
		if(d[dest]  > 10000)
		{
			cout<<"There is no path from this source: "<<source<<"to destination: "<<dest<<endl;
			return;
		}
		vector<int> v;
		v.push_back(dest);
		int parent = m[dest];
		//we check the parent of the destination and keep going upwards until we find the source
		while(parent!=source) //we see if the parent is not the root, if it is we exit out of the loop
		{	
			v.push_back(parent);
			parent = m[parent]; //look for the parent of the parent
		}
		v.push_back(source);  //and we pushback the root now
		int length = v.size();
		vector<int> v2 = v;
		//to print the edges
			while(v2.size()!=1)
		{	
			int svert = v2.back();
			v2.pop_back();
			int dvert = v2.back();
			cout<<"   "<<d[dvert]-d[svert];
		}
		cout<<endl;
		//to print the vertices
		for(int i =0; i<length; i++)
		{
			int svert = v.back();
			v.pop_back();
			cout<<svert;
			if(i<length-1)
				cout<<"--->";
		}
	}
}
#endif