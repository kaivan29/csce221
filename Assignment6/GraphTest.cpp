#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{ 
		string str("test.txt");
		Graph graph(str);
		cout<<"\nThe graph in the form of Adjacency List structure of the graph is: \n";
		graph.PrintGraph();
		
		// for storing distances and extracting the minimum;  equivalent to Q and d[] on the slides
		int source = 0, dest =0;
		cout<<"Enter the source vertex: ";
		cin>>source;
		cout<<"Enter the destination vertex: ";
		cin>>dest;

		graph.Djikstra(source, dest);
	
		return 0;
}