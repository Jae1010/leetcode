//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================

// 142. 环形链表 II
// 题目：给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 -1，则在该链表中没有环。
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 //链表head到环入口设长为a，环长b
 //慢指针slow一次走一步，快指针fast一次走两步，f = 2s；
 //当二者第一次相遇，f = s +n*b，两式联立的f = 2nb，s = nb
 //节点从head走到环入口处一定是a+nb，因为走a步到入口，绕环n周必定回到入口
 //此时s走了nb步，那么只要s再走a步就会走到入口处，返回s指针就可以了
 //让f = head，fs同时以速度1前进，再次相遇必定在环入口，因为f走a步到入口，s同样

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
