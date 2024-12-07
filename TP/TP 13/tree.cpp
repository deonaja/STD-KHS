#include "tree.h"

adrNode newNode(int x) {
    adrNode p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

adrNode findNode(adrNode root, int x) {
    if (root == NULL || root->info == x) {
        return root;
    }
    if (x < root->info) {
        return findNode(root->left, x);
    } else {
        return findNode(root->right, x);
    }
}

void insertNode(adrNode &root, adrNode p){
    if (root == NULL) {
        root = p;
    } else if (p->info < root->info) {
        insertNode(root->left, p);
    } else if (p->info > root->info) {
        insertNode(root->right, p);
    }
}

void printPreOrder(adrNode root) {
    if (root != NULL) {
        cout << root->info << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printDecendant(adrNode root, int x) {
    adrNode node = findNode(root, x);
    if (node != NULL) {
        printPreOrder(node->left);
        printPreOrder(node->right);
    } else {
        cout << "Node Tidak Ditemukan" << endl;
    }
}

int sumNode(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    return root->info + sumNode(root->left) + sumNode(root->right);
}

int countLeaves(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

int heightTree(adrNode root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = heightTree(root->left);
    int rightHeight = heightTree(root->right);
    return 1 + max(leftHeight, rightHeight);
}
