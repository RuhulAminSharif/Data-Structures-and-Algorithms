#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    string data; 
    Node *next; 
    Node *prev;
    Node(){
        this -> data = "";
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    Node(string data){
         this -> data = data;
         this -> next = nullptr;
         this -> prev = nullptr;
    }
    Node(string data, Node *prev, Node *next){
        this -> data = data;
        this -> prev = prev;
        this -> next = next;
    }
};
class BrowserHistory {
public:
    Node *curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node *newPage = new Node(url,curr,nullptr);
        curr -> next = newPage;
        curr = newPage;
    }
    
    string back(int steps) {
        while(steps--) {
            if( curr -> prev ) {
                curr = curr -> prev;
            }
            else {
                break;
            }
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(steps--) {
            if( curr -> next ) {
                curr = curr -> next;
            }
            else {
                break;
            }
        }
        return curr -> data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
/// Problem Link: https://leetcode.com/problems/design-browser-history/description/
int main()
{

}