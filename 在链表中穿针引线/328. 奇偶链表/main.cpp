//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��328. ��ż����
// ����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�
//�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������
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
