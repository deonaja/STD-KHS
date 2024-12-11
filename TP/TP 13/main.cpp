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
        insertNode_103032300101(root, newNode_103032300101(x[i]));
    }
    cout << "\nDelete Node 5\t\t: ";
    cout << deleteNode_103032300101(root, 5);
    cout << "\n\nPre Order\t: ";
    printPreOrder_103032300101(root);
    cout << "\n\nDecendent of Node 9\t: ";
    printDecendant_103032300101(root, 9);
    cout << "\n\nSum of BST Info\t\t: ";
    cout << sumNode_103032300101(root);
    cout << "\nNumber of Leaves\t: ";
    cout << countLeaves_103032300101(root);
    cout << "\nHeight of Tree\t\t: ";
    cout << heightTree_103032300101(root);
    printf("\n================================================================================");
    return 0;
}
