#include <iostream>
#include <TimeSupport.h>
#include <RandomSupport.h>

using namespace std;


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

    Node* insert_helper(Node* root, int value){
        if (root == nullptr){
            root = new Node(value);
        }
        else{
            if (value < root->data){
                root->left = insert_helper(root->left, value);
            }
            else{
                root->right = insert_helper(root->right, value);
            }
        }

        return root;
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

    Node* search_helper(Node* root, int value){
        if (root == nullptr){
            return nullptr;
        }
        else{
            if (root->data == value){
                return root;
            }
            else if (value < root->data){
                return search_helper(root->left, value);
            }
            else{
                return search_helper(root->right, value);
            }
        }
    }

public:
    BinarySearchTree(){
        root = nullptr;
    }

    void insert(int x){
        root = insert_helper(root, x);
    }

    // Call the function to display the tree and leave some space afterwards
    void draw(){
        displayTree(root, 0, 0);
        std::cout << std::endl << std::endl;
    }

    Node* search(int value){
        return search_helper(root, value);
    }

    Node* findParent(Node* p){
        if (p == root){
            return nullptr;
        }
        Node* temp = root;
        Node* parent = root;

        while(temp != p){
            parent = temp;
            if (p->data < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }

        return parent;
    }

    void remove(Node* p){
        if (p == nullptr){
            return;
        }

        if (p->left == nullptr && p->right == nullptr){
            Node* parent = findParent(p);

            if (p == parent->left){
                parent->left = nullptr;
            }
            else{
                parent->right = nullptr;
            }

            delete p;
        }

        if (p->left == nullptr && p->right != nullptr){
            Node* parent = findParent(p);
            if(p == parent->left){
                parent-> left = p->right;
            }
            else{
                parent->right = p->right;
            }
            delete p;
        }
    }
};

int main(){

    BinarySearchTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(6);
    tree.insert(8);

    tree.draw();

    Node* temp = tree.search(6);
    tree.remove(temp);

    tree.draw();

    temp = tree.search(7);
    tree.remove(temp);

    tree.draw();

    // Node* result = tree.search(4);
    // if (result == nullptr){
    //     cout << "NOT FOUND" << endl;
    // }
    // else{
    //     cout << result->data << " WAS FOUND" << endl;
    // }


    // tree.traverse();
    // tree.findMin();
    // tree.remove(...);

   
    return 0;
}