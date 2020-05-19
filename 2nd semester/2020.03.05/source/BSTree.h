class BSTree
{

private:
    struct Node
    {
        int key;
        Node* left;
        Node* right;
    };

    Node* Root;

    void AddLeafPrivate(int key, Node* Ptr);
    void RemoveSubTree(Node* Ptr);
    void PrintInOrderPrivate(Node* Ptr);
   // int HeightOfTreePrivate(Node* Ptr);

public:
    BSTree();
    ~BSTree();
    Node* CreateLeaf(int key);
    void AddLeaf(int key);
    void PrintInOrder();
    int HeightOfTree(Node* Ptr);
    int DepthOfTree(Node* Ptr);

};