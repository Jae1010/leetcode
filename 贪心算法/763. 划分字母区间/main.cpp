//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：763. 划分字母区间
// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
//返回一个表示每个字符串片段的长度的列表。
//
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char, int> m;
        for(int i = 0; i < S.size(); i++){
            m[S[i]] = i;
        }

        int be = 0, la = 0;
        for(int i = 0; i < S.size(); i++){
            la = max(la, m[S[i]]);
            if( i == la){
                res.push_back(la - be + 1);
                be = i + 1;
            }
        }
        return res;
    }
};

int main()
{
    string S = "ababcbacadefegdehijhklij";
    vector<int> res = Solution().partitionLabels(S);
    for(auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
