#include<bits/stdc++.h>
using namespace std;
struct info
{
    int data; /// data part
    info* next; /// pointer to next node
};
info* head; /// pointer to head node
void insert_begin(int value)
{
    info* node = new info(); /// creating an instance of the structure type
    node->data = value;
    node->next = head;
    head = node;
    return ;
}
void insert_end(int value)
{
    info* node = new info();
    node->data = value;
    node->next = NULL;
    if(head==NULL) head = node;
    else{
        info* tmp = new info();
        tmp= head;
        while(tmp->next!=NULL) tmp = tmp->next;
        tmp->next = node;
    }
    return ;
}
void insert_pos(int value, int pos)
{
    info* node = new info();
    node->data = value;
    if(pos==1){
        node->next = head;
        head = node;
        /// cout << "valid insertion" << endl;
        return ; /// true
    }
    if(head==NULL && pos!=1){
        /// cout << "invalid insertion since there does not exist this position" << endl;
        return ; /// false
    }
    info* tmp = new info();
    tmp = head;
    int i=1;
    while(i<pos-1 && (tmp->next)!=NULL){
        i++;
        tmp = tmp->next;
    }
    if(i!=(pos-1)){
        /// cout << "invalid insertion since there does not exist this position" << endl;
        return ; /// false
    }
    node->next = tmp->next;
    tmp->next = node;
    /// cout << "valid insertion" << endl;
    return ; /// true
}
/// this function insert the given newValue before the first occurance of the given value
void insert_before_value(int value, int newValue)
{
    if(head==NULL){
        /// there is no element in the list
        /// then how can we insert before given value?

        /// cout << "can't insert" << endl;
        return ; /// false
    }
    info* node = new info();
    node->data = newValue;
    /// inserting at the beginning if the value matches the head's data
    if(head->data == value){
        node->next = head;
        head = node;
        /// cout << "inserted" << endl;
        return ; /// true
    }
    info* tmp = new info();
    tmp = head;
    while(tmp->next!=NULL){
        /// Inserting at the current position,
        /// if the next node has the desired value
        if(tmp->next->data==value){
            node->next = tmp->next;
            tmp->next = node;
            /// cout << "inserted" << endl;
            return ; /// true
        }
        tmp = tmp->next;
    }
    /// no elements match with the given value
    /// cout << "can't insert" << endl;
    return ; /// false
}
/// this function insert the given newValue after the first occurance of the given value
void insert_after_value(int value, int newValue)
{
    if(head==NULL){
        /// there is no element in the list
        /// then how can we insert after given value?

        /// cout << "can't insert" << endl;
        return ; /// false
    }
    info* node = new info();
    node->data = newValue;
    /// inserting after the head node if the value matches the head's data
    if(head->data == value){
        node->next = head;
        head = node;

        /// cout << "inserted" << endl;
        return ; /// true
    }
    info* tmp = new info();
    tmp = head;
    while(tmp!=NULL){
        if(tmp->data == value){
            node->next = tmp->next;
            tmp->next = node;

            /// cout << "inserted" << endl;
            return ; /// true
        }
        tmp = tmp->next;
    }

    /// cout << "can't insert" << endl;
    return ; /// false
}
int len()
{
    info* node = new info();
    node = head;
    int cnt=0;
    while(node!=NULL){
        node = node->next;
        cnt += 1;
    }
    return cnt;
}
bool find_element(int value)
{
    info* node = new info();
    node = head;
    while(node!=NULL){
        if(node->data == value) return true; /// element found
        node = node->next;
    }
    return false; /// element not found
}
void removeHead()
{
    if(head==NULL){
        /// the list is already empty,
        /// so can't remove

        /// cout << "can't remove" << endl;
        return ; ///false
    }
    /// Creating a temporary pointer to the current head
    info* node = new info();
    node = head;
    /// moving the head to the next node
    head = head->next;

    /// deleting the ex head node to free the memory
    /// if we can't free the memory, the linked list will be still working
    /// since we moved the head
    /// but it is better to free the memory
    delete node; /// successfully removed the head

    /// cout << "removed head" << endl;
    return ;/// true
}
void removeTail()
{
    if(head==NULL){
        /// the list is already empty,
        /// so can't remove

        /// cout << "can't remove" << endl;
        return ; /// false
    }
    if(head->next == NULL){
        /// there exist only one element
        //delete head;
        head = NULL;

        /// cout << "removed" << endl;
        return ; /// true
    }
    info* node = new info();
    info* prev = new info();
    prev = NULL;
    node = head;
    while(node != NULL){
        if(node->next == NULL){
            delete node;
            prev->next = NULL;
            /// cout << "removed" << endl;
            return ; /// true
        }
        prev = node;
        node = node->next;
    }
    /// cout << "can't remove" << endl;
    return ; /// false
}
void remove_pos(int pos)
{
    if(head==NULL){
        /// the list is already empty,
        /// so can't remove

        /// cout << "can't remove" << endl;
        return ; /// false
    }
    if(pos==1){
        info* node = new info();
        node = head;
        head = head->next;
        delete node;

        /// cout << "removed" << endl;
        return ; /// true
    }
    info* node = new info();
    node = head;
    info* prev = new info();
    prev = NULL;
    int cnt=0;
    while(node!=NULL){
        cnt += 1;
        if(cnt==pos){
            prev->next = node->next;
            delete node;
            /// cout << "removed" << endl;
            return ; /// true
        }
        prev = node;
        node = node->next;
    }
    /// cout << "can't remove" << endl;
    return ; /// false
}
/// this function removes the first occurance of the given value
void removeVal(int value)
{
    if(head==NULL){
        /// the list is already empty,
        /// so can't remove

        /// cout << "can't remove" << endl;
        return ; /// false
    }
    if(head->data == value){
        info* node = new info();
        node = head;
        head = head->next;
        delete node;

        /// cout << "removed" << endl;
        return ; /// true
    }
    info* node = new info();
    node = head;
    info* prev = new info();
    prev = NULL;
    while(node!=NULL){
        if(node->data==value){
            prev->next = node->next;
            delete node;
            /// cout << "removed" << endl;
            return ; /// true
        }
        prev = node;
        node = node->next;
    }
    /// cout << "can't remove" << endl;
    return ; /// false
}
/// Iterative approach
void reverseList()
{
    struct info *current, *prev, *later;
    current = head;
    prev = NULL;
    later = NULL;
    while(current!=NULL){
        later = current->next;
        current->next = prev;
        prev = current;
        current = later;
    }
    head = prev;
    return ;
}
/// recursive approach
void reverseList(struct info* node)
{
    if(node->next == NULL){
        head = node;
        return ;
    }
    reverseList(node->next);
    struct info* tmp = node->next;
    tmp->next = node;
    node->next = NULL;
}
void updateNode(int oldValue, int newValue)
{
    info* node = new info();
    node = head;
    while(node!=NULL){
        if(node->data == oldValue){
            node->data = newValue;
            return ;
        }
        node = node->next;
    }
    cout << "old value does not exist" << endl;
    return ;
}
void show()
{
    info* node = new info();
    node = head;
    while(node!=NULL){
        cout <<  node->data << " ";
        node = node->next;
    }
    cout << endl;
}
void reverseShow(struct info* node)
{
    if(node==NULL) return ;
    reverseShow(node->next);
    cout << node->data << " ";
}
int main()
{
    head = NULL; /// empty list though its not necessary to write this line since we declaring it globally
    insert_end(5);
    show(); /// 5
    insert_begin(1);
    show(); /// 1 5
    insert_end(8);
    show(); /// 1 5 8
    insert_pos(4,1);
    show(); /// 4 1 5 8
    insert_pos(13,3);
    show(); /// 4 1 13 5 8
    insert_before_value(13,10);
    show(); /// 4 1 10 13 5 8
    insert_after_value(4,17);
    show(); /// 17 4 1 10 13 5 8
    insert_after_value(8,20);
    show(); /// 17 4 1 10 13 5 8 20
    cout << len() << endl; /// 8
    cout << find_element(5) << endl; /// 1
    cout << find_element(15) << endl; /// 0
    removeHead();
    show(); /// 4 1 10 13 5 8 20
    removeTail();
    show(); /// 4 1 10 13 5 8
    remove_pos(5);
    show(); /// 4 1 10 13 8
    removeVal(10);
    show(); /// 4 1 13 8
    reverseList();
    show(); /// 8 13 1 4
    /// reverseShow(head); /// 4 1 13 8
    reverseList(head);
    show(); /// 4 1 13 8
    updateNode(4, 11);
    show(); /// 11 1 13 8
    return 0;
}
