//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================

// 206. 反转链表
// 题目：反转一个单链表        示例：输入: 1->2->3->4->5->NULL
//                                   输出: 5->4->3->2->1->NULL
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//迭代版 双指针

    ListNode* reverseList(ListNode* head) {
        ListNode* p0 = nullptr;
        ListNode* p1 = head;
        while(p1){
            ListNode * temp = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = temp;
        }
        return p0;
    }

//递归版

ListNode* reverseList1(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode * p = reverseList1(head->next);
    head->next->next = head; //head的下一个节点的next指向head，两节点之间便反向
    head->next = nullptr; //此时head的next节点应指向nullptr
    return p;
}

int main()
{
    return 0;
}
