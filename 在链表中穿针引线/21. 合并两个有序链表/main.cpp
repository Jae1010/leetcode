//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��21. �ϲ�������������
//
//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.h"

using namespace std;

class Solution {
public:

    //������
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


    //�ݹ��
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
