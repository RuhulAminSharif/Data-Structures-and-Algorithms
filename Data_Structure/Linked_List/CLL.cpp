#include<bits/stdc++.h>
using namespace std;
/// CLL
class ListNode {
public:
    int data;
    ListNode *next;
    ListNode() {
        this -> data = 0;
        this -> next = nullptr;
    }
    ListNode( int data ) {
        this -> data = data;
        this -> next = nullptr;
    }
    ListNode( int data, ListNode *next ) {
        this -> data = data;
        this -> next = next;
    }
};
ListNode *tail;
int listLen()
{
    if( tail == nullptr ) return 0;
    int len = 0;
    ListNode *head = tail -> next; /// indicates head;
    ListNode *curr = head;
    do
    {
        len += 1;
        curr = curr -> next;
    } while (curr != head);
    return len;
}
void show()
{
    if( tail == nullptr ) return ;
    ListNode *curr = tail -> next;
    do {
        cout << curr -> data << " " ;
        curr = curr -> next;
    } while( curr != tail -> next ) ;
    cout << endl;
    return ;
}
void constructCLL(vector<int> v ) {
    if( v.size() == 0 ) return ;
    tail = new ListNode(v[0]);
    tail -> next = tail;
    for( int i = 1; i < v.size(); i += 1 ) {
        ListNode *newNode = new ListNode( v[i], tail -> next ) ;
        tail -> next = newNode;
        tail = newNode;
    }
    return ;
}
void insertBeforeHead( int value )
{
    ListNode *node = new ListNode( value );
    if( tail == nullptr ) {
        tail = node;
        tail -> next = tail;
        return ;
    }
    node -> next = tail -> next;
    tail -> next = node;
    return ;
}
void insertAfterHead( int value )
{
    if( tail == nullptr ) {
        tail = new ListNode(value);
        tail -> next = tail;
        return ;
    }
    ListNode *node = new ListNode( value, tail -> next -> next ) ;
    tail -> next -> next = node;
    return ;
}
void insertBeforeTail( int value )
{
    ListNode *newNode = new ListNode(value);
    if( tail == nullptr ) {
        tail = newNode;
        tail -> next = tail;
        return ;
    }
    if( tail == tail -> next ) {
        newNode -> next = tail;
        tail -> next = newNode;
        return ;
    }
    ListNode *prev = tail -> next;
    while( prev -> next != tail ) {
      prev = prev -> next;
    }
    newNode -> next = tail;
    prev -> next = newNode;
    return ;
}
void insertAfterTail( int value )
{
    ListNode *newNode = new ListNode(value);
    if( tail == nullptr ) {
        tail = newNode;
        tail -> next = tail;
        return ;
    }
    newNode -> next = tail -> next;
    tail -> next = newNode;
    tail = newNode;
    return ;
}
void insertPos( int value, int pos )
{
    if( tail == nullptr ) {
        if( pos == 1 ) {
            tail = new ListNode(value);
            tail -> next = tail;
            return ;
        }
        else {
          return ;
        }
    }
    if( pos == 1 ) {
        ListNode *node = new ListNode( value );
        node -> next = tail -> next;
        tail -> next = node;
        return ;
    }
    ListNode *prev = nullptr;
    ListNode *curr = tail -> next;
    int at_pos = 0;
    do {
        if( at_pos == pos - 1 ) {
            ListNode *newNode = new ListNode(value, curr);
            prev -> next = newNode;
            return ;
        }
        at_pos += 1 ;
        prev = curr;
        curr = curr -> next;
    } while( curr != tail -> next ) ;    
    /// indicates that insert after tail
    if( pos == at_pos + 1 ) {
        ListNode *newNode = new ListNode( value, tail -> next ) ;
        tail -> next = newNode;
        tail = newNode;
        return ; /// true
    }
    return ; /// false
}
void insertBeforeNode( ListNode *loc, int value )
{
    if( tail == nullptr || ( tail != loc && tail == tail -> next ) ) {
        return ; /// false
    }
    if( tail -> next == loc ) {
        insertBeforeHead(value);
        return ; /// true
    }
    if( tail == loc ) {
        insertBeforeTail(value);
        return ; /// true
    }
    ListNode *prev = nullptr;
    ListNode *node = tail -> next;
    do {
        if( node == loc ) {
            ListNode *newNode = new ListNode(value, node);
            prev -> next = newNode;
            return ; /// true
        }
        prev = node;
        node = node -> next;
    } while( node != tail -> next ) ;
    return ; /// false
}
void insertAfterNode( ListNode *loc, int value )
{
    if( tail == nullptr || ( tail != loc && tail == tail -> next ) ) {
        return ; /// false
    }
    if( tail -> next == loc ) {
        insertAfterHead( value );
        return ; /// true
    }
    if( tail == loc ) {
        insertAfterTail( value );
        return ; /// true
    }
    ListNode *node = tail -> next;
    while( node != tail ) {
        if( node == loc ) {
            ListNode *newNode = new ListNode( value, node->next );
            node -> next = newNode;
            return ; /// true
        }
        node = node -> next;
    }
    return ; /// false
}
bool find_element( int to_find )
{
    if( tail -> next -> data == to_find || tail -> data == to_find ) {
        return true;
    }
    ListNode *node = tail -> next;
    while( node != tail ) {
        if( node -> data == to_find ) {
            return true;
        }
        node = node -> next;
    }
    return false;
}
void deleteHead()
{
    if( tail == nullptr || tail == tail -> next ) {
        tail = nullptr;
        return ;
    }
    ListNode *prevHead = tail -> next;

    tail -> next = prevHead -> next;

    prevHead -> next = nullptr;
    delete prevHead;
    return ;
}
void deleteTail()
{
    if( tail == nullptr || tail == tail -> next ) {
        tail = nullptr;
        return ;
    }
    ListNode *prev = nullptr;
    ListNode *node = tail -> next ;
    while( node != tail ) {
        prev = node;
        node = node -> next;
    }
    prev -> next = tail -> next;
    tail = prev;
    delete node;
    return ;
}
void deletePos( int pos )
{
    if( tail == nullptr ) return ;
    if( pos == 1 ) {
        deleteHead();
        return ;
    }
    ListNode *prev = nullptr;
    ListNode *head = tail -> next;
    ListNode *curr = tail -> next;
    int at_pos = 1;
    do {
        if( at_pos == pos ) {
            prev -> next = curr -> next;
            if( curr == tail ) {
                tail = prev;
                tail -> next = prev -> next;
            }
            return ;
        }
        at_pos += 1 ;
        prev = curr;
        curr = curr -> next;
    } while( curr != tail -> next ) ;
    return ;
}
void deleteNode( ListNode *loc )
{
    if( tail == nullptr || (tail == tail -> next && tail == loc ) ) {
        tail = nullptr;
        return ;
    }
    if( tail -> next == loc ) {
        deleteHead();
        return ; /// true
    }
    if( tail == loc ) {
        deleteTail();
        return ; /// true
    }
    ListNode *prev = tail -> next; /// head
    ListNode *node = tail -> next -> next; /// head -> next
    while( node != tail ) {
        if( node == loc ) {
            prev -> next = node -> next;
            delete node;
            return ; /// true
        }
        prev = node;
        node = node -> next;
    }
    return ; /// false
}
int main()
{
    vector<int> v(5);
    for( int i = 0; i < v.size(); i += 1 ) {
        v[i] = rand();
    }
    constructCLL(v);
    show();
    return 0;
}