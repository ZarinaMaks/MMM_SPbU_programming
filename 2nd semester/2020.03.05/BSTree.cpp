#include <iostream>
#include <cstdlib>

#include "BSTree.h"
using namespace std;

BSTree::BSTree() {
    Root = NULL;
}

Node* BSTree::CreateLeaf(int key, Node* Ptr) {
    Node* N = new Node;
    N->key=key;
    N->left=NULL;
    N->right=NULL;
    N->parent = Ptr;
    return N;
}

BSTree::~BSTree() {
    RemoveSubTree(Root);
}
void BSTree::RemoveSubTree(Node *Ptr) {
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
        cout << "Deleting Node containing key:" << Ptr->key << endl;
        delete Ptr;
    }
}

Node* BSTree::AddLeaf(int key){
    return AddLeafPrivate(key, Root, NULL);
}

Node* BSTree::AddLeafPrivate(int key, Node* Ptr, Node* parent){
    if(Root == NULL)
    {
        Root = CreateLeaf(key, NULL);
    }
    else if(key < Ptr->key)
    {
        if(Ptr->left != NULL)
        {
            AddLeafPrivate(key, Ptr->left, Ptr);
        }
        else
        {
            Ptr->left = CreateLeaf(key, Ptr);
            return Ptr->left;

        }
    }
    else if(key > Ptr->key)
    {
        if(Ptr->right != NULL)
        {
            AddLeafPrivate(key, Ptr->right, Ptr);
        }
        else
        {
            Ptr->right = CreateLeaf(key, Ptr);
            return Ptr->right;
        }
    }
    else
    {
        cout << "The key" << key << "has already been added to the BSTree.\n";
        return Ptr;
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
        cout << Ptr->key << " ";
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


int BSTree::HeightOfTree() {
    HeightOfTreePrivate(Root);
}


int BSTree::HeightOfTreePrivate(Node* Ptr) {
    if (Ptr == NULL) {
        return 0;
    }
    int left, right;
    if (Ptr->left != NULL) {
        left = HeightOfTreePrivate(Ptr->left);
    } else {
        left = -1;
    }
    if (Ptr->right != NULL) {
        right = HeightOfTreePrivate(Ptr->right);
    }
    else {
        right = -1;
    }
    int max = left > right ? left : right;
    return max+1;

}


int BSTree::DepthOfTree(Node* Ptr) {
    DepthOfTreePrivate(Ptr);
}
int BSTree::DepthOfTreePrivate(Node* Ptr){
    if(Ptr->parent == NULL)
    {
        return 0;
    }
    else
    {
        return 1+DepthOfTree(Ptr->parent);
    }
}
