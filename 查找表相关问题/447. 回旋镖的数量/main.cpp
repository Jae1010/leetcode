//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 447. 回旋镖的数量
// 题目：给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其
// 中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
//找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000,
// 10000] 中。
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int dis(vector<int> m, vector<int> n){
    int sum = (m[0] - n[0])*(m[0] - n[0])+(m[1] - n[1])*(m[1] - n[1]);
    return sum;
}

int numberOfBoomerangs(vector<vector<int>>& points) {
    int res = 0;
    for(int i = 0; i < points.size(); ++i){
        unordered_map<int, int> record;
        for(int j = 0; j < points.size(); ++j){
            if(i != j){
                ++record[dis(points[i], points[j])];
            }
        }
        for(auto &i :record)
        res += (i.second)*(i.second-1);
    }
    return res;
}

int main()
{
    vector<vector<int>> ivec = {{0,0}, {1,0}, {2,0} };
    int a = numberOfBoomerangs(ivec);
    cout << a;
    return 0;
}
