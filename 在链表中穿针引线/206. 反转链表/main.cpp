//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��206. ��ת����
//  ��תһ��������
//
//          ����: 1->2->3->4->5->NULL
//          ���: 5->4->3->2->1->NULL
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

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = creatLinkedList(arr, n);
    printLinkedList(head);

    ListNode* head2 = reverseList(head);
    printLinkedList(head2);

    return 0;
}
