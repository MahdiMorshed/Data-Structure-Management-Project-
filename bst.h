
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

template<class ItemType>
struct TreeNode {
    ItemType info;
    TreeNode<ItemType>* left;
    TreeNode<ItemType>* right;
};

template<class ItemType>
class BST {
private:
    TreeNode<ItemType>* root;

    void Destroy(TreeNode<ItemType>*& tree);
    void Insert(TreeNode<ItemType>*& tree, ItemType item);
    void Delete(TreeNode<ItemType>*& tree, string itemName);
    void DeleteNode(TreeNode<ItemType>*& tree);
    void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);
    void InOrder(TreeNode<ItemType>* tree);
    void PrintTableHeader();
    void WriteInventoryToFile(TreeNode<ItemType>* tree, ofstream& outFile);

public:
    BST();
    ~BST();
    void InsertItem(ItemType item);
    bool IsEmpty();
    void PrintInventory();
    void SearchItem(string itemName);
    void WriteToFile(const string& filename);
};

#endif // BST_H_INCLUDED

