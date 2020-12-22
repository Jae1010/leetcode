//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��86. �ָ�����
// ����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
//    ��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.h"

using namespace std;

class Solution {
public:

    //�����ڱ��ڵ�
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

    //˫��ָ�룬���贴���ڱ��ڵ�
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

    //���򴴽��ڱ��ڵ㣬����ж�
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
