//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 3. ���ظ��ַ�����Ӵ�
// ��Ŀ������һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
//
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�������ڣ�˫ָ��

int lengthOfLongestSubstring(string s) {
    int slow = 0, fast = -1, res =0;
    int freq[256] = {0};
    while(slow < s.size()){
        if(fast+1 < s.size() && freq[s[fast+1]] == 0) //����ǰ������
            freq[s[++fast]] ++;
        else
            freq[s[slow++]] --;
        res = max(res, fast - slow + 1);
        }

    return res;
}


int main()
{
    string s = "abcabcbb";
    int a = lengthOfLongestSubstring(s);
    cout << a << endl;
    return 0;
}
