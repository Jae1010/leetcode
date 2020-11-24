//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��83. ɾ�����������е��ظ�Ԫ��
//     ����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {

    ListNode* curHead = head;

    while(curHead != NULL){
        ListNode* nex = curHead->next;
        if(nex != NULL && curHead -> val == nex -> val){
            curHead->next = nex->next;
            nex->next = NULL;
        }
        else
            curHead = curHead->next;
        }

    return head;
}

int main()
{
    int arr[] = {1,1,1,1,2,2,3,3,4,4,4,4,4,4};
    int n = sizeof(arr)/sizeof(int);
    ListNode* head = creatLinkedList(arr, n);
    printLinkedList(head);

    ListNode* head2 = deleteDuplicates(head);
    printLinkedList(head2);


    return 0;
}
