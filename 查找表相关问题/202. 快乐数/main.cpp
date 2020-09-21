//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 202. ������
// ��Ŀ����дһ���㷨���ж�һ���� n �ǲ��ǿ�������
// ��������������Ϊ������һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���ͣ�Ȼ���ظ�
//�������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1����� ���Ա�Ϊ  1����ô��������ǿ�������
//��� n �ǿ������ͷ��� True �����ǣ��򷵻� False ��
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int getNext(int n){
    int sum = 0;
    while ( n > 0){
        int d = n % 10; //ʮ���Ƴ�ʮȡ��
        n = n/10;
        sum += d*d;
    }
    return sum;
}

// ת��ΪѰ�������Ƿ��л�������
bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    while( fast != 1 && fast != slow){
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast == 1;
}

int main()
{
    int n;
    while(cin >> n){
    bool a = isHappy(n);
    cout << (a ? "is a happy numer!" : "is not a happy numer!")<< endl;}
    return 0;
}
