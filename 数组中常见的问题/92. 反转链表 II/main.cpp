//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 92. 反转链表 II
// 题目：反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
// 说明:
//1 ≤ m ≤ n ≤ 链表长度。
//
//
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//添加一个哨兵
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* start = new ListNode(-1);
    start->next = head;
    ListNode* pre = start;
    for( int i = 1; i < m; ++i)
        pre = pre->next;
    head = pre->next;
    for(int i = m; i < n; ++i){
        ListNode* nxt = head->next;
        head->next = nxt->next;
        nxt->next = pre->next;
        pre->next = nxt;
    }
    return start->next;
}

int main()
{
    vector<int> ivec = { };
    return 0;
}
