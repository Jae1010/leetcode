//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：24. 两两交换链表中的节点
//
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.h"

using namespace std;



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head, *tmp;
        if( p && p->next){
            tmp = p->next;
            p->next = tmp->next;
            tmp->next = p;
            head = tmp;
            while(p->next && p->next->next){
                tmp = p->next->next;
                p->next->next = tmp->next;
                tmp->next = p->next;
                p->next = tmp;
                p = tmp->next;
            }
        }
        return head;
    }
};

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    ListNode* head = creatLinkedList(arr, n);
    printLinkedList(head);

    ListNode* head2 = Solution().swapPairs(head);
    printLinkedList(head2);
    return 0;
}
