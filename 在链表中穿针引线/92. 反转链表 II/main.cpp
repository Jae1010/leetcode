//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��92. ��ת���� II
// ��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��
//      ˵����1 �� m �� n �� �����ȡ�
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

 ListNode* reverseBetween(ListNode* head, int m, int n) {

    ListNode *start = new ListNode (-1);
    start->next = head;

    ListNode *pre = start;
    for(int i = 1; i < m; i++){
        pre = pre->next;
    }

    ListNode *cur = pre->next;
    int i = n - m;
    while(i--){       //for(int i = m; i < n; i++)
        ListNode *nex = cur->next;
        cur->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;
    }
    return start->next;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int m = 2, n = 4;

    ListNode* head = creatLinkedList(arr, 5);
    printLinkedList(head);

    ListNode* head2 = reverseBetween(head, m, n);
    printLinkedList(head2);

    return 0;
}
