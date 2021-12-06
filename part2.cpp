//part2.cpp
#include "part2.h"
#include "graph.h"
#include "part1.h"
#include <cstring>
#include "stdio.h"
#include <iostream>
using namespace std;

int **Part2(Graph graph, int *O)
{

    int GF[graph.get_num_nodes()][graph.get_num_nodes()];
    //copying G into new matrix, GF
    for (int i = 1; i <= graph.get_num_nodes(); i++)
    {
        for (int j = 1; j <= graph.get_num_nodes(); j++)
        {
            GF[i][j] = graph.G[i][j];
        }
    }

    //Floyd Warshall
    for (int k = 1; k <= graph.get_num_nodes(); k++)
    {
        for (int i = 1; i <= graph.get_num_nodes(); i++)
        {
            for (int j = 1; j <= graph.get_num_nodes(); j++)
            {

                if (GF[i][j] != 1 && (i != j))
                {
                    if (GF[i][j] == 0 && GF[i][k] != 0 && GF[k][j] != 0)
                        GF[i][j] = GF[i][k] + GF[k][j];
                    else
                    {
                        if (GF[i][j] >= (GF[i][k] + GF[k][j]))
                            GF[i][j] = GF[i][k] + GF[k][j];
                    }
                }
            }
        }
    }

    //outputting odd degree rows and columns
    int **S;
    int Osize = get_size_of_O(graph);

    S = new int *[Osize];

    for (int i = 1; i <= Osize; i++)
    {
        S[i] = new int[Osize];

        //initialize adj matrix with 0
        memset(S[i], 0, Osize * sizeof(int));
    }

    for (int i = 1; i < Osize; i++)
    {
        for (int j = 1; j < Osize; j++)
        {
            S[i][j] = GF[O[i]][O[j]]; //O[i],O[j] are the vertices, together they form edge
        }
    }

    // std::cout << "Results of Flod-Warshall on O: " << std::endl;
    // //print flyod warshall on O resulting matrix

    // std::cout << "   |\t";
    // for(int i =1; i < Osize; i++){
    //     std::cout << O[i] << "\t" ;
    // }
    // std::cout << endl;

    // for(int i =1; i<= Osize+2; i++){
    //      std::cout <<  "------" ;
    // }
    //  std::cout << endl;

    // for(int i =1; i < Osize; i++){
    //     std::cout << O[i] ;
    //     for(int j =1; j < Osize; j++){
    //         std::cout << "  |\t" << S[i][j] << " " ;
    //     }
    //     std::cout << endl;
    // }
    // std::cout << endl;

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
    for (int i = 1; i <= Osize; i++)
    {
        delete[] S[i];
    }
    delete[] S;
}
