//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 567. 字符串的排列
// 题目：给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
// 换句话说，第一个字符串的排列之一是第二个字符串的子串。
//
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//滑动窗口 时间复杂度O(n),空间复杂度O(1)

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;
    for(char i : s1) need[i] ++;

    int left = 0, right = 0, valid = 0;
    bool res = false;
    while(right < s2.size()){
        char c = s2[right++];
        if(need.count(c)){
            window[c] ++;
            if(window[c] == need[c])
                valid ++;
        }
        while(right - left >= s1.size()){//不能是right - left >= need.size(),
            if(valid == need.size())      //因为s1可能有重复字母，need.size()<=s1.size()
                return true;
            char d = s2[left++];
            if(need.count(d)){
                if(need[d] == window[d])
                    valid--;
                window[d] --;
            }
        }
    }
    return res;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool a = checkInclusion(s1 ,s2);
    cout << a << endl;
    return 0;
}
