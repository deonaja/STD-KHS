#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>

using namespace std;

typedef char infotype;
struct Stack {
    infotype info[15];
    int top;
};

void createStack_103032300101(Stack &s);
bool isEmpty_103032300101(Stack s);
bool isFull_103032300101(Stack s);
void push_103032300101(Stack &s, infotype x);
infotype pop_103032300101(Stack &s);
void printInfo_103032300101(Stack s);


#endif // STACK_H_INCLUDED
