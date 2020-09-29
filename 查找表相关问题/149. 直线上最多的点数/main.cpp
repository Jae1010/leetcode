//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 149. ֱ�������ĵ���
// ��Ŀ������һ����άƽ�棬ƽ������ n ���㣬������ж��ٸ�����ͬһ��ֱ���ϡ�
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
                continue;     //ȥ�أ������ظ����¼��ֱ��������һ��
            }
            int g = gcd(x, y);//Ϊ�˱�֤׼ȷ�ԣ�������С����keyֵ
            x = x/g;          //���Է��ӷ�ĸͬʱ�������Լ��
            y = y/g;          //Ȼ�󽫷���ĸ�ַ�����ʽ����Ϊkeyֵ
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
