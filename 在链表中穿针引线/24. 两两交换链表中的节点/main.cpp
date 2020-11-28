//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��24. �������������еĽڵ�
//
//����һ���������������������ڵĽڵ㣬�����ؽ����������
//
//�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
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
