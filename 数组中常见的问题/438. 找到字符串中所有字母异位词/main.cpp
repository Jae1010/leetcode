//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 438. 找到字符串中所有字母异位词
// 题目：给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
//说明：字母异位词指字母相同，但排列不同的字符串。
//      不考虑答案输出的顺序。
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//双指针  滑动窗口 时间复杂度O(n)，空间复杂度O(1)
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, window;
    for( char c : p)
        need[c]++;
    vector<int> result;

    int right = 0, left = 0;
    int valid = 0;
    while(right < s.size()){
        char c = s[right++];
        if(need.count(c)){
            window[c] ++;
            if(window[c] == need[c])
                valid ++;
        }
        while(right - left >= p.size()){
            if( valid == need.size())
                result.push_back(left);
            char d = s[left++];
            if(need.count(d)){
                if(window[d] == need[d])
                    valid--;
                window[d] --;
            }
        }
    }
    return result;
}

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);
    for(auto i : result)
        cout << i << " ";
    return 0;
}
