#include "tree.h"

adrNode newNode_103032300101(infotype x) {
    adrNode n = new node;
    n->info = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

adrNode findNode_103032300101(adrNode root, infotype x) {
    if (root == NULL || root->info == x) {
        return root;
    } else {
        if (root->info > x) {
            return findNode_103032300101(root->left, x);
        } else if (root->info < x) {
            return findNode_103032300101(root->right, x);
        }
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
void DeleteNode_103032300101(adrNode &root, adrNode &p) {
    adrNode temp;
    cout << root->info << "-\n";
    if (root == NULL) {
        cout << "TREE KOSONG" << endl;
    } else if (root->info < p->info) {
        DeleteNode_103032300101(root->right, p);
    } else if (root->info > p->info) {
        DeleteNode_103032300101(root->left, p);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if (root->right == NULL) {
            temp = root;
            root = root->left;
            delete temp;
        } else if (root->left == NULL) {
            temp = root;
            root = root->right;
            delete temp;
        } else {
            temp = findMax_103032300101(root->left);
            cout << temp->info << "=";
            root->info = temp->info;
            DeleteNode_103032300101(root->left, temp);
        }
    }

//    adrNode temp;
//    cout << root->info << "-";
//    if (root == NULL){
//        cout << "Node not found" << endl;
//    }else if (p->info < root->info){
//        DeleteNode_103032300101(root->left, p);
//    }else if (p->info > root->info){
//        DeleteNode_103032300101(root->right, p);
//    }else{
//        if (root->left == NULL && root->right == NULL){
//            delete root;
//            root = NULL;
//        }else if (root->left == NULL){
//            temp = root;
//            root = root->right;
//            delete temp;
//        }else if (root->right == NULL){
//            temp = root;
//            root = root->left;
//            delete temp;
//        }else{
//            temp = findMin_103032300101(root->right);
//            cout << temp->info << "=";
//            root->info = temp->info;
//            DeleteNode_103032300101(root->right, temp);
//        }
//    }
}
void printInOrder_103032300101(adrNode root) {
    if (root != NULL) {
        printInOrder_103032300101(root->left);
        cout << root->info << " ";
        printInOrder_103032300101(root->right);
    }
}
adrNode findMin_103032300101(adrNode root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

adrNode findMax_103032300101(adrNode root) {
    if (root == NULL) {
        return root;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
