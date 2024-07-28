#include<bits/stdc++.h>
using namespace std;
///SLL
class ListNode{
public:
    int data; /// data part
    ListNode *next; /// pointer to next node
    ///
    ListNode(){
        this->data = 0;
        this->next = nullptr;
    }
    /// constructor with only data (next pointer set to nullptr)
    ListNode(int data){
         this->data = data;
         this->next = nullptr;
    }
    /// constructor with both data and next pointer
    ListNode(int data, ListNode *next){
         this->data = data;
         this->next = next;
    }
};
ListNode *head;
int listLen()
{
    int cnt = 0;
    ListNode *node = head;
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
        cout <<  node->data << " ";
        node = node->next;
    }
    cout << endl;
}
void reverseShow(ListNode *node )
{
    if( node == nullptr ) return ;
    reverseShow( node -> next );
    cout << node -> data << " ";
    return ;
}
void constructLL(vector<int>& arr)
{
    if( arr.size() == 0 ) return ;
    ListNode *node = new ListNode( arr[0] ) ;
    head = node;
    for( int i = 1; i < arr.size(); i += 1 ) {
        ListNode *newNode = new ListNode( arr[i] ) ;
        node -> next = newNode;
        node = newNode;
    }
    return ;
}
void insertBeforeHead( int value )
{
    ListNode *node = new ListNode(value, head);
    head = node;
    return ;
}
void insertAfterHead( int value )
{
    if( head == nullptr ) {
        ListNode *node = new ListNode(value, head);
        head = node;
        return ;
    }
    ListNode *node = new ListNode( value, head -> next ) ;
    head -> next = node;
    return ;
}
void insertBeforeTail( int value )
{
    if( head == nullptr || head -> next == nullptr ) {
        ListNode *node = new ListNode(value, head);
        head = node;
        return ;
    }
    ListNode *node = head;
    ListNode *prev = nullptr;
    while( node -> next != nullptr ) {
        prev = node;
        node = node -> next;
    }
    ListNode *newNode = new ListNode( value, node );
    prev -> next = newNode;
    return ;
}
void insertAfterTail( int value )
{
    ListNode *node = new ListNode( value );
    if( head == nullptr ) {
        head = node;
    }
    else {
        ListNode *tmp = head;
        while( tmp -> next != nullptr ) {
            tmp = tmp -> next;
        }
        tmp -> next = node;
    }
    return ;
}
void insertPos( int value, int pos )
{
    if( head == nullptr ) {
        if( pos == 1 ) {
            ListNode *node = new ListNode(value, head);
            head = node;
            return ; /// true
        }
        else {
            return ; /// false
        }
    }
    if( pos == 1 ) {
        ListNode *node = new ListNode(value, head);
        head = node;
        return ; /// true
    }
    ListNode *prev = nullptr;
    ListNode *curr = head;
    int at_pos = 0;
    while( curr != nullptr ) {
        if( at_pos == pos-1 ) {
            ListNode *newNode = new ListNode( value, curr);
            prev -> next = newNode;
            return ; /// true
        }
        at_pos += 1;
        prev = curr;
        curr = curr -> next;
    }
    /// indicates that insert after tail
    if( pos == at_pos + 1 ) {
        ListNode *newNode = new ListNode( value ) ;
        prev -> next = newNode;
        return ; /// true
    }
    return ; /// false
}
void insertBeforeNode( ListNode* loc, int value )
{
    if( head == nullptr ) {
        return ; /// false
    }
    if( loc == head ) {
        ListNode *node = new ListNode(value, head);
        head = node;
        return ;
    }
    ListNode *node = head;
    ListNode *prev = nullptr;
    while( node != nullptr ) {
        if( node == loc ) {
            ListNode *newNode = new ListNode( value, loc ) ;
            prev -> next = newNode;
            return ; /// true
        }
        prev = node;
        node = node -> next;
    }
    return ; /// false;
}
void insertAfterNode( ListNode *loc, int value )
{
    if( head == nullptr ) {
        return ; /// false
    }
    if( loc == head ) {
        ListNode *node = new ListNode( value, head -> next ) ;
        head -> next = node;
        return ;
    }
    ListNode *node = head;
    while( node != nullptr ) {
        if( node == loc ) {
            ListNode *newNode = new ListNode( value, loc->next ) ;
            loc -> next = newNode;
            return ; /// true
        }
        node = node -> next;
    }
    return ; /// false;
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
    /// Creating a temporary pointer to the current head
    ListNode *node = head;
    /// moving the head to the next node
    head = head->next;

    /// deleting the ex-head node to free the memory
    /// if we can't free the memory, the linked list will be still working
    /// since we moved the head
    /// but it is better to free the memory
    delete node; /// successfully removed the head

    return ;/// true
}
void deleteTail()
{
    if( head == nullptr || head -> next == nullptr ) {
        head = nullptr; /// there exist only one element //delete head;
        return ; /// true
    }
    ListNode *node = head;
    while( node -> next -> next != nullptr ) {
        node = node -> next;
    }
    delete( node -> next );
    node -> next = nullptr;
    return ; /// true
}
void deletePos( int pos )
{
    if( head == nullptr ) {
        return ; /// false
    }
    if( pos == 1 ) {
        ListNode *node = head;
        head = head->next;

        delete node;

        return ;/// true
    }
    ListNode *prev = nullptr, *curr = head;
    int at_pos = 1;
    while( curr != nullptr ) {
        if( at_pos == pos ) {
            prev -> next = curr -> next;
            delete curr;
            return ;
        }
        at_pos += 1;
        prev = curr;
        curr = curr -> next;
    }
    return ;
}
void deleteNode( ListNode *loc )
{
    if( head == nullptr ) {
        return ; /// false - there is no element
    }
    ListNode *node = head;
    ListNode *prev = nullptr;
    while( node != nullptr ) {
        if( node == loc ) {
            break;
        }
        prev = node;
        node = node -> next;
    }
    if( node != nullptr ) {
        if( prev == nullptr && node -> next == nullptr ) {
            delete node;
            head = nullptr;
            return ; /// true
        }
        else if( prev == nullptr ) {
            ListNode *node = head;
            head = head->next;
            delete node;
            return ; /// true
        }
        else if( node -> next == nullptr ) {
            prev -> next = nullptr;
            delete node;
            return ; /// true
        }
        else {
            prev -> next = node -> next;
            node -> next = nullptr;
            delete node;
            return ; /// true
        }
    }
    return ; /// false
}
void updateNode( ListNode *toUpdate, int value )
{
    ListNode *node = head;
    while( node != nullptr ) {
        if( node == toUpdate ) {
            node -> data = value;
            return ; /// true;
        }
        node = node -> next;
    }
    return ; /// false;
}
/// iterative approach
ListNode* reverseList( ListNode *head )
{
    ListNode* prev = nullptr;
    ListNode* later = nullptr;
    ListNode* curr = head;
    while( curr != nullptr ) {
        later = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = later;
    }
    return prev; /// update head, after returning from this function
}
ListNode* middleNode(ListNode *head)
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
    ListNode *prevMiddle = nullptr;
    ListNode *Middle = head;
    ListNode *endNode = head;
    while( endNode != nullptr && endNode -> next != nullptr ) {
        prevMiddle = Middle;
        Middle = Middle -> next;
        endNode = endNode -> next -> next;
    }
    prevMiddle -> next = Middle -> next;
    delete Middle;
    return ;
}
bool hasCycle()
{
    /// this function returns true if there is cycle
    /// Using Tortoise and Hare Algorithm
    ListNode* slow = head;
    ListNode* fast = head;
    while( fast != nullptr && fast->next != nullptr ){
        slow = slow->next;
        fast = fast->next->next;
        if( slow == fast ) return true;
    }
    return false;
}
int findLoopLength()
{
    ListNode *slow = head;
    ListNode *fast = head;
    while( fast != nullptr && fast -> next != nullptr ) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if( slow == fast ) {
            int cnt = 1;
            fast = fast -> next;
            while( fast != slow ) {
                fast = fast -> next;
                cnt += 1;
            }
            return cnt;
        }
    }
    return 0;
}
ListNode* headOfCycle()
{
    ListNode *slow = head;
    ListNode *fast = head;
    while( fast != nullptr && fast -> next != nullptr ) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if( slow == fast ) {
            slow = head;
            while( slow != fast ) {
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return nullptr;
}
bool isPalindrome( ListNode* head )
{
    ListNode *firstMiddle = head;
    ListNode *endNode = head;
    while( endNode -> next != nullptr && endNode -> next -> next != nullptr ) {
        firstMiddle = firstMiddle -> next;
        endNode = endNode -> next -> next;
    }
    ListNode* newHead = reverseList(firstMiddle->next);

    ListNode* first = head;
    ListNode* second = newHead;

    while( second != nullptr ) {
        if( first -> data != second -> data ) {
            reverseList( firstMiddle -> next);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseList(firstMiddle->next);
    return true;
}
ListNode* mergeTwoLists(ListNode* first, ListNode* second)
{
    /// here both the lists are sorted
    ListNode *curr1 = first;
    ListNode *curr2 = second;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while( curr1 != nullptr && curr2 != nullptr ) {
        if( curr1 -> data <= curr2 -> data ) {
            prev -> next = curr1;
            prev = curr1;
            curr1 = curr1 -> next;
        }
        else {
            prev -> next = curr2;
            prev = curr2;
            curr2 = curr2 -> next;
        }
    }
    if( curr1 != nullptr ) {
        prev -> next = curr1;
    } else {
        prev -> next = curr2;
    }
    ListNode *newHead = dummy -> next;
    dummy -> next = nullptr;
    delete dummy;
    return newHead;
}
ListNode* sortList(ListNode *head)
{
    /// Using Merge Sort technique
    if( head == nullptr || head -> next == nullptr ) return head;
    ListNode *middle = middleNode(head); /// Find first middle, modify the find middleNode codes otherwise it will give error
    ListNode *leftHead = head;
    ListNode *rightHead = middle -> next;
    middle -> next = nullptr;
    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);
    return mergeTwoLists( leftHead, rightHead ) ;
}
int main()
{
    vector<int> v (3);
    for( int i = 0; i < 3; i += 1 ) {
        v[i] = rand();
    }
    v[0] = -1;
    constructLL(v);
    show();
    head = sortList(head);
    cout << head -> data << endl;
    show();
    return 0;
}
