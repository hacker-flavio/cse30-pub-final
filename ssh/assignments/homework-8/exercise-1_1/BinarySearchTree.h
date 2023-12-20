#ifndef BST_H
#define BST_H
#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree{
    Node* root;

public:
    BinarySearchTree(){

    }

    BinarySearchTree(const BinarySearchTree& other){

    }

    void insert(int x){

    }

    void traverse(){

    }

    Node* search(int x){

    }

    Node* min(){

    }

    Node* max(){

    }

    Node* successor(Node* start){

    }

    Node* findParent(Node* start){

    }

    void remove(Node* node){

    }

    // A function to display the tree graphically
    void displayTree(Node* r, int level, int direction){
        // Don't worry about this function, just use it
        if (r != NULL){
            displayTree(r->right, level+1, 1);
            
            for (int i = 0; i < level-1; i++) {
                std::cout << "   ";
            }
            if (level > 0 ){
                if (direction == 1){
                    std::cout << " /--";
                }
                else{
                    std::cout << " \\--";
                }
            }
            std::cout << r->data;
            std::cout << std::endl;
            level++;
            
            displayTree(r->left, level, -1);
        }
    }

    // Call the function to display the tree and leave some space afterwards
    void draw(){
        displayTree(root, 0, 0);
        std::cout << std::endl << std::endl;
    }

};

#endif