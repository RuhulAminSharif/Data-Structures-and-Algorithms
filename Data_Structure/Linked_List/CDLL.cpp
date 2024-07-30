#include <bits/stdc++.h>
using namespace std;
/// CDLL
class ListNode
{
public:
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode()
    {
        this->data = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }
    ListNode(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
    ListNode(int data, ListNode *prev, ListNode *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};
ListNode *head;
int listLen()
{
    if (head == nullptr)
        return 0;
    if (head == head->next)
        return 1;
    int len = 1;
    ListNode *curr = head;
    while (curr != head->prev)
    {
        len += 1;
        curr = curr->next;
    }
    return len;
}
void show()
{
    if (head == nullptr)
        return;
    ListNode *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head->prev->next);
    cout << endl;
    return;
}
void constructCDLL(vector<int> &v)
{
    if (v.size() == 0)
        return;
    ListNode *curr = new ListNode(v[0]);
    head = curr;
    for (int i = 1; i < v.size(); i += 1)
    {
        ListNode *newNode = new ListNode(v[i], curr, curr->next);
        curr->next = newNode;
        curr = newNode;
    }
    head->prev = curr;
    curr->next = head;
    return;
}
void insertBeforeHead(int value)
{
    if (head == nullptr)
    {
        ListNode *newNode = new ListNode(value);
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }
    if (head == head->next)
    {
        ListNode *newHead = new ListNode(value, head, head);
        head->prev = newHead;
        head->next = newHead;
        head = newHead;
        return;
    }
    ListNode *newHead = new ListNode(value, head->prev, head);
    head->prev->next = newHead;
    head->prev = newHead;
    head = newHead;
    return;
}
void insertAfterHead(int value)
{
    if (head == nullptr)
    {
        ListNode *newNode = new ListNode(value);
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }
    if (head == head->next)
    {
        ListNode *newNode = new ListNode(value, head, head);
        head->next = head->prev = newNode;
        return;
    }
    ListNode *newNode = new ListNode(value, head, head->next);
    head->next->prev = newNode;
    head->next = newNode;
    return;
}
void insertBeforeTail(int value)
{
    if (head == nullptr || head == head->next)
    {
        insertBeforeHead(value);
        return;
    }
    ListNode *tail = head->prev;
    ListNode *newNode = new ListNode(value, tail->prev, tail);
    tail->prev->next = newNode;
    tail->prev = newNode;
    return;
}
void insertAfterTail(int value)
{
    if (head == nullptr || head == head->next)
    {
        insertAfterHead(value);
        return;
    }
    ListNode *newNode = new ListNode(value, head->prev, head);
    head->prev->next = newNode;
    head->prev = newNode;
    return;
}
bool find_element(int to_find)
{
    ListNode *curr = head;
    do
    {
        if (curr->data == to_find)
        {
            return true;
        }
        curr = curr->next;
    } while (curr != head);
    return false;
}
void deleteHead()
{
    if (head == nullptr || head == head->next)
    {
        head = nullptr;
        return;
    }
    ListNode *newHead = head->next;
    newHead->prev = head->prev;
    head->prev->next = newHead;
    head = newHead;
    return;
}
void deleteTail()
{
    if (head == nullptr || head == head->next)
    {
        head = nullptr;
        return;
    }
    ListNode *tail = head->prev;
    head->prev = tail->prev;
    tail->prev->next = head;
    tail->prev = nullptr;
    tail->next = nullptr;
    delete tail;
    return;
}
void deletePos(int pos)
{
    if (head == nullptr)
        return;
    if (pos == 1)
    {
        deleteHead();
        return;
    }
    ListNode *curr = head;
    int at_pos = 1;
    do
    {
        if (at_pos == pos)
        {
            ListNode *before = curr->prev;
            before->next = curr->next;
            curr->next->prev = before;
            return;
        }
        at_pos += 1;
        curr = curr->next;
    } while (curr != head);
    return;
}
void deleteNode(ListNode *loc)
{
    if (head == nullptr || (head == head->next && head == loc))
    {
        head = nullptr;
        return;
    }
    if (head == loc)
    {
        deleteHead();
        return; /// true
    }
    if (head->prev == loc)
    {
        deleteTail();
        return; /// true
    }
    ListNode *curr = head->next;
    while (curr != head)
    {
        if (curr == loc)
        {
            ListNode *before = curr->prev;
            before->next = curr->next;
            curr->next->prev = before;
            delete curr;
            return; /// true
        }
        curr = curr->next;
    }
    return; /// false
}
int main()
{
    vector<int> v(3);
    for (int i = 0; i < v.size(); i += 1)
    {
        v[i] = rand();
    }
    constructCDLL(v);
    show();
    return 0;
}
