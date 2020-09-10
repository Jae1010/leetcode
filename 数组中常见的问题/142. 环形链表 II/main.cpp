//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================

// 142. �������� II
// ��Ŀ������һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
// Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
//��� pos �� -1�����ڸ�������û�л���
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 //����head��������賤Ϊa������b
 //��ָ��slowһ����һ������ָ��fastһ����������f = 2s��
 //�����ߵ�һ��������f = s +n*b����ʽ������f = 2nb��s = nb
 //�ڵ��head�ߵ�����ڴ�һ����a+nb����Ϊ��a������ڣ��ƻ�n�ܱض��ص����
 //��ʱs����nb������ôֻҪs����a���ͻ��ߵ���ڴ�������sָ��Ϳ�����
 //��f = head��fsͬʱ���ٶ�1ǰ�����ٴ������ض��ڻ���ڣ���Ϊf��a������ڣ�sͬ��

 ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                fast = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;

    }

int main()
{

    return 0;
}
