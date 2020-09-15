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
#include <unordered_map>

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
//��һ��д��
int lengthOfLongestSubstring1(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0, res = 0;

    while(right < s.size()){
        char c = s[right++];
        window[c]++;
        while(window[c] != 1)
            window[s[left++]] --;
        res = max(res, right - left);
    }
    return res;
}


int main()
{
    string s = "abcabcbb";
    int a = lengthOfLongestSubstring1(s);
    cout << a << endl;
    return 0;
}
