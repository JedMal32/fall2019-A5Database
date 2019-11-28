#include <iostream>
#include "TreeNode.cpp"

using namespace std;

template<typename t>
class BST{
  private:
    TreeNode<t> *root;

  public:
    BST();
    ~BST();

    int size;

    bool search(int value); //returns bool for whether or not the space exists
    void insert(t value);
    bool deleteNode(int value);
    TreeNode<t> * getSuccessor(TreeNode<t> *d);

    TreeNode<t> * getMin();
    TreeNode<t> * getMax();
    void printTree();
    void recPrint(TreeNode<t> *node);
    TreeNode<t> * getNode(t value);
    TreeNode<t> * getRoot();
};
