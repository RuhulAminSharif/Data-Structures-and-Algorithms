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
  void inorderTraversal(TreeNode* node, vector<int>& inOrder) {
    if( node == nullptr ) {
        return ;
    }
    inorderTraversal( node -> left, inOrder );
    inOrder.push_back( node -> val );
    inorderTraversal( node -> right, inOrder );
    return ;
  }
  void preOrderTraversal(TreeNode* node, vector<int>& preOrder) {
    if( node == nullptr ) {
        return ;
    }
    preOrder.push_back( node -> val );
    preOrderTraversal( node -> left, preOrder );
    preOrderTraversal( node -> right, preOrder );
    return ;
  }
  void postorderTraversal(TreeNode* node, vector<int>& postOrder) {
    if( node == nullptr ) {
        return ;
    }
    postorderTraversal( node -> left, postOrder );
    postorderTraversal( node -> right, postOrder );
    postOrder.push_back( node -> val );
    return ;
  }
  void levelOrderTraversal(TreeNode *node, vector<vector<int>>& levelOrder ) {
    if( node == nullptr ) {
      return ;
    }
    queue<TreeNode*> q;
    q.push( node );
    while( q.size() ) {
      int currSize = q.size();
      vector<int> currLevel;
      for( int i = 1; i <= currSize; i += 1 ) {
        TreeNode* currNode = q.front();
        q.pop();
        currLevel.push_back( currNode->val );
        if( currNode->left != nullptr ) q.push( currNode->left );
        if( currNode->right != nullptr ) q.push( currNode->right );
      }
      levelOrder.push_back( currLevel );
    }
    return ;
  }
  void inOrderTraversalIterative(TreeNode* node, vector<int>& inOrder) {
    if( node == nullptr ) {
      return ;
    }
    stack<TreeNode*> st;
    while( true ) {
      if( node != nullptr ) {
        st.push( node );
        node = node->left;
      } else {
        if( st.empty() ) break;
        node = st.top();
        st.pop();
        inOrder.push_back( node->val );
        node = node->right;
      }
    }
    return ;
  }
  void preOrderTraversalIterative(TreeNode* node, vector<int>& preOrder) {
    if( node == nullptr ) {
      return ;
    }
    stack<TreeNode*> st;
    st.push( node );
    while( st.size() > 0 ) {
      TreeNode * curr = st.top();
      st.pop();
      preOrder.push_back( curr->val );
      if( curr->right != nullptr ) st.push( curr->right );
      if( curr->left != nullptr ) st.push( curr->left ); 
    }
    return ;
  }
  void postOrderTraversalIterative(TreeNode* node, vector<int>& postOrder) {
    if( node == nullptr ) {
      return ;
    }
    stack<TreeNode*> st;
    st.push( node );
    while( st.size() ) {
      node = st.top();
      st.pop();
      postOrder.push_back( node->val );
      if( node->left != nullptr ) st.push( node->left );
      if( node->right != nullptr ) st.push( node->right );
    }
    reverse( postOrder.begin(), postOrder.end() );
    return ;
  }
  void allTraversals( TreeNode * node, vector<int>& preOrder, vector<int>& inOrder, vector<int>& postOrder ) {
    if( node == nullptr ) {
      return ;
    }
    stack< pair<TreeNode*, int>> st;
    st.push( {node, 1} );
    while( st.size() > 0 ) {
      TreeNode* currNode = st.top().first;
      int indicator = st.top().second;
      st.pop();

      if( indicator == 1 ) {
        preOrder.push_back( currNode->val );
        indicator += 1;
        st.push( { currNode, indicator } );
        if( currNode->left != nullptr ) st.push( { currNode->left, 1 } );
      } else if( indicator == 2 ) {
        inOrder.push_back( currNode->val );
        indicator += 1;
        st.push( { currNode, indicator } );
        if( currNode->right != nullptr ) st.push( { currNode->right, 1 } );
      } else {
        postOrder.push_back( currNode->val );
      }
    }
    return ;
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

  /// DFS -> inOrder, preOrder, postOrder
  vector<int> inOrder, preOrder, postOrder;
  tree.inorderTraversal( tree.root, inOrder );
  tree.preOrderTraversal( tree.root, preOrder );
  tree.postorderTraversal( tree.root, postOrder );

  vector<int> inOrderIterative, preOrderIterative, postOrderIterative;
  tree.inOrderTraversalIterative( tree.root, inOrderIterative );
  tree.preOrderTraversalIterative( tree.root, preOrderIterative );
  tree.postOrderTraversalIterative( tree.root, postOrderIterative );
  
  // BFS -> levelOrder
  vector<vector<int>> levelOrder;
  tree.levelOrderTraversal( tree.root, levelOrder );

  cout << "Inorder " << endl;
  for( auto & x : inOrder ) {
    cout << x << " ";
  }
  cout << endl;
  for( auto & x : inOrderIterative ) {
    cout << x << " ";
  }
  cout << endl;
  
  cout << "Preorder " << endl;
  for( auto & x : preOrder ) {
    cout << x << " ";
  }
  cout << endl;
  
  for( auto & x : preOrderIterative ) {
    cout << x << " ";
  }
  cout << endl;


  cout << "Postorder " << endl;
  for( auto & x : postOrder ) {
    cout << x << " ";
  }
  cout << endl;
  for( auto & x : postOrderIterative ) {
    cout << x << " ";
  }
  cout << endl;


  cout << "Level Order " << endl;
  for( int currLevel = 0; currLevel < levelOrder.size(); currLevel += 1 ) {
    cout << "At level " << currLevel << ", the nodes are : ";
    for( auto& val : levelOrder[currLevel] ) {
      cout << val << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}