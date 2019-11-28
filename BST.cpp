#include <iostream>
#include "BST.h"
#include "Faculty.h"

using namespace std;

template<typename t>
BST<t>::BST(){
  root = NULL;
  size = 0;
}

template<typename t>
BST<t>::~BST(){
  //I do it myself
}

template<typename t>
bool BST<t>::search(int value){
  if(root == NULL){
    return false;
  }else{
    TreeNode<t> *current = root;
    while(current->key!=value){
      if(value<current->key){
        current = current->left;
      }else{
        current = current->right;
      }
      if(current==NULL){
        return false;
      }
    }
  }
  return true;
}

template<typename t>
void BST<t>::insert(t input){
  size++;
  TreeNode<t> *node = new TreeNode<t>(input);
  int value = node->key;
  if(root == NULL){ //tree is empty empty
    root = node;
  }else{ //tree is not empty
    TreeNode<t> *current = root;
    TreeNode<t> *parent = NULL;
    while(true){
      parent = current;
      if(value < current->key){ //go left
        current = current->left;
        if(current==NULL){
          parent->left = node;
          break;
        }
      }else{ //go right
        current = current->right;
        if(current==NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

//When you get to the point of a node to delete, you either need to:
//-Go left one, and then all the way right to find the replacement
//-Go right one, and then all the way left to find the replacement <-WE USE THIS ONE
template<typename t>
bool BST<t>::deleteNode(int value){
  if(root == NULL){ //Tree is empty- return false
    return false;
  }
  //Tree is not empty
  size--;
  TreeNode<t> *current = root;
  TreeNode<t> *parent = NULL;;
  bool isLeft = true;
  while(current->key!=value){
    parent = current;
    if(value<current->key){
      isLeft = true;
      current = current->left;
    }else{
      isLeft = false;
      current = current->right;
    }
    if(current==NULL){ //We did not find the node- return false
      return false;
    }
  }
  //We found the node

  if(current->left == NULL && current->right == NULL){ //case if: node to be deleted is a leaf node (no children)
    //EASY CASE: the found value is the root
    if(current == root){
      root = NULL;
    }else if(isLeft){
      parent->left = NULL;
    }else{
      parent->right = NULL;
    }
  }else if(current->right == NULL){ //case if: node to be deleted has one child (left)
    //has no right child
    if(current == root){
      root = current->left;
    }else if(isLeft){
      parent->left = current->left;
    }else{ //isRight
      parent->right = current->left;
    }
  }else if(current->left == NULL){ //case if: node to be deleted has one child (right)
    //has no left child
    if(current == root){
      root = current->right;
    }else if(isLeft){
      parent->left = current->right;
    }else{ //isRight
      parent->right = current->right;
    }
  }else{ //case if: node to be deleted has two children
    TreeNode<t> *successor = getSuccessor(current);
    if(current == root){
      root = successor;
    }else if(isLeft){
      parent -> left = successor;
    }else{
      parent -> right = successor;
    }
    successor->left = current->left;
  }
  return true;
}

template<typename t>
TreeNode<t> * BST<t>::getSuccessor(TreeNode<t> *d){ //helper function to be used in Delete
  TreeNode<t> *current = d->right;
  TreeNode<t> *sp = d; //successor's parent
  TreeNode<t> *successor = d;
  while(current != NULL){
    //traverse tree until we find the successor
    sp = successor;
    successor = current;
    current = current->left;
  }
  //by this point, all pointers should be in the right spot
  if(successor != d->right){
    sp->left = successor->right; //sets the right pointer for the successor to the one above it
    successor -> right = d -> right;
  }
}

template<typename t>
TreeNode<t> * BST<t>::getMin(){
  TreeNode<t> *current = root;
  if(root == NULL)//empty tree
    return NULL;

  while(current->left != NULL){
    current = current->left;
  }

  return current;
}

template<typename t>
TreeNode<t> * BST<t>::getMax(){
  TreeNode<t> *current = root;
  if(root == NULL)//empty tree
    return NULL;

  while(current->right != NULL){
    current = current->right;
  }

  return current; //could aslo be return current->key for other systems, aka on online stuff
}

template<typename t>
void BST<t>::printTree(){
  recPrint(root);
}

template<typename t>
void BST<t>::recPrint(TreeNode<t> *node){
  if(node == NULL)
    return;

  //Inorder Traverse
  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);

  /*
  //Preorder Traverse
  cout << node->key << endl;
  recPrint(node->left);
  recPrint(node->right);

  //Postorder Traverse
  recPrint(node->left);
  recPrint(node->right);
  cout << node->key << endl;
  */
}


template<typename t>
TreeNode<t> * BST<t>::getNode(t value){
  if(root == NULL || !(search(value))){
    return NULL;
  }else{
    TreeNode<t> *current = root;
    while(current->key!=value){
      if(value<current->key){
        current = current->left;
      }else{
        current = current->right;
      }
      if(current==NULL){
        return NULL;
      }
    }
    return current;
  }
}

template<typename t>
TreeNode<t> * BST<t>::getRoot(){
  if(size == 0)
    return NULL;
  return root;
}
