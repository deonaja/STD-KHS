#include "tree.h"

adrNode newNode_103032300101(int x) {
    adrNode p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

adrNode findNode_103032300101(adrNode root, int x) {
    if (root == NULL || root->info == x) {
        return root;
    }
    if (x < root->info) {
        return findNode_103032300101(root->left, x);
    } else {
        return findNode_103032300101(root->right, x);
    }
}

void insertNode_103032300101(adrNode &root, adrNode p){
    if (root == NULL) {
        root = p;
    } else if (p->info < root->info) {
        insertNode_103032300101(root->left, p);
    } else if (p->info > root->info) {
        insertNode_103032300101(root->right, p);
    }
}

adrNode deleteNode_103032300101(adrNode &root, int x) {
    if (root != NULL) {
        if (x < root->info) {
            root->left = deleteNode_103032300101(root->left, x);
        } else if (x > root->info) {
            root->right = deleteNode_103032300101(root->right, x);
        } else {
            if (root->left == NULL) {
                adrNode temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                adrNode temp = root->left;
                delete root;
                return temp;
            }
            adrNode temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->info = temp->info;
            root->right = deleteNode_103032300101(root->right, temp->info);
        }
    }
    return root;
}

void printPreOrder_103032300101(adrNode root) {
    if (root != NULL) {
        cout << root->info << " ";
        printPreOrder_103032300101(root->left);
        printPreOrder_103032300101(root->right);
    }
}

void printDecendant_103032300101(adrNode root, int x) {
    adrNode node = findNode_103032300101(root, x);
    if (node != NULL) {
        if (node->left != NULL) {
            cout << node->left->info << " ";
            printDecendant_103032300101(node->left, node->left->info);
        }
        if (node->right != NULL) {
            cout << node->right->info << " ";
            printDecendant_103032300101(node->right, node->right->info);
        }
    } else {
        cout << "Node Tidak Ditemukan" << endl;
    }
}

int sumNode_103032300101(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    return root->info + sumNode_103032300101(root->left) + sumNode_103032300101(root->right);
}

int countLeaves_103032300101(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves_103032300101(root->left) + countLeaves_103032300101(root->right);
}

int heightTree_103032300101(adrNode root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = heightTree_103032300101(root->left);
    int rightHeight = heightTree_103032300101(root->right);
    return 1 + max(leftHeight, rightHeight);
}
