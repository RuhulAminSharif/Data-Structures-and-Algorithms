#include<bits/stdc++.h>
using namespace std;
struct info
{
    int data; /// data part
    info* prev; /// pointer to previous node
    info* next; /// pointer to next node
};
info* head;
void insertBeforeHead(int value)
{
    info* node = new info();
    node->data = value;
    node->prev = NULL;
    node->next = head;
    head = node;
    return ;
}
void insertAfterHead(int value)
{
    info* node = new info();
    node->data = value;
    if(head==NULL){
        node->prev = NULL;
        node->next = head;
        head = node;
        return ;
    }
    node->prev = head;
    node->next = head->next;
    if(head->next != NULL) head->next->prev = node;
    head->next = node;
    return ;
}
void insertBeforeTail(int value)
{
    info* node = new info();
    node->data = value;
    if(head==NULL || head->next == NULL){
        node->prev = NULL;
        node->next = head;
        head = node;
        return ;
    }
    info* tmp = new info();
    tmp = head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    node->prev = tmp->prev;
    node->next = tmp;
    tmp->prev->next = node;
    tmp->prev = node;
    return ;
}
void insertAfterTail(int value)
{
    info* node = new info();
    node->data = value;
    if(head==NULL){
        node->prev = NULL;
        node->next = head;
        head = node;
        return ;
    }
    info* tmp = new info();
    tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    node->prev = tmp;
    tmp->next = node;
    node->next = NULL;
    return ;
}
void insert_pos(int value, int pos)
{
    info* node = new info();
    node->data = value;
    if(pos==1){
        node->prev = NULL;
        node->next = head;
        head = node;
        return ; /// true
    }
    if(head==NULL && pos!=1){
        return ;/// false ///can't insert, this is not a valid position
    }
    info* tmp = new info();
    tmp = head;
    int i = 1;
    while(i<pos-1 && tmp->next!=NULL){
        tmp = tmp->next;
        i++;
    }
    if(i!=pos-1){
        return ; /// false
    }
    node->prev = tmp;
    node->next = tmp->next;
    if(tmp->next != NULL) tmp->next->prev = node;
    tmp->next = node;
    return ; /// true

}
void insertBeforeNode(info* loc, int value)
{
    info* node = new info();
    node->data = value;
    if(head==NULL){
        /// cout << "can't insert";
        return ; /// false
    }
    if(loc==head){
        node->prev = NULL;
        node->next = head;
        head = node;
        return ; /// true
    }
    info* tmp = new info();
    tmp = head;
    while(tmp!=NULL){
        if(tmp==loc){
            node->prev = tmp->prev;
            node->next = tmp;
            node->prev->next = node;
            tmp->prev = node;
            return ; /// true
        }
        tmp = tmp->next;
    }
    /// cout << "can't insert";
    return ; /// false
}
void insertAfterNode(info* loc, int value)
{
    info* node = new info();
    node->data = value;
    if(head==NULL){
        /// cout << "can't insert";
        return ; /// false
    }
    if(loc==head){
        node->prev = head;
        node->next = head->next;
        if(head->next!=NULL) head->next->prev = node;
        head->next = node;
        return ; /// true
    }
    info* tmp = new info();
    tmp = head;
    while(tmp!=NULL){
        if(tmp==loc){
            node->prev = tmp;
            node->next = tmp->next;
            if(node->next!=NULL) tmp->next->prev = node;
            tmp->next = node;
            return ; /// true
        }
        tmp = tmp->next;
    }
    /// cout << "can't insert";
    return ; /// false
}
void deleteHead()
{
    if(head==NULL){
        return ;
    }
    if(head->next == NULL){
        head = NULL;
        return ;
    }
    info* prevHead = new info();
    prevHead = head;

    head = head->next;
    head->prev = NULL;

    prevHead->next = NULL;
    delete prevHead;
    return ;
}
void deleteTail()
{
    if(head==NULL) return ;
    if(head->next==NULL){
        head = NULL;
        return ;
    }
    info* node = new info();
    node = head;
    while(node->next != NULL){
        node = node->next;
    }
    node->prev->next = NULL;
    node->prev = NULL;
    delete node;
    return ;
}
void deletePos(int pos)
{
    if(head==NULL) return ;
    bool fg = false;
    int cnt=0;
    info* node = new info();
    node = head;
    while(node!=NULL){
        cnt++;
        if(cnt==pos){
            fg = true;
            break;
        }
        node = node->next;
    }
    if(fg){
        if(node->prev==NULL && node->next==NULL){
            delete node;
            head = NULL;
            return ;
        }
        else if(node->prev == NULL){
            return deleteHead();
        }
        else if(node->next==NULL){
            return deleteTail();
        }
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = NULL;
            node->next = NULL;
            delete node;
            return ;
        }
    }
    else{
        return ; /// not possible to delete
    }
}
void deleteNode(info* loc)
{
    if(head==NULL){
        return ;
    }
    info* node = new info();
    node = head;
    while(node!=NULL){
        if(node==loc){
            break;
        }
        node = node->next;
    }
    if(node!=NULL){
        if(node->prev==NULL && node->next==NULL){
            delete node;
            head = NULL;
            return ;
        }
        else if(node->prev == NULL){
            return deleteHead();
        }
        else if(node->next==NULL){
            return deleteTail();
        }
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = NULL;
            node->next = NULL;
            delete node;
            return ;
        }
    }
}
void updateNode(info* loc, int newValue)
{
    info* node = new info();
    node = head;
    while(node!=NULL){
        if(node==loc){
            node->data = newValue;
            return ; /// true
        }
        node = node->next;
    }
    /// given location doesn't exist
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
        if(node->data == value) return true;
        node = node->next;
    }
    return false;
}
void show()
{
    info* node = new info();
    node =  head;
    while(node!=NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
    return ;
}
void reverseShow(info* node)
{
    if(node==NULL) return ;
    reverseShow(node->next);
    cout << node->data << " ";
}
int main()
{
    head = NULL;
    insertBeforeHead(7);
    show(); /// 7
    insertAfterHead(10);
    show(); /// 7 10
    insertBeforeTail(100);
    show(); /// 7 100 10
    insertAfterTail(8);
    show(); /// 7 100 10 8
    insert_pos(111, 5);
    show(); /// 7 100 10 8 111
    info* node= new info();
    node = head;
    while(node->next!=NULL){
        node = node->next;
    }
    insertBeforeNode(node,10000);
    show(); /// 7 100 10 8 10000 111
    insertAfterNode(node, 580);
    show(); /// 7 100 10 8 10000 111  580
    deleteHead();
    show(); /// 100 10 8 10000 111 580
    deleteTail();
    show(); /// 100 10 8 10000 111
    deletePos(3);
    show(); /// 100 10 10000 111
    deleteNode(node);
    show(); /// 100 10 10000
    cout << len() << endl; /// 3
    cout << find_element(100) << endl; /// 1
    reverseShow(head); cout << endl; /// 10000 10 100
    show(); /// 100 10 10000
    updateNode(head->next, 1245);
    show(); /// 100 1245 10000
    return 0;
}