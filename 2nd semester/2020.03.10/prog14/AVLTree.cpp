#include "AVLTree.h"

//----------------AVLTree----------------//
template <typename T>
int AVLTree<T>::ReturnSLR() { return SLR_count; }

template <typename T>
int AVLTree<T>::ReturnSRR() { return SRR_count; }

template <typename T>
int AVLTree<T>::ReturnBLR() { return BLR_count; }

template <typename T>
int AVLTree<T>::ReturnBRR() { return BRR_count; }

template <typename T>
void  AVLTree<T>::Delete() {
    DeleteTree(root);
    BLR_count = 0;
    BRR_count = 0;
    SLR_count = 0;
    SRR_count = 0;
    root = NULL;
}

template <typename T>
void CreateTree(const int& number, AVLTree<T>& tree, const T& value)
{
    int* transpos = new int[number];
    Transposition(transpos, (int&)number);
    for (int i = 0; i < number; ++i)
    {
        tree.InsertIntoTree(value, transpos[i]);
    }
    delete[] transpos;
}

template <typename T>
Node<T>::Node(const T& CurValue, const int& CurKey)
{
    value = CurValue;
    key = CurKey;
    hight = 0;
    left = NULL; right = NULL;
}

template <typename T>
AVLTree<T>::AVLTree()
{
    root = NULL;
    BRR_count = 0; BLR_count = 0;
    SRR_count = 0; SLR_count = 0;
}
template <typename T>
AVLTree<T>::~AVLTree() {
    DeleteTree(root);
}

template <typename T>
void AVLTree<T>::DeleteTree(Node<T>* head) {
    if (head != NULL)
    {
        DeleteTree((*(head)).left);
        DeleteTree((*(head)).right);
        delete head;
    }
}

template <typename T>
int AVLTree<T>::ReturnHight(Node<T>* head) {
    if (head != NULL) {
        return (*(head)).hight;
    } else {
        return -1;
    }
}

template <typename T>
void AVLTree<T>::NewHight(Node<T>* head) {
    int left_h = ReturnHight((*(head)).left) + 1;
    int right_h = ReturnHight((*(head)).right) + 1;
    (*(head)).hight = (left_h > right_h) ? left_h : right_h; 
}

template <typename T>
int AVLTree<T>::HightDiff(Node<T>* head) {
    return ReturnHight((*(head)).right) - ReturnHight((*(head)).left);
}

template <typename T>
Node<T>** AVLTree<T>::next(const int& key, Node<T>* head) {
    if (key > (*(head)).key) {
        return &(*(head)).right;
    } else {
        return &(*(head)).left;
    }
}
//--------------------------------//



//----------------Rotations----------------//
template <typename T>
Node<T>* AVLTree<T>::SLR(Node<T>* head) {
    if (head != NULL) {
        if ((*(head)).right != NULL) {
            Node<T>* right = (*(head)).right;
            (*(head)).right = (*(right)).left;
            (*(right)).left = head;
            NewHight(head);
            NewHight(right);
            ++SLR_count;
            return right;
        } else {
            return head;
        }
    } else {
        return head;
    }
}

template <typename T>
Node<T>* AVLTree<T>::TreeBalance(Node<T>* head) {
    if (HightDiff(head) > 1) {
        if (HightDiff((*(head)).right) > 0) {
            return SLR(head);
        } else {
            return BLR(head);
        }
    } else if (HightDiff(head) < -1) {
        if (HightDiff((*(head)).left) > 0) {
            return BRR(head);
        } else {
            return SRR(head);
        }
    } else {
        return head;
    }
}

template <typename T>
void AVLTree<T>::InsertIntoTree(const T& value, const int& key) {
    vector<Node<T>**> UsedNodes;
    Node<T>** element = &root;
    while (*(element) != NULL) {
        UsedNodes.push_back(element);
        element = next(key, *(element));
    }
    *(element) = new Node<T>(value, key);
    for (int i = UsedNodes.size() - 1; i >= 0; --i) {
        NewHight(*(UsedNodes[i]));
        *(UsedNodes[i]) = TreeBalance(*(UsedNodes[i]));
    }
}

template <typename T>
Node<T>* AVLTree<T>::SRR(Node<T>* head) {
    if (head != NULL) {
        if ((*(head)).left != NULL) {
            Node<T>* left = (*(head)).left;
            (*(head)).left = (*(left)).right;
            (*(left)).right = head;
            NewHight(head);
            NewHight(left);
            ++SRR_count;
            return left;
        } else {
            return head;
        }
    } else {
        return head;
    }
}

template <typename T>
Node<T>* AVLTree<T>::BLR(Node<T>* head) {
    if (head != NULL) {
        if ((*(head)).right != NULL) {
            (*(head)).right = SRR((*(head)).right);
            ++BLR_count;
            --SRR_count;
            --SLR_count;
            return SLR(head);
        } else {
            return head;
        }
    } else {
        return head;
    }
}

template <typename T>
Node<T>* AVLTree<T>::BRR(Node<T>* head) {
    if (head != NULL) {
        if ((*(head)).left != NULL) {
            (*(head)).left = SLR((*(head)).left);
            ++BRR_count;
            --SRR_count;
            --SLR_count;
            return SRR(head);
        } else {
            return head;
        }
    } else {
        return head;
    }
}

void AverageAmount(const int& number) {
    AVLTree<int> tree;
    float SLR = 0, SRR = 0, BLR = 0, BRR = 0;
    int count = number / 10;
    for (int i = 0; i < count; ++i) {
        tree.Delete();
        CreateTree(number, tree, 1);
        BRR += tree.ReturnBRR();
        BLR += tree.ReturnBLR();
        SRR += tree.ReturnSRR();
        SLR += tree.ReturnSLR();
        SRR += tree.ReturnSRR();
    }

    cout << "   For number " << number << ": "<< endl;
    cout << "2) Big Right Rotation amount - " << BRR / count << endl;
    cout << "1) Big Left Rotation amount - " << BLR / count << endl;
    cout << "4) Small Right Rotation amount - " << SRR / count << endl;
    cout << "3) Small Left Rotation amount - " << SLR / count << endl;
    cout << endl;
}
//--------------------------------//



//----------------Array----------------//
bool IsChance(const double& chance) {
    return ((double)rand() / RAND_MAX) <= chance;
}

void Transposition(int* array, int& arrayNum) {
    int element = 0, j = 0;
    for (int i = 0; i < arrayNum; i++) {
        array[i] = -1;
    }
    while (element < arrayNum) {
        if (array[j] == -1 && IsChance((double) 1 / (arrayNum - element))) {
            array[j] = element;
            element++;
        }
        ++j;
        j %= arrayNum;
    }
}
//--------------------------------//

