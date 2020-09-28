//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 191. λ1�ĸ���
// ��Ŀ����дһ��������������һ���޷�������������������Ʊ��ʽ������λ��Ϊ ��1�� �ĸ�
//      ����Ҳ����Ϊ������������
//
//
#include <iostream>
#include <vector>

using namespace std;
//ʱ�临�Ӷ�O(logn)
int hammingWeight_1(uint32_t n) {
    int ones = 0;
    while(n > 0){
        ones += ( n & 1);
        n >>= 1;
    }
    return ones;
}

//���㷨ִ��ʱ��������n��1�ĸ���  ʱ�临�Ӷ�O(logn)
int hammingWeight_2(uint32_t n) {
    int ones = 0;
    while(n > 0){
        ones ++;
        n &= n-1; //���λ1����ͱ���Ϊ0,
    }
    return ones;
}

int main()
{
    vector<int> ivec = { };

    int a = hammingWeight_2(441);
    cout << a;
    return 0;
}
