#include <iostream>
#include <cstdlib>

#include "BSTree.h"
using namespace std;

BSTree::BSTree() {
    Root = NULL;

}
BSTree::Node* BSTree::CreateLeaf(int key) {
    Node* N = new node;
    N->key=key;
    N->left=NULL;
    N->right=NULL;
    return N;
}

BSTree::~BSTree() {
    RemoveSubTree(Root);
}
void BSTree::RemoveSubTree(BSTree::Node *Ptr) {
    if(Ptr != NULL)
    {
        if (Ptr->left != NULL)
        {
            RemoveSubTree(Ptr->left);
        }
        if (Ptr->right != NULL)
        {
            RemoveSubTree(Ptr->right);
        }
        cout << Deleting Node containing key: << Ptr->key << endl;
        delete Ptr;
    }
}

void BSTree::AddLeaf(int key){
    AddLeafPrivate(key, Root);
}
void BSTree::AddLeafPrivate(int key, Node* Ptr){
    if(Root == NULL)
    {
        Root = CreateLeaf(key);
    }
    else if(key < Ptr->key)
    {
        if(Ptr->left != NULL)
        {
            AddLeafPrivate((key, Ptr->left));
        }
        else
        {
            Ptr->left = CreateLeaf(key);
        }
    }
    else if(key > Ptr->key)
    {
        if(Ptr->right != NULL)
        {
            AddLeafPrivate((key, Ptr->right));
        }
        else
        {
            Ptr->right = CreateLeaf(key);
        }
    }
    else
    {
        cout << "The key" << key << "has already been added to the BSTree.\n"
    }
}

void BSTree::PrintInOrder() {
    PrintInOrderPrivate(Root);
}
void BSTree::PrintInOrderPrivate(Node* Ptr){
    if (Root != NULL)
    {
        if (Ptr->left != NULL)
        {
            PrintInOrderPrivate(Ptr->left);
        }
        cout << Ptr->Key << " ";
        if (Ptr->right != NULL)
        {
            PrintInOrderPrivate(Ptr->right);
        }
    }
    else
    {
        cout << "The BSTree is empty.\n";
    }
}

int HeightOfTree(Node* Ptr) {
    if (Ptr == 0) {
        return 0;
    }
    int left, right;
    if (Ptr->left != NULL) {
        left = HeightOfTree(Ptr->left);
    } else {
        left = -1;
    }
    if (Ptr->right != NULL) {
        right = HeightOfTree(Ptr->right);
    }
    else {
        right = -1;
    }
    int max = left > right ? left : right;
    return max+1;

}
int DepthOfTree(Node* Ptr){
    if(Ptr->parent == NULL)
    {
        return 0;
    }
    else
    {
        return 1+DepthOfTree(Ptr->parent);
    }
}
