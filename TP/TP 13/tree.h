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

adrNode newNode(int x);
adrNode findNode(adrNode root, int x);
void insertNode(adrNode &root, adrNode p);
void printPreOrder(adrNode root);
void printDecendant(adrNode root, int x);
int sumNode(adrNode root);
int countLeaves(adrNode root);
int heightTree(adrNode root);


#endif // TREE_H_INCLUDED
