//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：83. 删除排序链表中的重复元素
//     给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
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
