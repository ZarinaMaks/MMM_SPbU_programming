struct Node
{
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

class BSTree
{

private:

    Node* Root;
    Node* AddLeafPrivate(int key, Node* Ptr, Node* parent);

    void RemoveSubTree(Node* Ptr);
    void PrintInOrderPrivate(Node* Ptr);
    int HeightOfTreePrivate(Node* Ptr);
    int DepthOfTreePrivate(Node* Ptr);

public:

    BSTree();
    ~BSTree();
    Node* CreateLeaf(int key, Node* Ptr);
    Node* AddLeaf(int key);
    void PrintInOrder();
    int HeightOfTree();
    int DepthOfTree(Node* Ptr);

};