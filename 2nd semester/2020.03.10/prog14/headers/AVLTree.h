#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

template <typename T1>
struct Node {
  public:
    T1 value;       
    int key;        
    int hight;      
    Node* left; 
    Node* right; 
  public:
    Node(const T1& CurValue, const int& CurKey);
};

template <typename T2>
struct AVLTree {
  private:
  
    Node<T2>* root;
    int BLR_count; // - Big Left Rotation amount
    int BRR_count; // - Big Right Rotation amount
    int SLR_count; // - Small Left Rotation amount
    int SRR_count; // - Small Right Rotation amount
    
  private:
  
    Node<T2>* TreeBalance(Node<T2>* head);
  
    void NewHight(Node<T2>* head);
    int ReturnHight(Node<T2>* head);
    int HightDiff(Node<T2>* head);
    
    void DeleteTree(Node<T2>* head);
    
    Node<T2>** next(const int& key, Node<T2>* head);
    Node<T2>* BLR(Node<T2>* head);
    Node<T2>* BRR(Node<T2>* head);
    Node<T2>* SLR(Node<T2>* head);
    Node<T2>* SRR(Node<T2>* head);

    
  public:
  
    AVLTree();
    void InsertIntoTree(const T2& value, const int& key);
    void DisplayRCount();
    
    ~AVLTree();
    void Delete();
    
    int ReturnSLR();
    int ReturnSRR();
    int ReturnBLR();
    int ReturnBRR();
};

void Transposition(int* array, int& arrayNum);

bool IsChance(const double& chance);

void AverageAmount(const int& number);

template <typename T3>
void CreateTree(const int& number, AVLTree<T3>& tree, const T3& value);


