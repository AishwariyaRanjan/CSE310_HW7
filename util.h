#include <bits/stdc++.h>
#define MAX 1000

Graph build_graph(File file);
Graph build_weighted_graph(Graph G, Edge M[]);

/* C++ program to implement basic stack
   operations */
class Stack {
    int top;
 
public:
    int a[MAX]; // Maximum size of Stack
 
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
 
bool Stack::push(int x){};
 
int Stack::pop(){};

int Stack::peek(){};
 
bool Stack::isEmpty(){};
    
 