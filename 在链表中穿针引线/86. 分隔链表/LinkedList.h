#ifndef __LINKEFLIST_H__
#define __LINKEFLIST_H__

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* creatLinkedList(int arr[], int n){

    if(n == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);

    ListNode* curHead = head;
    for(int i = 1; i < n; i++){
        curHead->next = new ListNode(arr[i]);
        curHead = curHead->next;
    }

    return head;
 }

void printLinkedList(ListNode *head){

    ListNode* curHead = head;

    while(curHead != NULL){
        cout << curHead->val <<" -> ";
        curHead = curHead->next;
    }
    cout << "NULL"<< endl;

    return;
}


#endif // __LINKEFLIST_H__
