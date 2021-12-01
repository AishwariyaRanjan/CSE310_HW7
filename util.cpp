#include "util.h"
#include "graph.h"
#include "graph.cpp"
#include <fstream>
#include <iostream>
using namespace std;

Graph build_graph(File file, Graph G){

    ifstream myFile(file);
    myFile.open(file);
    

    //marking edges in the matrix
    int x, y;
    int numVertices

    //myFile >> numVertices;
    myFile.ignore(1,'\n');
    // Vertice v[numVertices]; // array to hold vertices of the graph
    // int index=0;

    for (int i=1; i<=G.get_num_edges(); i++){
                
        myFile >> x >> y;
        G[x][y] = 1;
        G[y][x] = 1;
        //Store value of vertice 
        // NOT COMPLETE -- how to check if x/y in v
        // for(int j =0; j <=i; j++){
        //     if(v[j].value != x   ||   v[j].value != y){
        //         v[index].value = x;
        //         v[index+1].value = y;
        //         index+=2;
        //     }
        // }
    }
    myFile.close();
    return G;

}

Graph build_weighted_graph(Graph G, Edge M[]){
    //Graph newG = G;

    for(int i=0; i<G.get_num_nodes; i++){
        for(int j=0; j<G.get_num_nodes; j++){
            newG[i][j] = G[i][j];

    }
    for(int i=1; i<M.length; i++){
        for(int j=1; j<M.length; j++){
            newG[M[i].start][M[i].end] = M[i].weight;
            newG[M[i].end][M[i].start] = M[i].weight;
    }

}

bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}
 
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
 
bool Stack::isEmpty()
{
    return (top < 0);
}
 