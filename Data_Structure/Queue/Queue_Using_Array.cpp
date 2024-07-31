#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
private:
    T* arr;           
    int cap;     
    int frontIdx;   
    int rearIdx;
    int sz;

public:
    Queue(int size = 100) {
        arr = new T[size];
        cap = size;
        frontIdx = 0;
        rearIdx = -1;
        sz = 0;
    }
    ~Queue() {
        delete[] arr;
    }
    void push( T item ) {
        if( isFull() ) {
            throw OverflowException();
        }
        rearIdx = (rearIdx + 1) % cap;
        arr[rearIdx] = item;
        sz += 1;
        return ;
    }
    void pop() {
        if( empty() ) {
            throw UnderflowException();
        }
        T item = arr[frontIdx];
        frontIdx = (frontIdx + 1) % cap;
        sz -= 1;
        return ;
    }
    T front() {
        if( empty() ) {
            throw UnderflowException();
        }
        return arr[frontIdx];
    }
    T back() {
        if( empty() ) {
            throw UnderflowException();
        }
        return arr[rearIdx];
    }
    int size() {
        return sz;
    }
    bool empty() {
        return sz == 0;
    }
    bool isFull() {
        return sz == cap;
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
