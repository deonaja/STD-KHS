#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>

using namespace std;

typedef int infotype;
typedef struct node* adrNode;

struct node {
    infotype info;
    adrNode left;
    adrNode right;
};

adrNode newNode_103032300101(infotype x);
adrNode findNode_103032300101(adrNode root, infotype x);
void insertNode_103032300101(adrNode &root, adrNode p);
void DeleteNode_103032300101(adrNode &root, adrNode &p);
void printInOrder_103032300101(adrNode root);
adrNode findMin_103032300101(adrNode root);
adrNode findMax_103032300101(adrNode root);


#endif // TREE_H_INCLUDED
