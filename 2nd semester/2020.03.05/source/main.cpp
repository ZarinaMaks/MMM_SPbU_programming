 /* (20 баллов)Построить структуру данных дерево поиска (без добавления/удаления).
  * Реализовать конструктор, деструктор, обращение по ключу(operator[]),
  * выписывание в отсортированном порядке(operator<<), определение высоты,
  * глубины элементов, размера дерева.
 */
#include <iostream>
#include <string>
#include <memory>  // unique_ptr

 template <typename T>
 class BSTree
 {
 public:
     // constructor
     BSTree(): root(nullptr) {}

     // destructor
     ~BSTree();

     // print function
     void Print() const;

     // TODO hight, deep, size of a tree
 private:

     struct TreeNode
     {
         // member vars
         T data;
         std::unique_ptr<TreeNode> left;
         std::unique_ptr<TreeNode> right;

         // constructor
         TreeNode(T data): data(data), left(nullptr), right(nullptr) {}
     };

     std::unique_ptr<TreeNode> root;
     std::string SubTreeAsString(const std::unique_ptr<TreeNode>& node) const;  // Helper method for Print()
     bool Contains(T val, std::unique_ptr<TreeNode>& node) const;  // Helper method for Contains(int val)
 };

 // Destructor
 void BSTree::DestroyRecursive(BSTreePtr node)
 {
     if (node)
     {
         DestroyRecursive(node->left);
         DestroyRecursive(node->right);
         delete node;
     }
 }

 BSTree::~BSTree()
 {
     DestroyRecursive(Root);
 }

/// Print the tree
 template <typename T>
 void BSTree<T>::Print() const {
     if(this->root == nullptr){
         std::cout << "{}" << std::endl;
     } else{
         std::cout << this->SubTreeAsString(this->root) << std::endl;
     }
 }

/// Print the subtree starting at node
 template <typename T>
 std::string BSTree<T>::SubTreeAsString(const std::unique_ptr<TreeNode>& node) const {
     std::string leftStr = (node->left == nullptr) ? "{}" : SubTreeAsString(node->left);
     std::string rightStr = (node->right == nullptr) ? "{}" : SubTreeAsString(node->right);
     std::string result = "{" + std::to_string(node->data) + ", " + leftStr + ", " + rightStr + "}";
     return result;
 }


/// Search the subtree starting at node and return a pointer to the minimum-value node
/// The returned pointer will be a reference of an actual pointer in the tree, not a copy
 template <typename T>
 std::unique_ptr<typename BSTree<T>::TreeNode>& BSTree<T>::FindMin(std::unique_ptr<TreeNode>& node) {
     if(node == nullptr){
         throw "Min value not found";
     } else if(node->left == nullptr){
         return node;
     } else{
         return this->FindMin(node->left);
     }
 }