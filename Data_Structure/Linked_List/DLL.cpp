#include<bits/stdc++.h>
using namespace std;
///DLL
class ListNode{
public:
    int data; /// data part
    ListNode *next; /// pointer to next node
    ListNode *prev; /// pointer to prev node
    ListNode(){
        this -> data = 0;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    /// constructor with only data (next pointer set to nullptr)
    ListNode(int data){
         this -> data = data;
         this -> next = nullptr;
         this -> prev = nullptr;
    }
    /// constructor with both data and next pointer
    ListNode(int data, ListNode *prev, ListNode *next){
        this -> data = data;
        this -> prev = prev;
        this -> next = next;
    }
};
ListNode *head;
int listLen()
{
    int cnt = 0;
    ListNode *node = new ListNode();
    node = head;
    while( node != nullptr ) {
        node = node -> next;
        cnt += 1;
    }
    return cnt;
}
void show()
{
    if( head == nullptr ) return ;
    ListNode* node = new ListNode();
    node = head;
    while( node != nullptr ){
        cout << node -> data << " ";
        node = node->next;
    }
    cout << endl;
}
void reverse_show(ListNode *node)
{
    if( node == nullptr ) return ;
    reverse_show(node->next);
    cout << node -> data << " ";
    return ;
}
void constructDLL(vector<int>& arr) {
    ListNode *node = new ListNode( arr[0] ) ;
    head = node;
    for( int i = 1; i < arr.size(); i += 1 ) {
        ListNode *newNode = new ListNode( arr[i] ) ;
        newNode -> prev = node;
        node -> next = newNode;
        node = newNode;
    }
    return ;
}
void insertBeforeHead( int value )
{
    ListNode *newHead = new ListNode( value, nullptr, head );
    ListNode *oldHead = head;
    if( oldHead != nullptr ) {
        oldHead -> prev = newHead;
    }
    head = newHead;
    return ;
}
void insertAfterHead( int value )
{
    if( head == nullptr ) {
        ListNode *newHead = new ListNode( value, nullptr, head );
        head = newHead;
        return ;
    }
    ListNode *node = new ListNode( value, head, head -> next ) ;
    head -> next -> prev = node;
    head -> next = node;
    return ;
}
void insertBeforeTail( int value )
{
    if( head == nullptr || head -> next == nullptr ) {
        insertBeforeHead( value );
        return ;
    }
    ListNode *node = head;
    while( node -> next != nullptr ) {
        node = node -> next;
    }
    ListNode *newNode = new ListNode( value, node -> prev, node );
    (node -> prev) -> next = newNode;
    node -> prev = newNode;
    return ;
}
void insertAfterTail( int value )
{
    if( head == nullptr || head -> next == nullptr ) {
        insertAfterHead( value ) ;
        return ;
    }
    ListNode *tail = head;
    while( tail -> next != nullptr ) {
        tail = tail -> next;
    }
    ListNode *newNode = new ListNode( value, tail, nullptr );
    tail -> next = newNode;
    return ;
}
void insertPos( int value, int pos )
{
    if( head == nullptr ) {
        if( pos ==  1 ) {
            ListNode *node = new ListNode(value);
            head = node;
            return ;
        }
        else {
            return ;
        }
    }
    if( pos == 1 ) {
        ListNode *node = new ListNode(value, nullptr, head);
        head -> prev = node;
        head = node;
        return ;
    }
    ListNode *before = nullptr;
    ListNode *curr = head;
    int at_pos = 0;
    while( curr != nullptr ) {
        if( at_pos == pos - 1 ) {
            ListNode *newNode = new ListNode(value, before, curr );
            before -> next = newNode;
            curr -> prev = newNode;
            return ;
        } 
        at_pos += 1;
        before = curr;
        curr = curr -> next;
    }
    /// indicates that insert after tail
    if( pos == at_pos + 1 ) {
        ListNode *newNode = new ListNode( value, before, nullptr ) ;
        before -> next = newNode;
        return ; /// true
    }
    return ;
}
void insertBeforeNode( ListNode* loc, int value )
{
    if( head == nullptr ) {
        return ;
    }
    if( loc == head ) {
        insertBeforeHead( value ) ;
        return ;
    }
    ListNode *node = head;
    while( node != nullptr ) {
        if( node == loc ) {
            ListNode *newNode = new ListNode( value, node->prev, loc ) ;
            node -> prev -> next = newNode;
            node -> prev = newNode;
            return ;
        }
        node = node -> next;
    }
    return ;
}
void insertAfterNode( ListNode *loc, int value )
{
    if( head == nullptr ) {
        return ;
    }
    if( loc == head ) {
        insertAfterHead( value ) ;
        return ;
    }
    ListNode *node = head;
    while( node != nullptr ) {
        if( node == loc ) {
            ListNode *newNode = new ListNode( value, loc, loc->next ) ;
            if( loc -> next != nullptr ) {
                loc -> next -> prev = newNode;
            }
            loc -> next = newNode;
            return ; /// true
        }
        node = node -> next;
    }
    return ;
}
bool find_element( int value )
{
    ListNode* node = head;
    while( node != nullptr ) {
        if( node -> data == value ) {
            return true;
        }
        node = node -> next;
    }
    return false;
}
void deleteHead()
{
    if( head == nullptr ) {
        return ;
    }
    if( head -> next == nullptr ) {
        head = nullptr;
        return ;
    }
    ListNode *prevHead = head;

    head = head -> next;
    head -> prev = nullptr;

    prevHead -> next = nullptr;
    delete prevHead;
    return ;
}
void deleteTail()
{
    if( head == nullptr || head -> next == nullptr ) {
        head = nullptr ;
        return ;
    }
    ListNode *tail = head;
    while( tail -> next != nullptr ) {
        tail = tail -> next;
    }
    tail -> prev -> next = nullptr;
    tail -> prev = nullptr;
    delete tail;
    return ;
}
void deletePos( int pos )
{
    if( head == nullptr ) {
        return ;
    }
    if( pos == 1 ) {
        deleteHead();
        return ;
    }
    ListNode *curr = head;
    int at_pos = 1;
    while( curr != nullptr ) {
      if( at_pos == pos ) {
          curr -> prev -> next = curr -> next;
          if( curr -> next != nullptr ) curr -> next -> prev = curr -> prev;
          curr -> prev = nullptr;
          curr -> next = nullptr;
          delete curr;
          return ;
      }
      at_pos += 1;
      curr = curr -> next;
    }
    return ;
}
void deleteNode( ListNode *loc )
{
    if( head == nullptr ) {
        return ;
    }
    ListNode *node = head;
    while( node != nullptr ) {
        if( node == loc ) {
            break;
        }
        node = node -> next;
    }
    if( node != nullptr ) {
        if( node -> prev == nullptr && node -> next == nullptr ) {
            delete node;
            head = nullptr;
            return ;
        }
        else if( node -> prev == nullptr ) {
            ListNode *prevHead = head;
            head = head -> next;
            head -> prev = nullptr;
            delete prevHead;
            return ;
        }
        else if( node -> next == nullptr ) {
            node -> prev -> next = nullptr;
            node -> prev = nullptr;
            delete node;
            return ;
        }
        else {
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
            node -> prev = nullptr;
            node -> next = nullptr;
            delete node;
            return ;
        }
    }
    return ;
}
void updateNode( ListNode *toUpdate, int value )
{
    ListNode *node = head;
    while( node != nullptr ) {
        if( node == toUpdate ) {
            node -> data = value;
            return ;
        }
        node = node -> next;
    }
    return ;
}
ListNode* reverseList ( ListNode * head )
{
    ListNode *before = nullptr, *later = nullptr, *curr = head;
    if( head == nullptr || head -> next == nullptr ) {
        return head;
    }
    while( curr != nullptr ) {
        before = curr -> prev;
        later = curr -> next;
        curr -> prev = later;
        curr -> next = before;
        curr = later;
    }
    return before -> prev; /// update head, after returning from this function
}
ListNode* middleNode( )
{
    /// Using Tortoise and Hare Algorithm
    ListNode *Middle = head;
    ListNode *endNode = head;
    while( endNode != nullptr && endNode -> next != nullptr ) {
        Middle = Middle -> next;
        endNode = endNode -> next -> next;
    }
    return Middle;
    /// 1 2 3 4 5 -> return 3
    /// 1 2 3 4 5 6-> return 4

    /// to get the firstMiddle in even number of elements
    /// change the condition in while-loop
    /// write endNode->next != nullptr && endNode->next->next != nullptr
}
void deleteMiddle()
{
    if( head -> next == nullptr ) {
        head = nullptr;
        return ;
    }
    ListNode *Middle = head;
    ListNode *endNode = head;
    while( endNode != nullptr && endNode -> next != nullptr ) {
        Middle = Middle -> next;
        endNode = endNode -> next -> next;
    }
    Middle -> prev -> next = Middle -> next;
    delete Middle;
    return ;
}
int main()
{
    vector<int> v(5);
    for( int i = 0; i < 5; i += 1 ) {
        v[i] = rand();
    }
    constructDLL(v);
    show();
    deleteMiddle();
    show();
}