//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：206. 反转链表
//  反转一个单链表。
//
//          输入: 1->2->3->4->5->NULL
//          输出: 5->4->3->2->1->NULL
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.h"

using namespace std;


/*Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };*/

//迭代版
ListNode* reverseList(ListNode* head) {
    ListNode *pre = NULL;
    ListNode *cur = head;
    while(cur != NULL){
        ListNode *next = cur->next;

        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

//递归版
ListNode* reverseList_1(ListNode* head) {
    if( head == NULL || head->next == NULL)
        return head;

     ListNode* p = reverseList_1(head -> next);

     head->next->next = head;
     head->next = NULL;

     return p;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = creatLinkedList(arr, n);
    printLinkedList(head);

    ListNode* head2 = reverseList_1(head);
    printLinkedList(head2);

    return 0;
}
