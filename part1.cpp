//part1.cpp
//#include "util.cpp"
#include "part1.h"
#include <fstream>
#include "stdio.h"
#include <iostream>
using namespace std;

int *Part1(Graph graph)
{
    int k = 1;
    int counter = 0;
    int *O = new int[graph.get_num_nodes()];

    //traversing through the graph and checking if edge exists
    for (int i = 1; i <= graph.get_num_nodes(); i++)
    {
        for (int j = 1; j <= graph.get_num_nodes(); j++)
        {
            if (graph.G[i][j] == 1)
                counter++; //if edge exists, counter++
        }
        if (counter % 2 != 0)
        { //checking if there are odd number of edges for a node
            O[k] = i;
            k++;
        }
        counter = 0;
    }

    // std::cout <<"array O in part1 " ;
    // for(int i=1; i < k; i++){
    //     std::cout << O[i] << " " ;
    // }
    // std::cout << std::endl;

    return O;
    delete[] O;
}

//return k (size of O)
int get_size_of_O(Graph graph)
{
    int k = 1;
    int counter = 0;
    int *O = new int[graph.get_num_nodes()];
    //int k=0;

    for (int i = 1; i <= graph.get_num_nodes(); i++)
    {
        for (int j = 1; j <= graph.get_num_nodes(); j++)
        {
            if (graph.G[i][j] == 1)
                counter++;
        }
        if (counter % 2 != 0)
        {
            O[k] = i;
            k++;
        }
        counter = 0;
    }
    //std::cout <<"size of O " << sizeof(O)/sizeof(O[1])<< std::endl ;

    // std::cout <<"array O in part1 " ;
    // for(int i=1; i < k; i++){
    //     std::cout << O[i] << " " ;
    // }
    // std::cout << std::endl;

    // std::cout <<"array O in part1 " ;
    // for(int i=1; i < k; i++){
    //     std::cout << O[i] << " " ;
    // }
    //std::cout << "k in part1.cpp = " << k<<std::endl;

    return k;
}
