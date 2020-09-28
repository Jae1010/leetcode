//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 454. 四数相加 II
// 题目：给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使
// 得 A[i] + B[j] + C[k] + D[l] = 0。
//为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整
//整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> record;
    for(int i = 0; i < C.size(); ++i)
        for(int j = 0; j < D.size(); ++j){
            int sum = C[i] + D[j];
            ++ record[sum];
        }
    int res = 0;
    for(int i = 0; i < C.size(); ++i)
        for(int j = 0; j < D.size(); ++j){
            int otherNum = 0 - A[i] - B[j];
            if(record.find(otherNum) != record.end()){
                res += record[otherNum];
            }

        }
    return res;
}

int fourSumCount_1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> record_1;
    for(int i = 0; i < C.size(); ++i)
        for(int j = 0; j < D.size(); ++j){
            int sum = A[i] + B[j];
            ++ record_1[sum];
        }
    int res = 0;
    unordered_map<int, int> record_2;
    for(int i = 0; i < C.size(); ++i)
        for(int j = 0; j < D.size(); ++j){
            int sum = C[i] + D[j];
            ++ record_2[sum];
        }
    for(unordered_map<int,int>::iterator it = record_1.begin(); it != record_1.end();++it){
        if(record_2.count(-it->first))
            res = it->second + record_2[-(it->first)];
    }

    return res;
}


int main()
{
    vector<int> A = {1,2 }, B = {-2,-1 },C = {-1,2 },D = {0,2 };
    int a = fourSumCount_1(A,B,C,D);
    cout << a;
    return 0;
}
