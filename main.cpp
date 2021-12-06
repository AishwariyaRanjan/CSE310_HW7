#include "part1.h"
//#include "util.h"
#include <fstream>
#include "stdio.h"
#include <iostream>
#include "part2.h"
#include "part3.h"
//#include "part4.h"

int main()
{
    ///////////////reading graph from input txt file////////////////////////////////////////
    std::ifstream myFile;
    myFile.open("graph.txt");
    int x, y, nodes, edges;

    myFile >> nodes >> edges;

    Graph *graph = new Graph(nodes, edges);
    while (myFile.is_open())
    {
        for (int i = 1; i <= graph->get_num_edges(); i++)
        {

            myFile >> x >> y;
            graph->G[x][y] = 1;
            graph->G[y][x] = 1;
        }
        myFile.close();
    }

    // 	//printing adj matrix
    // 	for(int i=1; i<=nodes; i++){
    // 		for(int j=1; j<=nodes; j++){
    // 			std::cout << graph->G[i][j] << " ";
    // 		}
    // 		std::cout <<std::endl;
    // 	}

    ///////////////getting and printing odd-degree nodes////////////
    int *O = Part1(*graph);

    std::cout << "The odd degree vertices in G: O{";

    int k = get_size_of_O(*graph);
    for (int i = 1; i < k; i++)
    {
        std::cout << O[i] << " ";
    }

    std::cout << "}\n"
              << std::endl;

    /////////Floyd-Warshall/////////////////////////////////
    int **S = Part2(*graph, O);
    std::cout << "Results of Floyd-Warshall on O: " << std::endl;
    //print flyod warshall on O resulting matrix

    std::cout << "   |\t";
    for (int i = 1; i < k; i++)
    {
        std::cout << O[i] << "\t";
    }
    std::cout << std::endl;

    for (int i = 1; i <= k + 2; i++)
    {
        std::cout << "------";
    }
    std::cout << std::endl;

    for (int i = 1; i < k; i++)
    {
        std::cout << O[i];
        for (int j = 1; j < k; j++)
        {
            if (j == 1)
            {
                std::cout << "  |\t" << S[i][j] << " ";
            }
            else
                std::cout << "  \t" << S[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    ////////////////////perfect matching//////////////////////////////////////////
    Edge *M = Part3(S, O, *graph); //
    std::cout << "The greedy perfect matching in O: M = {";
    for (int i = 1; i < k; i++)
    {
        if (M[i].start != -1 && M[i].end != -1)
        {
            std::cout << "(" << M[i].start << "," << M[i].end << ") ";
            //std::cout << "weight" <<M[i].weight;
        }
    }
    std::cout << "}" << std::endl;

    ////////////adding virtual edges to G////////////

    Graph *newG = new Graph(nodes, edges);

    for (int i = 0; i < graph->get_num_nodes(); i++)
    {
        for (int j = 0; j < graph->get_num_nodes(); j++)
        {
            newG->G[i][j] = graph->G[i][j];
        }
    }

    for (int i = 1; i < k; i++)
    {
        for (int j = 1; j < k; j++)
        {
            if (M[i].start != -1 && M[i].end != -1)
            {
                newG->G[M[i].start][M[i].end] = M[i].weight;
                newG->G[M[i].end][M[i].start] = M[i].weight;
            }
        }
    }

    //printing newG
    // for(int i=0; i<graph->get_num_nodes(); i++){
    //     for(int j=0; j<graph->get_num_nodes(); j++){
    //         std::cout<< newG->G[i][j] << " ";
    //     }
    //     std::cout<<std::endl;

    // }

    //
    /////////////Printing Euler circuit///////////////////
    std::cout << "euler circuit" << std::endl;
    int startV = 1;
    //Part4(*newG, startV);

    std::cout << "end of main" << std::endl;
    delete[] M;
    delete[] O;
    // 	delete[][] newG;
    // 	delete[][] graph;

    return 0;
}
