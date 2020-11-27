//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：435. 无重叠区间
// 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
//注意:  1.可以认为区间的终点总是大于它的起点。2.区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[1] < b[1];});

        int res = 0;
        int tmp = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if( intervals[i][0] < tmp)
                res++;
            else
                tmp = intervals[i][1];
        }
        return res;
    }
};


int main()
{
    vector<vector<int>> ivec = {{1,2}, {1,3}, {2,4}};
    int res = Solution().eraseOverlapIntervals(ivec);
    cout << res << endl;
    return 0;
}
