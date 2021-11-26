
class Graph{
    public:
    int num_nodes=0, num_edges=0;
    int* G = NULL;

    //constructor
    Graph(File file);

    int get_num_edges();
    int get_num_nodes();

    ~Graph();

   
};