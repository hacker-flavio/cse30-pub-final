#include <iostream>
#include <TimeSupport.h>
#include <RandomSupport.h>
#include <stdexcept>

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

Node* insert(Node* root, int value){
    if (root == nullptr){
        root = new Node(value);
    }
    else{
        if (value < root->data){
            root->left = insert(root->left, value);
        }
        else{
            root->right = insert(root->right, value);
        }
    }

    return root;
}

void traverse(Node* root){
    if(root != nullptr){
        traverse(root->left);
        cout << root->data << endl;
        traverse(root->right);
    }
}

int findMin(Node* root){
    if (root == nullptr){
        throw logic_error("Tree is empty");
    }

    while (root->left != nullptr){
        root = root->left;
    }
    return root->data;
}

bool search(Node* root, int value){
    if (root == nullptr) {return false;}else{
        if (root->data == value){
            return true;
        }else if (value < root->data){
            return search(root->left, value);
        }else{
            return search(root->right, value);
        }
    }
    

    return false;
}

int main(){

    Node* root = nullptr;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, -7);
    root = insert(root, 2);

    traverse(root);

    (search(root, 11))?cout<< "found"<< endl : cout << "not found" << endl;

    cout << "Min is: " << findMin(root) << endl;

    return 0;
}