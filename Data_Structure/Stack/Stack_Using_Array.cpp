#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Stack {
private:
    T *arr;
    int topIndex;
    int mxSize;
public:
    Stack() {
        topIndex = -1;
        mxSize = 1000;
        arr = new T[mxSize];
    }
    Stack( int mxSize) {
        if ( mxSize <= 0) {
            throw invalid_argument("Size of the stack must be positive");
        }
        ( * this ).mxSize = mxSize;
        arr = new T[mxSize];
        topIndex = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push( const T& element ) {
        if (topIndex >= mxSize - 1) {
            throw overflow_error("Stack overflow: Cannot push to a full stack");
        }
        topIndex += 1;
        arr[topIndex] = element;
        return ;
    }
    void pop() {
        if( empty() ) {
            throw underflow_error("Stack underflow: Cannot pop from an empty stack");
        }
        topIndex -= 1;
        return ;
    }
    T top() {
        if( empty() ) {
            throw underflow_error("Stack underflow: No top element in an empty stack");
        }
        return arr[topIndex];
    }
    bool empty() {
        return topIndex == -1;
    }
    int size() {
        return topIndex + 1;
    }
    int maxCapacity() {
        return mxSize;
    }
};
int main()
{
    Stack <int> st;
    Stack<int> stt (10);
    return 0;
}