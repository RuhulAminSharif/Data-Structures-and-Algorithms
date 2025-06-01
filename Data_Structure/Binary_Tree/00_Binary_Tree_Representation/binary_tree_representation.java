class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
  TreeNode(int data ) {
    val = data;
    left = null;
    right = null;
  }
};
class BinaryTree{
  TreeNode root;
  BinaryTree() {
    root = null;
  }
  // Public insert method for external calls
  void insert(int value) {
    root = insert(root, value);
  }
  // Helper for insertion (BST-style)
  TreeNode insert( TreeNode node, int value ) {
    if( node == null ) {
      return new TreeNode(value);
    }
    else {
      if( value < node.val ) {
        node.left = insert( node.left, value );
      } else {
        node.right = insert( node.right, value );
      }
      return node;
    }
  }
};
public class binary_tree_representation {
  public static void main(String[] args ) {
    BinaryTree tree = new BinaryTree();
        tree.insert(5);
        tree.insert(3);
        tree.insert(8);
        tree.insert(1);
        tree.insert(4);
  }
}