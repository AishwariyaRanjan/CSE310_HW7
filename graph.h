//graph.h
#include <cstddef>
#ifndef Graph_H
#define Graph_H

struct Edge
{

    int start, end;
    int weight;
};

class Graph
{
public:
    int num_nodes, num_edges;
    int **G;

    //constructors
    Graph(); //default constructor
    Graph(int numNodes, int numEdges);

    int get_num_edges() const;
    int get_num_nodes() const;

    ~Graph();
};
#endif
