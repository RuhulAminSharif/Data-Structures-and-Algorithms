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
  TreeNode* buildFromPostorderAndInorder( vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& inMap )
    {
        if( postStart > postEnd || inStart > inEnd ) return NULL;

        TreeNode* node = new TreeNode( postorder[ postEnd ] );
        int inRoot = inMap[ node -> val ];
        int howMany =  inRoot - inStart;
        node -> left = buildFromPostorderAndInorder( postorder, postStart, postStart + howMany - 1, inorder, inStart, inRoot - 1, inMap );
        node -> right = buildFromPostorderAndInorder( postorder, postStart + howMany, postEnd - 1, inorder, inRoot + 1, inEnd, inMap );
        return node;
    }
    TreeNode* buildTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) {
        map<int,int> inMap;
        for( int i = 0; i < inorder.size(); i++ ) {
            inMap[ inorder[i] ] = i;
        }
        return buildFromPostorderAndInorder( postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap );
    }

    TreeNode* buildFromPreorderAndInorder( vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& inMap )
    {
        if( preStart > preEnd || inStart > inEnd ) return NULL;

        TreeNode* node = new TreeNode( preorder[preStart] );
        int inRoot = inMap[ node -> val ];
        int howMany =  inRoot - inStart;
        node -> left = buildFromPreorderAndInorder( preorder, preStart + 1, preStart + howMany, inorder, inStart, inRoot - 1, inMap );
        node -> right = buildFromPreorderAndInorder( preorder, preStart + howMany + 1, preEnd, inorder, inRoot + 1, inEnd, inMap );
        return node;
    }
    TreeNode* buildTreeFromPreorderAndInorder(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        for( int i = 0; i < inorder.size(); i += 1 ) {
            inMap[ inorder[i] ] = i;
        }
        return buildFromPreorderAndInorder(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
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

  vector<int> postorder = {20, 40, 30, 60, 80, 70, 50};
  vector<int> inorder = {20, 30, 40, 50, 60, 70, 80};
  TreeNode* root = tree.buildTreeFromPostorderAndInorder(postorder, inorder);
  cout << "Root of the tree built from postorder and inorder: " << root->val << endl; 
  vector<int> preorder = {50, 30, 20, 40, 70, 60, 80};
  root = tree.buildTreeFromPreorderAndInorder(preorder, inorder);
  cout << "Root of the tree built from preorder and inorder: " << root->val << endl;
  return 0;
} 


    