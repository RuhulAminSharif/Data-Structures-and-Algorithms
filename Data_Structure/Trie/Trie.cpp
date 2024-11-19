#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9+7;
class Trie {
private:
    class Node {
    public:
        Node * edges[30];
        ll words, prefix;
        Node() {
            words = 0;
            prefix = 0;
            for( ll i = 0; i < 30; i += 1 ) {
                edges[i] = nullptr;
            }
        }
    };
public:
    Node *root; 
    Trie() {
        root = new Node();
    }

    int getIndex( char ch ) {
        return ch - 'a';
    }

    void insertStr(string &word) {
        Node* curr = root; 
        for( ll i = 0; i < word.size(); i += 1 ) {
            int idx = getIndex(word[i]);
            if( curr->edges[idx] == nullptr ) {
                curr->edges[idx] = new Node();
            }
            curr = curr ->edges[idx];
            curr->prefix += 1; 
        }
        curr->words += 1;
    }

    ll search(string &word) {
        Node* curr = root; 
        for( ll i = 0; i < word.size(); i += 1 ) {
            int idx = getIndex(word[i]);
            if( curr->edges[idx] == nullptr ) { 
                return 0;
            }
            curr = curr -> edges[idx]; 
        }
        return curr->words; 
    }

    ll startsWith(string &prefix) {
        Node* curr = root;  
        for( ll i = 0; i < prefix.size(); i += 1 ) {
            int idx = getIndex(prefix[i]);
            if( curr->edges[idx] == nullptr ) { 
                return 0; 
            }
            curr = curr ->edges[idx];
        }
        return curr->prefix; 
    }

    void erase(string &word){
        Node* curr = root; 
        for( ll i = 0; i < word.size(); i += 1 ) { 
            int idx = getIndex(word[i]);
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

};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Trie* tr = new Trie();
    string s = "sharif" ;
    tr ->insertStr(s);
    cout << tr -> search(s) << endl;
    cout << tr -> startsWith(s) << endl;
    tr -> erase(s);
    cout << tr -> search(s) << endl;
    cout << tr -> startsWith(s) << endl;
    tr -> deleteTrie(tr->root);
    return 0;
}
