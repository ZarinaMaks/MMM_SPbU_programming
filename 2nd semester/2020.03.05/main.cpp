 /* (20 баллов)Построить структуру данных дерево поиска (без добавления/удаления).
  * Реализовать +конструктор, +деструктор, +обращение по ключу(operator[]),
  * выписывание в отсортированном порядке+(operator<<), определение высоты,
  * глубины элементов, размера дерева.
 */
#include <iostream>
#include <cstdlib>

#include "BSTree.h"
 using namespace std;


 int main()
 {
     int TreeKeys[8] = {10, 34, 42, 67, 2, 86, 62, 33};
     BSTree myTree;

     cout << "Printing the tree in order BEFORE adding numbers\n";
     myTree.PrintInOrder();
     for(int i = 0; i < 8; i++)
     {
         //myTree.AddLeaf(TreeKeys[i]);
         //Node* CurrentNode = myTree.AddLeaf(TreeKeys[i]);
         cout << "Printing the depth of " << i << " of BSTree:" << myTree.DepthOfTree(myTree.AddLeaf(TreeKeys[i])) << endl;
     };
     cout << "Printing the tree in order AFTER adding numbers\n";
     myTree.PrintInOrder();

     //cout << "Printing the depth of BSTree:" << myTree.DepthOfTree() << endl;
     cout << "Printing the height of BSTree:" << myTree.HeightOfTree() << endl;


     return 0;
 }