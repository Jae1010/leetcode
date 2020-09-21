//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 290. 单词规律
// 题目：给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存
// 在着双向连接的对应规律。
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> record;
    vector<string> svec;
    string str1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ')
            str1 += s[i];
        else{
            svec.push_back(str1);
            str1 = "";
        }
    }
    svec.push_back(str1);
    if(pattern.size() != svec.size())
        return false;
    for(int i = 0; i < pattern.size(); i++){
        if(record.count(pattern[i]))
            if(record[pattern[i]] != svec[i])
                return false;
        record[pattern[i]] = svec[i];
    }
    // 反向验证
    unordered_map<string, char>  record2;
    for(int i = 0; i < pattern.size(); i++){
        if(record2.count(svec[i]))
        if(record2[svec[i]] != pattern[i])
            return false;
        record2[svec[i]] = pattern[i];
    }
    return true;
}

int main()
{
    string pattern = "abba";
    string str = "dog cat cat dog";
    bool a = wordPattern(pattern, str);
    cout << a << endl;
    return 0;
}
