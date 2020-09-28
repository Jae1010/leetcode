//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 447. �����ڵ�����
// ��Ŀ������ƽ���� n �Բ�ͬ�ĵ㣬�������ڡ� ���ɵ��ʾ��Ԫ�� (i, j, k) ����
// �� i �� j ֮��ľ���� i �� k ֮��ľ�����ȣ���Ҫ����Ԫ���˳�򣩡�
//�ҵ����л����ڵ�����������Լ��� n ���Ϊ 500�����е�������ڱ����� [-10000,
// 10000] �С�
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
