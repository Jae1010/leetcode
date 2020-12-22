//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：328. 奇偶链表
// 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
//请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL)
            return head;
        ListNode *jishu = head;
        ListNode *jishu_head = head;
        ListNode *oushu = head->next;
        ListNode *oushu_head = head->next;

        while(jishu->next != NULL && oushu->next != NULL){
            jishu->next = oushu->next;
            jishu = jishu->next;

            oushu->next = jishu->next;
            oushu = oushu->next;
        }

        jishu->next = oushu_head;

        return jishu_head;
    }
};

int main()
{
    int arr[] = {1,2,3,4,5,6};

    ListNode *head = creatLinkedList(arr, sizeof(arr)/sizeof(int));
    printLinkedList(head);

    ListNode *res = Solution().oddEvenList(head);
    printLinkedList(res);

    ListNode *res1 = Solution().oddEvenList(res);
    printLinkedList(res1);
    return 0;
}
