//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 215. �����еĵ�K�����Ԫ��
// ��Ŀ����δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ�����������
//      ��ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��Ҫ��д�����㷨

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int main()
{
    vector<int> ivec = { 3,2,1,5,6,4};
    int a = findKthLargest(ivec,2);
    cout << a <<endl;
    return 0;
}
