#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    int x[9] = {8,6,15,4,7,12,17,9,13};
    int y[9] = {8,9,12,13,15,17,7,6,4};
    adrNode root = NULL;
    for (int i=0; i<9; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    adrNode P = NULL;
    for (int i=0; i<9; i++){
        insertNode_103032300101(root, newNode_103032300101(x[i]));
    }
    cout << endl;
    for (int i=0; i<10; i++){
        if (root != NULL){
            printInOrder_103032300101(root);
            cout << endl;
            P = findNode_103032300101(root, y[i]);
            DeleteNode_103032300101(root, P);
        }else{
            cout << "(kosong)";
        }
    }
    return 0;
}
