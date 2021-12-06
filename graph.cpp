//graph.cpp
#include "graph.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include "stdio.h"
using namespace std;

//initializing graph constructor
Graph::Graph(int numNodes, int numEdges)
{

	num_nodes = numNodes;
	num_edges = numEdges;

	//create dynamic array of pointers
	G = new int *[numNodes];

	//create row for every pointer
	for (int i = 0; i <= numNodes; i++)
	{
		G[i] = new int[numNodes];

		//initialize adj matrix with 0
		memset(G[i], 0, numNodes * sizeof(int));
	}
}

int Graph::get_num_edges() const
{
	return num_edges;
}
int Graph::get_num_nodes() const
{
	return num_nodes;
}

Graph::~Graph() {}
