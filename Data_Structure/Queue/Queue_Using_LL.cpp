#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node( T data ) {
        this -> data = data;
        this -> next = nullptr;
    }
};
template<typename T>
class Queue {
private:
    Node<T> *start;
    Node<T> *end;
    int sz;
public:
    Queue() {
        start = nullptr;
        end = nullptr;
        sz = 0;
    }
    ~Queue() {
        while( !empty()) {
            pop();
        }
    }
    void push( T item ) {
        Node<T> *newNode = new Node<T>(item);
        sz += 1;
        if( end == nullptr ) {
            start = end = newNode;
            return ;
        }
        end -> next = newNode;
        end = newNode;
        return ;
    }
    void pop() {
        if( empty() ) {
            throw UnderflowException();
        }
        Node<T>* temp = start;
        T data = start -> data;
        start = start -> next;
        if( start == nullptr ) {
            end = nullptr;
        }
        delete temp;
        sz -= 1;
        return ; /// data
    }
    T front() {
        if( empty() ) {
            throw UnderflowException();
        }
        return start -> data;
    }
    T back() {
        if( empty() ) {
            throw UnderflowException();
        }
        return end -> data;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return start == nullptr;
    }
    class UnderflowException : public runtime_error {
    public:
        UnderflowException() : runtime_error("Queue underflow") {}
    };

    class OverflowException : public runtime_error {
    public:
        OverflowException() : runtime_error("Queue overflow") {}
    };
};
int main() {
    Queue<int> Q;
    Q.push(10);
    cout << Q.size() << endl;
    cout << Q.front() << endl;
    cout << Q.back() << endl;
    Q.pop();
    cout << Q.empty();
    return 0;
}