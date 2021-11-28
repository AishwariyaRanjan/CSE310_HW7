#include "graph.h"
#include <fstream>
#include <iostream>
using namespace std;

// Edge::Edge(int startEdge, int endEdge){
//     start = startEdge;
//     end = endEdge;
// }

Graph::Graph(File file){

    ifstream myFile;
    myFile.open(file);

    //create 2D array for adjecentcy matrix using input file
    myFile >> num_nodes >> num_edges;
    G = new int [num_nodes+1][num_nodes+1];

    //initialize matrix with 0s
    for (int i=0; i<=num_nodes; i++){
        for(int j=0; j<=num_nodes; j++){
            G[i][j] = 0;
        }
    }
    myFile.close();
}

Graph::get_num_edges(){
    return num_edges;
}
Graph::get_num_nodes{
    return num_nodes;
}

Graph::~Graph(){ delete[] G;}