//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 49. 字母异位词分组
// 题目：给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不
//  同的字符串。
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> record;
    for(const string& s: strs){
        string t = s;
        sort(t.begin(), t.end());
        record[t].push_back(s);
    }
    for(auto &i : record)
        res.push_back(i.second);
    return res;
}



vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    int sub=0;  //结果vector的下标值
    string tmp; //临时string
    unordered_map<string,int> work; //判断排序后单词是否存在，即字母组成是否一致
    for(auto str:strs)
    {
        tmp=str;
        sort(tmp.begin(),tmp.end());
        if(work.count(tmp))
        {
            res[work[tmp]].push_back(str);
        }
        else
        {
            vector<string> vec(1,str);
            res.push_back(vec);
            work[tmp]=sub++;
        }
    }
    return res;
}


int main()
{
    vector<string> ivec = { "eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> str = groupAnagrams(ivec);
    for(auto &i : str){
        for(auto &j : i)
            cout<<j<<" ";
        cout << endl;}
    return 0;
}
