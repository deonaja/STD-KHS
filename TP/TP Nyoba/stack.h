#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>

using namespace std;
typedef char infotype;

struct stack{
   infotype info[15];
   int top;
};

void createStack_103032300035(stack &S);
bool isEmpty_103032300035(stack S);
bool isFull_103032300035(stack S);
void push_103032300035(stack &S, infotype x);
infotype pop_103032300035(stack &S);
void printinfo_103032300035(stack S);



#endif // STACK_H_INCLUDED
