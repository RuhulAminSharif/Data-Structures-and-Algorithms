#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node {
public:
    T data;
    Node *next;
    Node( T data ) {
        this -> data = data;
        next = nullptr;
    }
};
template<typename T>
class  Stack {
private:
    Node<T> *topNode;
    int sz;
public:
    Stack() {
        topNode = nullptr;
        sz = 0;
    }
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
    void push( T element ) {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = topNode;
        topNode = newNode;
        sz += 1;
        return ;
    }
    void pop() {
        if ( empty() ) {
            throw underflow_error("Stack underflow: cannot pop from an empty stack");
        }
        T poppedValue = topNode -> data;
        Node<T> *temp = topNode;
        topNode = topNode -> next;
        delete temp;
        sz -= 1;
        return ;
    }
    T top() {
        if( empty() ) {
            throw underflow_error("Stack underflow: cannot peek from an empty stack");
        }
        return topNode -> data;
    }
    bool empty() {
        return topNode == nullptr;
    }
    int size() {
        return sz;
    }
};
int main()
{
    Stack<int> st;
    st.push(5);
    cout << st.size() << endl;
    st.pop();
    cout << st.size() << endl;
    cout << st.empty() << endl;
}