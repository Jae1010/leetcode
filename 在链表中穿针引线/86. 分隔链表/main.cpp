//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：86. 分隔链表
// 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//    你应当保留两个分区中每个节点的初始相对位置。
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.h"

using namespace std;

class Solution {
public:

    //创建哨兵节点
    ListNode* partition(ListNode* head, int x) {

        ListNode* nex = head;
        ListNode* before_head = new ListNode(0);
        ListNode* before = before_head;
        ListNode* after_head = new ListNode(0);
        ListNode* after = after_head;

        while(nex != NULL){
            if(nex->val < x){
                before->next = nex;
                before = before->next;
            }
            else{
                after->next = nex;
                after = after->next;
            }

            nex = nex->next;
        }

        after->next = NULL;

        before->next = after_head->next;

        return before_head->next;

    }

    //双层指针，无需创建哨兵节点
    ListNode* partition_1(ListNode* head, int x) {
        ListNode *new_head = nullptr, **new_p = &new_head;
        for (auto p = &head; (*p); ) {
            if ((*p)->val >= x) {
                p = &(*p)->next;
            } else {
                (*new_p) = (*p);
                new_p = &((*new_p)->next);
                (*p) = (*p)->next;
            }
        }
        (*new_p) = head;
        return new_head;
    }

    //无序创建哨兵节点，多个判断
    ListNode* partition(ListNode* head, int x) {

        ListNode* nex = head;
        ListNode* before_head = NULL;
        ListNode* before = before_head;
        ListNode* after_head = NULL;
        ListNode* after = after_head;

        while(nex != NULL){
            if(nex->val < x){
                if(before_head == NULL){
                    before_head = nex;
                    before = before_head;
                }
                else{
                    before->next = nex;
                    before = before->next;
                }
            }
            else{
                if(after_head == NULL){
                    after_head = nex;
                    after = after_head;
                }
                else{
                    after->next = nex;
                    after = after->next;
                }
            }

            nex = nex->next;
        }
        if(after_head != NULL){
            after->next = NULL;
        }
        if(before_head != NULL){
            before->next = after_head;
            return before_head;
        }
        return after_head;

    }
};

int main()
{
    int arr[] = {1,4,3,2,5,2};

    ListNode *head = creatLinkedList(arr, sizeof(arr)/sizeof(int));
    printLinkedList(head);

    ListNode *res = Solution().partition_2(head, 3);
    printLinkedList(res);

    return 0;
}
