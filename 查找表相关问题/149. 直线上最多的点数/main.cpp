//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 149. 直线上最多的点数
// 题目：给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
//
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int m, int n){
    while( n!= 0){
        int temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

 int maxPoints(vector<vector<int>>& points) {
    if(points.size() < 3)
        return points.size();
    int res = 0;
    for(int i = 0; i < points.size(); ++i){
        int dup = 0;
        int m = 0;
        unordered_map<string, int> record;
        for(int j = i + 1; j < points.size(); ++j){
            int x = points[j][0] - points[i][0];
            int y = points[j][1] - points[i][1];
            if(x == 0&& y == 0){
                ++dup;
                continue;     //去重，遇到重复点记录并直接跳到下一点
            }
            int g = gcd(x, y);//为了保证准确性，不能用小数当key值
            x = x/g;          //所以分子分母同时除以最大公约数
            y = y/g;          //然后将分子母字符串形式保存为key值
            string xx = to_string(x);
            string yy = to_string(y);
            string key = xx + '/' + yy;
            ++record[key];
            m = max(m, record[key]);
        }
        res = max(res, m + dup + 1);
    }
    return res;
 }

int main()
{
    vector<vector<int>> ivec = {{1,1}, {3,2},{5,3} ,{4,1}, {2,3}, {1,4}};
    vector<vector<int>> ivec1 = {{1,1}, {2,2},{3,3}};
    vector<vector<int>> ivec2 = {{0,0},{0,0},{0,0}};
    int a = maxPoints(ivec2);
    cout << a;
    return 0;
}
