//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 76. ��С�����Ӵ�
// ��Ŀ������һ���ַ��� S��һ���ַ��� T ���������һ���㷨�������� O(n) ��ʱ�临�Ӷ��ڣ�
// ���ַ��� S �����ҳ������� T �����ַ�����С�Ӵ���
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//˫ָ�룬��������

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
    cout << str <<endl;//�������aa
    cout << str1 << endl;//�������"abbbbbcdd"
    return 0;
}
