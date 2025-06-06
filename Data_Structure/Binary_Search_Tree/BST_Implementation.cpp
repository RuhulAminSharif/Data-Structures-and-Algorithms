#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
  int data;
  TreeNode* left;
  TreeNode* right;   
  TreeNode() {
    data = 0;
    left = nullptr;
    right = nullptr;
  };
  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  };
  TreeNode(int val, TreeNode* leftChild, TreeNode* rightChild) {
    data = val;
    left = leftChild;
    right = rightChild;
  };
};
class BST {
public:
  TreeNode* root;
  BST() {
    root = nullptr;
  }
  void insert(int val) {
    root = insert(root, val);
  }
  TreeNode* insert(TreeNode* node, int val) {
    if(node == nullptr) {
      return new TreeNode(val);
    }
    if(val < node->data) {
      node->left = insert(node->left, val);
    } else if(val > node->data) {
      node->right = insert(node->right, val);   
   }
    return node;
  }
  TreeNode* search(int val) {
    return search(root, val);
  }
  TreeNode* search(TreeNode* node, int val) {
    if(node == nullptr || node->data == val) {
      return node;
    }
    if(val < node->data) {
      return search(node->left, val);
    } else if(val > node->data) {
      return search(node->right, val);
    }
    return nullptr;
  }
  void inorderTraversal(TreeNode* node, vector<int>& inOrder) {
    if( node == nullptr ) {
        return ;
    }
    inorderTraversal( node -> left, inOrder );
    inOrder.push_back( node -> data );
    inorderTraversal( node -> right, inOrder );
    return ;
  }
  void preOrderTraversal(TreeNode* node, vector<int>& preOrder) {
    if( node == nullptr ) {
        return ;
    }
    preOrder.push_back( node -> data );
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
    postOrder.push_back( node -> data );
    return ;
  }
  TreeNode* findMin(TreeNode* node) {
    while(node->left != nullptr) {
      node = node->left;
    }
    return node;
  }
  TreeNode* findMax(TreeNode* node) {
    while(node->right != nullptr) {
      node = node->right;
    }
    return node;
  }
  TreeNode* deleteNode(int val) {
    return remove(root, val);
  }
  TreeNode* remove(TreeNode* node, int key) {
    if(node == nullptr) {
      return node;
    }
    if(key < node->data) {
      node->left = remove(node->left, key);
    } else if(key > node->data) {
      node->right = remove(node->right, key);
    } else {
      if(node->left == nullptr) {
        TreeNode* temp = node->right;
        delete node;
        return temp;
      } else if(node->right == nullptr) {
        TreeNode* temp = node->left;
        delete node;
        return temp;
      }
      TreeNode* temp = findMin(node->right);
      node->data = temp->data;
      node->right = remove(node->right, temp->data);
    }
    return node;
  }
  int kthSmallest(TreeNode* node, int k) {
    if( node == nullptr ) {
      return -1;
    }
    vector<int> allMins;
    inorderTraversal(node, allMins);
    if( k > allMins.size() ) {
      return -1;
    }
    return allMins[k-1];
  }
  bool isValidBST(TreeNode* node, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if(node == nullptr) {
      return true;
    }
    if(node->data <= minVal || node->data >= maxVal) {
      return false;
    }
    return isValidBST(node->left, minVal, node->data) && isValidBST(node->right, node->data, maxVal);
  }
  bool isValidBST() {
    return isValidBST(root);
  }
  TreeNode* LCA(TreeNode* node, TreeNode* node1, TreeNode* node2) {
    if( node == nullptr || node == node1 || node == node2 ) {
      return node;
    }
    TreeNode* leftSide = LCA( node -> left, node1, node2 );
    TreeNode* rightSide = LCA( node -> right, node1, node2 );
    if( leftSide && rightSide ) {
      return node;
    } else if( leftSide ) {
      return leftSide;
    } else {
      return rightSide;
    }
    return nullptr;
  }
  TreeNode* LCA(TreeNode* node1, TreeNode* node2) {
    return LCA(root, node1, node2); 
  }
  TreeNode* bstFromPreorder( vector<int>& preOrder, int& i, int limit = INT_MAX ) {
    if( i >= preOrder.size() || preOrder[i] > limit ) return nullptr;
    TreeNode* node = new TreeNode( preOrder[i] );
    i += 1;
    node -> left = bstFromPreorder( preOrder, i, node -> data );
    node -> right = bstFromPreorder( preOrder, i, limit );
    return node;
  }
  
};
int main() {
  BST tree;
  tree.insert(10);
  tree.insert(5);
  tree.insert(15);
  TreeNode* foundNode = tree.search(5);
  if(foundNode) {
    cout << "Found: " << foundNode->data << endl;
  } else {
    cout << "Not Found" << endl;
  }
  TreeNode* minNode = tree.findMin(tree.root);
  cout << "Minimum: " << minNode->data << endl;
  TreeNode* maxNode = tree.findMax(tree.root);
  cout << "Maximum: " << maxNode->data << endl;
  tree.deleteNode(5); 
  foundNode = tree.search(5); 
  if(foundNode) {
    cout << "Found: " << foundNode->data << endl;
  } else {
    cout << "Not Found" << endl;
  }
  cout << "Is Valid BST: " << tree.isValidBST() << endl;
  cout << "Kth Smallest: " << tree.kthSmallest(tree.root, 1) << endl;
  cout << "LCA: " << tree.LCA(tree.root, tree.root->left, tree.root->right)->data << endl;
  vector<int> preorder = {10, 5, 15, 1, 8, 12, 20};
  int idx = 0;
  tree.root = tree.bstFromPreorder(preorder, idx);
  cout << "Root: " << tree.root->data << endl;

  vector<int> inOrder, preOrder, postOrder;
  tree.inorderTraversal( tree.root, inOrder );
  tree.preOrderTraversal( tree.root, preOrder );
  tree.postorderTraversal( tree.root, postOrder );
  cout << "Inorder " << endl;
  for( auto & x : inOrder ) {
    cout << x << " ";
  }
  cout << endl;
  
  cout << "Preorder " << endl;
  for( auto & x : preOrder ) {
    cout << x << " ";
  }
  cout << endl;
  
  cout << "Postorder " << endl;
  for( auto & x : postOrder ) {
    cout << x << " ";
  }
  cout << endl;
  

  return 0;
}