#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    printf("================================================================================\n");
    adrNode root = NULL;
    int x[9] = {5,3,9,10,4,7,1,8,6};
    for (int i = 0; i < 9; i++) {
        cout << x[i] << " ";
        insertNode(root, newNode(x[i]));
    }
    cout << "\n\nPre Order\t: ";
    printPreOrder(root);
    cout << "\n\nDecendent of Node 9\t: ";
    printDecendant(root, 9);
    cout << "\n\nSum of BST Info\t\t: ";
    cout << sumNode(root);
    cout << "\nNumber of Leaves\t: ";
    cout << countLeaves(root);
    cout << "\nHeight of Tree\t\t: ";
    cout << heightTree(root);
    printf("\n================================================================================");
    return 0;
}
