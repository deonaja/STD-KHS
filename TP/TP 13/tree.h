#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct node* adrNode;

struct node {
    adrNode right;
    adrNode left;
    int info;
};

adrNode newNode_103032300101(int x);
adrNode findNode_103032300101(adrNode root, int x);
void insertNode_103032300101(adrNode &root, adrNode p);
adrNode deleteNode_103032300101(adrNode &root, int x);
void printPreOrder_103032300101(adrNode root);
void printDecendant_103032300101(adrNode root, int x);
int sumNode_103032300101(adrNode root);
int countLeaves_103032300101(adrNode root);
int heightTree_103032300101(adrNode root);


#endif // TREE_H_INCLUDED
