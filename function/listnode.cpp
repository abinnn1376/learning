#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define longlong ll



struct ListNode
{
    int val;
    ListNode* next;
    ListNode* last;

    ListNode():val(0),next(nullptr){};
    ListNode(int val) : val(val),next(nullptr){};
    ListNode(int val,ListNode* next) : val(val),next(next){};
};


signed main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;

    // 打印链表节点的值
    ListNode* current = node1;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;


    return 0;

}




// 反转单链表
ListNode* reverseList(ListNode* head)
{
    ListNode* pre = nullptr;
    ListNode* next = nullptr;
    
    while (head != nullptr) 
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    
    return pre;
}

// 反转双向链表
ListNode* reverseList(ListNode* head)
{
    ListNode* pre = nullptr;
    ListNode* next = nullptr;
    ListNode* last = nullptr;
    
    while (head != nullptr) 
    {
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    }
    
    return pre;
}