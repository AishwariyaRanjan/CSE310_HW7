#include "graph.cpp"
#include "part1.cpp"
#include <fstream>
#include <iostream>
using namespace std;

Graph Part2(Graph G){
    int GF[G.get_num_nodes()][G.get_num_nodes()];
    //copying G into S
    for(int i=0; i<G.get_num_nodes(); i++){
        for(int j=0; j<G.get_num_nodes(); j++){
            GF[i][j] = G[i][j];
        }
    }

    //Floyed Warshall
    for(k=0; k < G.get_num_nodes(); k++){
        for(int i=0; i<G.get_num_nodes(); i++){
            for(int j=0; j<G.get_num_nodes(); j++){

                if(GF[i][j] != 1 && (i!=j)){
                    if(GF[i][j] == 0)
                        GF[i][j] = GF[i][k] + GF[k][j];
                    else {
                        if(GF[i][j] > (GF[i][k]+GF[k][j]))
                             GF[i][j] = GF[i][k] + GF[k][j];
                    }
                }

            }
        }
    }

    //outputting odd degree rows and columns
    int Osize = Part1_k(G);
    int S[Osize][Osize];

    for(int i=0; i<Osize; i++){
        for(int j=0; j<Osize; j++){
              S[i][j] = GF[O[i]][O[j]];
        }
    }

    return S;
}