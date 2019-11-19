#include <iostream>
#include "TreeNode.h"

using namespace std;

template<typename t>
TreeNode<t>::TreeNode(){
  left = NULL;
  right = NULL;
}

template<typename t>
TreeNode<t>::TreeNode(t d){
  data = d;
  key = data.getID(); //SPECIFIC TO CURRENT PROJECT
  left = NULL;
  right = NULL;
}

template<typename t>
TreeNode<t>::~TreeNode(){
  //I need to do this
}
