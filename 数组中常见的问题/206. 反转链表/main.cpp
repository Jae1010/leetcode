//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================

// 206. ��ת����
// ��Ŀ����תһ��������        ʾ��������: 1->2->3->4->5->NULL
//                                   ���: 5->4->3->2->1->NULL
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//������ ˫ָ��

    ListNode* reverseList(ListNode* head) {
        ListNode* p0 = nullptr;
        ListNode* p1 = head;
        while(p1){
            ListNode * temp = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = temp;
        }
        return p0;
    }

//�ݹ��

ListNode* reverseList1(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode * p = reverseList1(head->next);
    head->next->next = head; //head����һ���ڵ��nextָ��head�����ڵ�֮��㷴��
    head->next = nullptr; //��ʱhead��next�ڵ�Ӧָ��nullptr
    return p;
}

int main()
{
    return 0;
}
