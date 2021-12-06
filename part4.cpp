//part4.cpp
#include "util.h"
#include "graph.h"
#include "part1.h"
#include <iostream>
using namespace std;

void DFS(int V, int visited[], Graph graph, Stack s)
{
    visited[V] = 1;

    for (int i = 1; i < graph.get_num_nodes(); i++)
        if (graph.G[V][i] != 0 && visited[i] == 0)
        {                      //if edge exists between V and i
            s.push(V, i);      //push into stack]
            graph.G[V][i] = 0; //remove edge from G

            if (visited[i] = 0)
            {
                DFS(i, visited, graph, s);
            }
        }
}

void Part4(Graph newG, int startV)
{
    std::cout << "in part4" << std::endl;
    //Graph G = newG;
    int V = startV;
    Stack *s = new Stack;
    Stack *s1 = new Stack;

    Edge circuit[newG.get_num_edges()];
    int visited[newG.get_num_nodes()];

    //initialize array visited with 0s
    for (int i = 0; i < newG.get_num_nodes(); i++)
    {
        visited[i] = 0;
    }

    //explore all vertices one by one
    DFS(V, visited, newG, *s);
    DFS(V, visited, newG, *s1);

    //print Stack
    std::cout << "stack contents: ";
    for (s1; !s1->isEmpty(); s1->pop())
    {
        std::cout << s1->top << " ";
    }
}
