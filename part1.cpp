#include "util.cpp"
#include <fstream>
#include <iostream>
using namespace std;

int k=0;

int * Part1(Graph G){
int counter=0;
int O[G.get_num_edges()];
//int k=0;

    for(int i=1; i <= num_nodes; i++){
        for(int j=1; j <= num_nodes; j++){
            if(G[i][j]==1)
                counter++;
        }
        if(counter%2 != 0){
            O[k] = i;
            k++
        }
    }
    return O;
}

int get_k(){
    return k;
}
