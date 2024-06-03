#include "BST.h"
#include <limits>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

template<class ItemType>
BST<ItemType>::BST() {
    root = NULL;
}

template<class ItemType>
BST<ItemType>::~BST() {
    Destroy(root);
}

template<class ItemType>
void BST<ItemType>::Destroy(TreeNode<ItemType>*& tree) {
    if (tree != NULL) {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
        tree = NULL;
    }
}

template<class ItemType>
void BST<ItemType>::Insert(TreeNode<ItemType>*& tree, ItemType item) {
    if (tree == NULL) {
        tree = new TreeNode<ItemType>;
        tree->info = item;
        tree->left = NULL;
        tree->right = NULL;
    } else if (item.getName() < tree->info.getName()) {
        Insert(tree->left, item);
    } else {
        Insert(tree->right, item);
    }
}

template<class ItemType>
void BST<ItemType>::InsertItem(ItemType item) {
    Insert(root, item);
}

template <class ItemType>
bool BST<ItemType>::IsEmpty()
{
 return root == NULL;
}


template<class ItemType>
void BST<ItemType>::Delete(TreeNode<ItemType>*& tree, string itemName) {
    if (tree == NULL) {
        return;
    } else if (itemName < tree->info.getName()) {
        Delete(tree->left, itemName);
    } else if (itemName > tree->info.getName()) {
        Delete(tree->right, itemName);
    } else {
        DeleteNode(tree);
    }
}

template<class ItemType>
void BST<ItemType>::DeleteNode(TreeNode<ItemType>*& tree) {
    ItemType data;
    TreeNode<ItemType>* tempPtr;
    tempPtr = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
    } else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
    } else {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data.getName());
    }
}

template<class ItemType>
void BST<ItemType>::GetPredecessor(TreeNode<ItemType>* tree, ItemType& data) {
    while (tree->right != NULL) {
        tree = tree->right;
    }
    data = tree->info;
}

template<class ItemType>
void BST<ItemType>::PrintTableHeader() {
    cout << "----------------------------" << endl;
    cout << setw(15) << left << "Name" << setw(15) << left << "Availability" << endl;
    cout << "----------------------------" << endl;
}

template<class ItemType>
void BST<ItemType>::InOrder(TreeNode<ItemType>* tree) {
    if (tree != NULL) {
        InOrder(tree->left);
        cout << setw(15) << left << tree->info.getName() << setw(15) << left << tree->info.getAvailability() << endl;
        InOrder(tree->right);
    }
}

template<class ItemType>
void BST<ItemType>::PrintInventory() {
    if (IsEmpty()) {
        cout << endl << "Inventory is empty." << endl;
    } else {
        cout << endl << "Showing all items in inventory:" << endl;
        PrintTableHeader();
        InOrder(root);
    }
}

template<class ItemType>
void BST<ItemType>::SearchItem(string itemName) {
    TreeNode<ItemType>* current = root;
    while (current != NULL) {
        if (current->info.getName() == itemName) {
            PrintTableHeader();
            cout << setw(15) << left << current->info.getName() << setw(15) << left << current->info.getAvailability() << endl;
            string choice;
            do {
                cout << "\nDo you want to update the availability? (1 for Yes, 0 for No): ";
                cin >> choice;
                if (choice == "1") {
                    cout << "Enter the new availability: ";
                    int newAvailability;
                    cin >> newAvailability;
                    current->info.setAvailability(newAvailability);
                    cout << "Availability updated successfully.\n";
                    WriteToFile("final_shop.txt");
                } else if (choice == "0") {
                    cout << "Availability not updated.\n";
                } else {
                    cout << "Invalid choice. Availability not updated.\n";
                }
            } while (choice != "1" && choice != "0");
            return;
        } else if (itemName < current->info.getName()) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout << "\nItem not found.\n";
}


template<class ItemType>
void BST<ItemType>::WriteToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    WriteInventoryToFile(root, outFile);
    outFile.close();
}

template<class ItemType>
void BST<ItemType>::WriteInventoryToFile(TreeNode<ItemType>* tree, ofstream& outFile) {
    if (tree != NULL) {
        WriteInventoryToFile(tree->left, outFile);
        outFile << tree->info.getName() << " (" << tree->info.getAvailability() << ")\n";
        WriteInventoryToFile(tree->right, outFile);
    }
}
