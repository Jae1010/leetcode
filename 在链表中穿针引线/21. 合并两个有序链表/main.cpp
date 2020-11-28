//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：21. 合并两个有序链表
//
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.h"

using namespace std;

class Solution {
public:

    //迭代版
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode(-1), *res = start;

        while(l1 && l2){
            if(l1->val <= l2->val){
                start->next = l1;
                l1 = l1->next;
            }
            else{
                start->next = l2;
                l2 = l2->next;
            }
            start = start->next;
        }
        start->next = (l1 ? l1 : l2);

        return res->next;
    }


    //递归版
    ListNode* mergeTwoLists_1(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        else if( l1->val < l2->val){
            l1->next = mergeTwoLists_1(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists_1(l1, l2->next);
            return l2;
        }
    }

};

int main()
{

    return 0;
}
