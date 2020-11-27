//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：455. 分发饼干
//假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
//对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸
//s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多
//数量的孩子，并输出这个最大数值。
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int gi = 0, si = 0;
        int res = 0;
        while(gi < g.size() && si <s.size()){
            if(g[gi] <= s[si]){
                res++;
                gi++;
                si++;
            }
            else
                gi++;
        }
        return res;
    }

    int findContentChildren_2(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0, si = 0;
        while(gi < g.size() && si <s.size()){
            if(g[gi] <= s[si])
                gi++;
            si++;
        }
        return gi;
    }
};

int main()
{
    vector<int> g = {1,2,3};
    vector<int> s = {2,3,4};
    int res = Solution().findContentChildren_2(g, s);
    cout << res << endl;
    return 0;
}
