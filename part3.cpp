//part3.cpp
#include "graph.h"
#include "part1.h"
#include "part2.h"
#include "part3.h"
#include <fstream>
#include <iostream>

Edge *Part3(int **S, int *O, Graph graph)
{
    //storing paths of all possible lengths

    int Osize = get_size_of_O(graph);

    Edge **path;
    path = new Edge *[Osize];
    for (int i = 1; i <= Osize; i++)
    {
        path[i] = new Edge[Osize];
    }
    int col = 1;
    for (int x = 1; x < Osize; x++)
    { // checks if edge in S is of length 1...numNodes
        for (int i = 1; i < Osize; i++)
        { //iterates through paths of diff lenghts
            for (int j = 1; j <= Osize; j++)
            { // iterates through edges of one path length

                if (S[i][j] == x && O[i] < O[j])
                {
                    path[x][col].start = O[i];
                    path[x][col].end = O[j];

                    col++;
                }
            }
        }
        col = 1;
    }
    //printing path
    // std::cout << "printing path:" <<std::endl;
    // for(int i=1; i<Osize; i++){
    //     std::cout << "path length "<< i ;
    //     for(int j=1; j<=Osize; j++){
    //         if(path[i][j].start!=0 && path[i][j].end !=0)
    //             std::cout << "("<< path[i][j].start <<","<<path[i][j].end<<") ";
    //     }
    //     std::cout<<std::endl;
    // }

    //initialize array M with -1
    Edge *M = new Edge[Osize];
    for (int i = 1; i <= Osize; i++)
    {
        M[i].start = -1;
        M[i].end = -1;
    }

    M[1].start = path[1][1].start;
    M[1].end = path[1][1].end;
    M[1].weight = 1;

    int index = 2;
    int k = 1;
    bool match = true;
    for (int i = 1; i <= Osize; i++)
    {
        for (int j = 1; j <= Osize; j++)
        {

            //if(M[k].start != -1 && M[k].end != -1 ){
            for (int n = 1; n < index; n++)
            {
                if ((path[i][j].start != M[n].start && path[i][j].start != M[n].end) && (path[i][j].end != M[n].start && path[i][j].end != M[n].end))
                {
                    match = false;
                }
                else
                {
                    match = true;
                    break;
                }
            }

            if (match == false && path[i][j].start != 0 && path[i][j].end != 0)
            {
                M[index].start = path[i][j].start;
                M[index].end = path[i][j].end;
                M[index].weight = i;
                index++;
            }
            //}
        }
    }

    return M;

    for (int i = 1; i <= Osize; i++)
    {
        delete[] path[i];
    }
    delete[] path;

    delete[] M;
}
