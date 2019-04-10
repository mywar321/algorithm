#include <iostream>
#include <stdexcept>
using namespace std;

struct ListNode{
    int val = 0;
    ListNode *next = nullptr;
};
/*带有哨兵节点的链表*/
class LinkList {

public:
    LinkList();
    LinkList(const LinkList& list);

    ~LinkList();


    LinkList(int arr[], int length);
    void ascendNum(int n);
    friend ostream& operator<<(ostream &out, const LinkList &list);

    void reverse();
    bool hasCircle();
    void merge(LinkList list);
    int removeNthFromEnd(int n);
    ListNode *middleNode();


private:
    ListNode *head = new ListNode;
};

LinkList::LinkList()
{

}

LinkList::LinkList(const LinkList &list)
{
    ListNode *node = head;
    ListNode *trvlNode = list.head;
    while (trvlNode->next != nullptr) {
        trvlNode = trvlNode->next;
        node->next = new ListNode;
        node = node->next;
        node->val = trvlNode->val;
    }
    node->val = trvlNode->val;
}

LinkList::~LinkList()
{

}

LinkList::LinkList(int arr[], int length)
{
    ListNode *node = head;

    for (int i=0; i<length; i++) {
        node->next = new ListNode;
        node = node->next;
        node->val = arr[i];
    }
}

void LinkList::ascendNum(int n)
{
    ListNode *node = head;

    for (int i=0; i<n; i++) {
        node->next = new ListNode;
        node = node->next;
        node->val = i;  
    }

}

ostream& operator<<(ostream &out, const LinkList &list)
{
    ListNode *travelNode = list.head->next;
    while (travelNode != nullptr) {
        out << travelNode->val << ",";
        travelNode = travelNode->next;
    }
    return out;
}

/*反转链表*/
void LinkList::reverse()
{

    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    ListNode *current = head->next;


    while (current != nullptr) {
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
    }

    head->next = prev;
}
/*合并2条有序链表*/
void LinkList::merge(LinkList list)
{
    if (list.head->next == nullptr)
        return;

    ListNode *pres = head;
    ListNode *cur_1 = head->next;
    ListNode *cur_2 = list.head->next;
    while(pres != nullptr){   //写成while（true）也可以

        if (cur_1 == nullptr) {   //终止条件：当某一条链表走到了尽头，则将另外一条链表剩余部分接上
            pres->next = cur_2;
            break;
        }
        if (cur_2 == nullptr) {
            pres->next = cur_1;
            break;
        }

        if (cur_1->val < cur_2->val) {
            pres->next = cur_1;
            cur_1 = cur_1->next;
        }
        else {
            pres->next = cur_2;
            cur_2 = cur_2->next;
        }

        pres = pres->next;
    }

}

/*求中间节点*/
ListNode *LinkList::middleNode()
{
    ListNode *runner = head->next;
    ListNode *walker = head->next;
    if (runner == nullptr)
        return head;

    while ( runner != nullptr && runner->next != nullptr) {
        walker = walker->next;
        runner = runner->next->next;
    }
    return walker;
}
/*删除倒数第n个节点,从1开始*/
int LinkList::removeNthFromEnd(int n)
{

    ListNode *walker = head->next;
    ListNode *runner = head->next;

    if (walker ==nullptr || n <= 0)
        return 0;

    while (n > -1 && runner != nullptr) {  //先使得快指针与慢指针之间的距离为n+1
        n--;
        runner = runner->next;
    }

    if (n > -1)
        return 0;

    while ( runner != nullptr) {
        walker = walker->next;
        runner = runner->next;
    }
    ListNode *removedNode = walker->next;
    walker->next = removedNode->next;
    delete removedNode;
    removedNode = nullptr;

    return 1;
}

int main()
{
    LinkList list;
    list.ascendNum(4);
    cout << list << endl;

    cout << "翻转链表:" << endl;
    list.reverse();
    cout << list << endl;

    cout << "链表中点值:" << endl;
    cout << list.middleNode()->val << endl;


    if (list.removeNthFromEnd(3) == 1)
        cout << list << endl;
    else
        cout << "错误的输入" << endl;

    cout << "合并链表：" << endl;
    int arr1[] = {1,1,1,1,1};
    int arr2[] = {2,4,6,8,10};
    LinkList list3(arr1, sizeof(arr1)/sizeof(int));
    LinkList list4(arr2, sizeof(arr2)/sizeof(int));
    cout << list3 << endl;
    cout << list4 << endl;
    list3.merge(list4);
    cout << list3 << endl;


    cout << "Hello World!" << endl;
    return 0;
}
