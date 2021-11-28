#include "graph.cpp"
#include "part1.cpp"
#include <fstream>
#include <iostream>
using namespace std;

Graph Part2(Graph G, int * O){
    int GF[G.get_num_nodes()][G.get_num_nodes()];
    //copying G into S
    for(int i=0; i<G.get_num_nodes(); i++){
        for(int j=0; j<G.get_num_nodes(); j++){
            GF[i][j] = G[i][j];
        }
    }

    //Floyd Warshall
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
              S[i][j] = GF[O[i]][O[j]]; //O[i],O[j] are the vertices, together they form edge
        }
    }

    //print flyod warshall on O resulting matrix
    
    std::cout << "\t |\t";
    for(int i =0; i < O.length; i++){
        std::cout << O[i] << " " ; 
    }
    std::cout << endl;

    for(int i =0; i<O.length+2; i++){
         std::cout <<  "--- " ; 
    }
     std::cout << endl;

    for(int i =0; i < O.length; i++){
        std::cout << O[i] ;
        for(int j =0; j < O.length; j++){
            std::cout << "  |\t" << S[i][j] << " " ;
        }
        std::cout << endl;
    }
    std::cout << endl; 
    



// //storing paths of all possible lengths
//     Edge path[G.get_num_nodes()][G.get_num_nodes()];

//     for(int i=1; i<=G.get_num_nodes(); i++){ //iterates through paths of diff lenghts
//         for(int j=1; j<=G.get_num_nodes(); j++){ // iterates through edges of one path length
//             for(int x=1; x<=G.get_num_nodes(); x++) // checks if edge in S is of length 1...numNodes
//             if(S[i][j] == x){
//                 path[x][j]= new Edge(i,j);
//             }          
//         }        
//     }

    
    return S;
} 