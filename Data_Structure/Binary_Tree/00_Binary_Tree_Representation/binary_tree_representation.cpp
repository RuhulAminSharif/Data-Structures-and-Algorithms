#include<bits/stdc++.h>
using namespace std;
class TreeNode {
  public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int data ) {
      val = data;
      left = nullptr;
      right = nullptr;
    }
};
class BinaryTree{
  public:
    TreeNode * root;
    BinaryTree() {
      root = nullptr;
    }
    // Helper for insertion (BST-style)
    TreeNode* insert( TreeNode* node, int value ) {
      if( node == nullptr ) return new TreeNode(value);
      else {
        if( value < node->val ) {
          node->left = insert( node->left, value );
        } else {
          node->right = insert( node->right, value );
        }
        return node;
      }
    }
    void insert(int value) {
      root = insert(root, value);
    }
};
int main()
{
  BinaryTree tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(8);
  tree.insert(1);
  tree.insert(4);
  return 0;
}