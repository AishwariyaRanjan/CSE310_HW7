//util.h

#include "graph.h"
//#include <bits/stdc++.h>
#define MAX 30
#ifndef UTILITY_H
#define UTILITY_H

///* C++ program to implement basic stack
//   operations */
class Stack
{

public:
    int top;
    Edge a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(int start, int end);
    void pop();
    int peek();
    bool isEmpty();
};

#endif
