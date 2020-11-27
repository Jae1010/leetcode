//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��435. ���ص�����
// ����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���
//ע��:  1.������Ϊ������յ����Ǵ���������㡣2.���� [1,2] �� [2,3] �ı߽��໥���Ӵ�������û���໥�ص���
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
