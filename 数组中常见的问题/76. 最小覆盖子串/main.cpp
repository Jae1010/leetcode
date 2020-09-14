//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 76. 最小覆盖子串
// 题目：给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，
// 从字符串 S 里面找出：包含 T 所有字符的最小子串。
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//双指针，滑动窗口

string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for( char c : t) need[c]++;
    int right = 0, left = 0, valid = 0;
    int start = 0, len = s.size()+1;
    while(right < s.size()){
        char c = s[right++];
        if(need.count(c)){
            window[c] ++;
            if(window[c] == need[c])
                valid ++;
        }
        while( need.size() == valid){
            if (right - left < len) {
                start = left;
                len = right - left;
            }
            char d = s[left++];
            if(need.count(d)){
                if(window[d] == need[d])
                    valid--;
                window[d] --;
            }
        }

    }
    return len == s.size()+1 ? "" : s.substr(start, len);
}

int main()
{
    string s = "aa";
    string t = "aa";
    string s1 = "aaaaaaaaaaaabbbbbcdd";
    string t1 = "abcdd";
    string str = minWindow(s, t);
    string str1 = minWindow(s1, t1);
    cout << str <<endl;//期望输出aa
    cout << str1 << endl;//期望输出"abbbbbcdd"
    return 0;
}
