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
        cout <<  root->data << endl;
        traverse(root->right);

    }
}

int findMin(Node* root){
  Node* temp = (root != nullptr)? root : throw logic_error("nothing to search");
  while (temp->left != nullptr){
      temp = temp->left;
  }
  return temp->data;
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
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 1);

    traverse(root);
    (search(root, 7))?cout<< "found"<< endl : cout << "not found" << endl;

    int min = findMin(root);
    cout << "min: "<< min << endl;

    return 0;
}