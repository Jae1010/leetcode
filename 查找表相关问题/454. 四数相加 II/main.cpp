//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 454. ������� II
// ��Ŀ�������ĸ����������������б� A , B , C , D ,�����ж��ٸ�Ԫ�� (i, j, k, l) ��ʹ
// �� A[i] + B[j] + C[k] + D[l] = 0��
//Ϊ��ʹ����򵥻������е� A, B, C, D ������ͬ�ĳ��� N���� 0 �� N �� 500 ��������
//�����ķ�Χ�� -228 �� 228 - 1 ֮�䣬���ս�����ᳬ�� 231 - 1 ��
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
