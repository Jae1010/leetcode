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
#include <queue>
#include <string>

using namespace std;

//数组记录频率
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

//优先队列
string frequencySort1(string s) {
    unordered_map<char, int> record;
    for(const auto &i : s)
        ++record[i];
    priority_queue<pair<char, int>> pq;
    for(const auto &i : record)
        pq.push(make_pair(i.second, i.first));
    string res;
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        //while(t.first--)
        //res+=t.second;//res.push_back(t.second_;
        res.append(t.first, t.second);
    }
    return res;
}

int main()
{
    string str = "tree";
    string st = frequencySort1(str);
    cout << st << endl;
    return 0;
}
