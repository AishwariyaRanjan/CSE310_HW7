struct Vertice{
    int value;
    Vertice* next;
}

struct Edge{
    
    int start, end;
    int weight;
 
    //Edge(int startEdge, int endEdge);
}

class Graph{
    public:
    int num_nodes=0, num_edges=0;
    int* G = NULL;

    //constructors
    Graph(File file);
    Graph();

    int get_num_edges();
    int get_num_nodes();

    ~Graph();

   
};