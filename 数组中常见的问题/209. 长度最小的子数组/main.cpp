//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 209. ������С��������
// ��Ŀ������һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ�����С��
// ���� �����飬�������䳤�ȡ���������ڷ��������������飬���� 0��
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����ⷨ
int minSubArrayLen1(int s, vector<int>& nums) {
    int slow = -1, fast = 0, sum = 0, size = nums.size(); //slow,fast���������⣬(-1,0)->(0,0)��
    while(slow < fast){//slow��fast�����غ�
         if(fast < nums.size())
            sum += nums[fast];
        if(sum >= s){
            if(size > fast - slow )//
                size = fast - slow ;
            while(sum > s)
                sum -= nums[++slow];
        }
        fast++;
    }
    return size;
}

//˫ָ�� �������� ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
int minSubArrayLen(int s, vector<int>& nums) {
    int slow = 0, fast = -1, res = nums.size()+1, sum = 0;
    while(slow < nums.size()){//fast = -1,fast+1<nums.size(),++fast
        if(fast+1<nums.size() && sum < s)
            sum += nums[++fast];
        else
            sum -= nums[slow++];
        if(sum>=s)
            res = min(res, fast - slow + 1);
    }
    if(res == nums.size()+1)
        return 0;
    return res;
}

int main()
{
    vector<int> ivec = { 2,3,1,2,4,3};
    int a = minSubArrayLen(7, ivec);
    cout << a<<endl;
    return 0;
}
