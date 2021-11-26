#include "util.h"
#include "graph.h"
#include "graph.cpp"
#include <fstream>
#include <iostream>
using namespace std;

Graph buildGraph(File file){

    ifstream myFile(file);
    myFile.open(file);
    myFile.ignore(1,'\n');

    //marking edges in the matrix
    for (int i=1; i<=num_edges; i++){
        int x, y;
        
        myFile >> x >> y;
        G[x][y] = 1;
        G[y][x] = 1;
    }
    myFile.close();
    return G;

}