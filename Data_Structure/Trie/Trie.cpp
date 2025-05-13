#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

class Trie
{
private:
  class Node{
  public:
    vector<Node *> edges;
    ll words, prefix;
    Node(){
      edges.resize( 30, nullptr );
      words = prefix = 0;
    }
  };
public:
  Node * root;
  Trie() {
    root = new Node();
  }
  
  int getIndex( char ch ) {
    return ch - 'a';
  }

  void insertStr( string& word ) {
    Node * curr = root;
    for( char ch : word ) {
      int idx = getIndex(ch);
      if( curr->edges[idx] == nullptr ) {
        curr -> edges[idx] = new Node();
      }
      curr = curr -> edges[idx];
      curr -> prefix += 1;
    }
    curr -> words += 1;
    return ;
  }

  ll search( string& word ) {
    Node * curr = root;
    for( char ch : word ) {
      int idx = getIndex(ch);
      if( curr->edges[idx] == nullptr ) {
        return 0LL;
      }
      curr = curr -> edges[idx];
    }
    return curr -> words;
  }

  ll startsWith(string& prefix) {
    Node* curr = root;  
    for( char ch : prefix ) {
      int idx = getIndex(ch);
      if( curr->edges[idx] == nullptr ) { 
        return 0; 
      }
      curr = curr ->edges[idx];
    }
    return curr->prefix; 
  }

  void erase(string& word){
    if( search(word) == 0 ) return ;
    Node* curr = root; 
    for( char ch : word ) {
      int idx = getIndex(ch);
      if( curr->edges[idx] == nullptr ) { 
        return ; 
      }
      curr = curr ->edges[idx];
      curr -> prefix -= 1;
    }
    curr->words -= 1;
  }

  void deleteTrie(Node* node) {
    if (!node) return;
    for (int i = 0; i < 30; i++) {
      deleteTrie(node->edges[i]);
    }
    delete node;
  }
  
  ~Trie() {
    deleteTrie(root);
  }
};

int main()
{
  ios::sync_with_stdio(false); cin.tie(nullptr);  cout.tie(nullptr);

  Trie* tr = new Trie();
  string s = "sharif" ;
  tr ->insertStr(s);
  cout << tr -> search(s) << endl;
  cout << tr -> startsWith(s) << endl;
  tr -> erase(s);
  cout << tr -> search(s) << endl;
  cout << tr -> startsWith(s) << endl;
  delete tr;
}