#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
      if(root == NULL){
        return;
      }
      else{
      traverseInOrder(root->left);
      cout << root->key << " ";
      traverseInOrder(root->right);
      return;
      }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
      if(root == NULL){
        root = new node;
        root->key = key;
        root->left = NULL;
        root->right = NULL;
      }
      else if(root->key < key){
        root->right = insertNode(root->right,key);
      }
      else if(root->key > key){
        root->left = insertNode(root->left,key);
      }
      return root;
}

int findMax(struct node *root){
    if(root->right == NULL){
        if(root->left == NULL){
            int temp = root->key;
            root = NULL;
            return temp;
        }
        else{
            int temp = root->key;
            root = root->left;
            return temp;
        }
    }
    else{
        findMax(root->right);
    }
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
      if(root == NULL){
        return root;
      }
      else if(root->key > key){
        root->left = deleteNode(root->left,key);
      }
      else if(root->key < key){
        root->right = deleteNode(root->right,key);
      }
      else{
        if(root->right == NULL && root->left == NULL){
            root = NULL;
        }
        else if(root->right == NULL){
            root = root->left;

        }
        else if(root->left == NULL){
            root = root->right;
        }
        else {
            int temp = findMax(root->right);
            root->key = temp;
        }
      }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
