//util.cpp
#include "util.h"
////#include "graph.h"
#include "stdio.h"
#include "stdlib.h"
////#include "graph.cpp"
//#include <fstream>
#include <iostream>
using namespace std;

bool Stack::push(int x, int y)
{
    if (top >= (MAX - 1))
    {
        std::cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top].start = x;
        a[++top].end = y;
        std::cout << "(" << a[++top].start << ", " << a[++top].end << ") pushed into stack\n";
        return true;
    }
}

void Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        //return 0;
    }
    else
    {
        a[top].start = 0;
        a[top].end = 0;
        top--;
    }
}
// Edge Stack::peek()
// {
//     if (top < 0) {
//         cout << "Stack is Empty";
//         return 0;
//     }
//     else {
//         Edge x = a[top];
//         return x;
//     }
// }

bool Stack::isEmpty()
{
    return (top < 0);
}
//
//Graph build_graph(std::fstream& file){
//
//    ifstream myFile(file);
//    myFile.open(file);
//
//
//    //marking edges in the matrix
//    int x, y;
//    int nodes, edges;
//
//    myFile >> nodes >> edges;
//
//	Graph graph= new Graph(nodes, edges);
//	//int G[nodes][nodes];
//    //myFile >> numVertices;
//   // myFile.ignore(1,'\n');
//    // Vertice v[numVertices]; // array to hold vertices of the graph
//    // int index=0;
//
//    for (int i=1; i<=graph.get_num_edges(); i++){
//
//        myFile >> x >> y;
//        graph.G[x][y] = 1;
//        graph.G[y][x] = 1;
//        //Store value of vertice
//        // NOT COMPLETE -- how to check if x/y in v
//        // for(int j =0; j <=i; j++){
//        //     if(v[j].value != x   ||   v[j].value != y){
//        //         v[index].value = x;
//        //         v[index+1].value = y;
//        //         index+=2;
//        //     }
//        // }
//    }
//    myFile.close();
//    return graph;
//
//}
//
//Graph build_weighted_graph(Graph G, Edge M[]){
//    //Graph newG = G;
//
//    for(int i=0; i<G.get_num_nodes; i++){
//        for(int j=0; j<G.get_num_nodes; j++){
//            newG[i][j] = G[i][j];
//
//    }
//    for(int i=1; i<M.length; i++){
//        for(int j=1; j<M.length; j++){
//            newG[M[i].start][M[i].end] = M[i].weight;
//            newG[M[i].end][M[i].start] = M[i].weight;
//    }
//
//}
//
