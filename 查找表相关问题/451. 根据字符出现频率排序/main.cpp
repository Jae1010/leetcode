//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 451. 根据字符出现频率排序
// 题目：给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
//
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string frequencySort(string s) {
    int arr[256] = {0};
    for(int i = 0; i < s.size(); ++i){
        ++arr[s[i]] ;
    }
    char c;
    string  str;
    for(int i = 0; i < s.size(); ++i){
        c = max_element(arr, arr + 256) - arr;
        while(arr[c]){
            str += c;
            -- arr[c];
        }
    }
    return str;
}

int main()
{
    string str = "tree";
    string st = frequencySort(str);
    cout << st << endl;
    return 0;
}
