#include <iostream>

using namespace std;

template<typename t>
class TreeNode{
  public:
    t data;
    int key;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(t d); //k = key
    ~TreeNode();
};
