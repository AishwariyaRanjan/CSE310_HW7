int main{
   Graph G = new Graph("graph.txt");
    G = build_graph("graph.txt");

    int* O = NULL;
    O = Part1(G);
    