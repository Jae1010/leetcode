//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 205. 同构字符串
// 题目：给定两个字符串 s 和 t，判断它们是否是同构的。如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
// 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射
// 上，但字符可以映射自己本身。
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 不能case100%
bool isIsomorphic1(string s, string t) {
    unordered_map<char, int> sRecord;
    unordered_map<char, int> tRecord;
    if(s.size() != t.size())
        return false;
    for(int i = 0; i < s.size(); i++){
        sRecord[s[i]]++;
        tRecord[t[i]]++;
        if(sRecord.size() != tRecord.size()||sRecord[s[i]] != tRecord[t[i]])
            return false;
    }
    return true;
}
//双哈希表映射
bool isIsomorphic(string s, string t) {
    if(s.size() != t.size())
        return false;
    unordered_map<char, char> s_to_t;
    for(int i = 0; i < s.size(); i++){
        if(s_to_t.count(s[i]))
            if(s_to_t[s[i]] != t[i])
                return false;
        s_to_t[s[i]] = t[i];
    }
    unordered_map<char, char> t_to_s;
    for(int i = 0; i < s.size(); i++){
        if(t_to_s.count(t[i]))
            if(t_to_s[t[i]] != s[i])
                return false;
        t_to_s[t[i]] = s[i];
    }
    return true;

}
//同步映射到第三方，比较是否相同
bool isIsomorphic2(string s, string t) {
    if(s.size() != t.size())
        return false;
    int sArr[256] = {0};
    int tArr[256] = {0};
    for( int i = 0; i < s.size(); i++){
        if(sArr[s[i]] != tArr[t[i]])
            return false;
        else
            if(sArr[s[i]] == 0){
                sArr[s[i]] = i+1;
                tArr[t[i]] = i+1;
            }
    }
    return true;

}


int main()
{
    string s = "aabb", t = "abba";
    bool a = isIsomorphic2(s, t);
    cout << a << endl;
    return 0;
}
