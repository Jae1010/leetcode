//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 1. ����֮��
// ��Ŀ������һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ��
// �� ���� ���������������ǵ������±ꡣ
// ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����ѭ�� ʱ�临�Ӷ�O(n2)
vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); ++i)
        for(int j = i+1; j < nums.size(); ++j)
            if(nums[i] + nums[j] == target)
                return {i, j};
    return {};
}


int main()
{
    vector<int> ivec = {1,2,3,4,5,10,12,};
    vector<int> vec = twoSum(ivec, 9);
    for(const auto &i : vec)
        printf("%d ", i);
    return 0;
}
