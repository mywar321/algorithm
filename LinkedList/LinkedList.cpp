#include <iostream>

using namespace std;

struct ListNode{
    int val = 0;
    ListNode *next = nullptr;
};

class LinkList {

public:
    LinkList();
    ~LinkList();

    void ascendNum(int n);
    friend ostream& operator<<(ostream &out, const LinkList &list);

    void reverse();
    bool hasCircle();
    void merge(const LinkList& list);
    void removeNthFromEnd();
    ListNode *middleNode();


private:
    ListNode *head = new ListNode;
};

LinkList::LinkList()
{

}

LinkList::~LinkList()
{

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


int main()
{
    LinkList list;
    list.ascendNum(10);
    cout << list << endl;

    list.reverse();
    cout << list << endl;

    cout << "Hello World!" << endl;
    return 0;
}
