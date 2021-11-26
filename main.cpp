#include "part1.cpp"
#include "part2.cpp"
#include "graph.cpp"
int main{
 //reading graph from input txt file
    Graph G = new Graph("graph.txt");
    G = build_graph("graph.txt");

 //getting and printing odd-degree nodes
    int* O = NULL;
    O = Part1(G);
    //int O[get_k()];

    cout << "The odd degree vertices in G: O{" ;
    
    int k = Part1_k(G);
    for(int i=0; i<k; i++){
        cout << O[i] << ", ";
    }

    cout << "}" ;


//Floyd-Warshall
    int S[G.get_num_nodes()][G.get_num_nodes()];
    S = Part2(G);
    






    return 0;
}