//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 92. ��ת���� II
// ��Ŀ����ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��
// ˵��:
//1 �� m �� n �� �����ȡ�
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

//���һ���ڱ�
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
