#include<bits/stdc++.h>
using namespace std;
class TreeNode {
  public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() {
      val = 0;
      this->left = nullptr;
      this->right = nullptr;
    } 
    TreeNode(int data ) {
      val = data;
      this->left = nullptr;
      this->right = nullptr;
    }
    TreeNode(int data, TreeNode *left, TreeNode *right) {
      val = data;
      this->left = left;
      this->right = right;
    }
};
class BinaryTree{
public:
  TreeNode * root;
  BinaryTree() {
    root = nullptr;
  }
  int depthCalc( TreeNode* node ) {
    if( node == nullptr ) {
        return 0;
    }
    int left = depthCalc( node -> left );
    int right = depthCalc( node -> right );
    return max( left, right ) + 1;
  }   
};

int main()
{
  BinaryTree tree;
  /*
        50
       /  \
     30    70
    / \   /  \
   20 40 60  80
  */
  TreeNode* n20 = new TreeNode(20);
  TreeNode* n40 = new TreeNode(40);
  TreeNode* n60 = new TreeNode(60);
  TreeNode* n80 = new TreeNode(80);
  TreeNode* n30 = new TreeNode(30, n20, n40);
  TreeNode* n70 = new TreeNode(70, n60, n80);
  tree.root = new TreeNode(50, n30, n70);

  cout << tree.depthCalc(tree.root) << endl;

  return 0;
} 


    