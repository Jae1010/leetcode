//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 3. 无重复字符的最长子串
// 题目：给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//滑动窗口，双指针

int lengthOfLongestSubstring(string s) {
    int slow = 0, fast = -1, res =0;
    int freq[256] = {0};
    while(slow < s.size()){
        if(fast+1 < s.size() && freq[s[fast+1]] == 0) //窗口前进条件
            freq[s[++fast]] ++;
        else
            freq[s[slow++]] --;
        res = max(res, fast - slow + 1);
        }

    return res;
}
//另一种写法
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
