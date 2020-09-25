//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 16. ��ӽ�������֮��
// ��Ŀ������һ������ n ������������ nums �� һ��Ŀ��ֵ target���ҳ� nums �е�����
//  ������ʹ�����ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψ
//  һ�𰸡�
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


//˫ָ�뷨
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res1 = 1e7;
    int res2 = -1e7;
    if(nums.size() < 3)
        return 0;
    for (int i = 0; i < nums.size()-2; ++i){
        if(i > 0&& nums[i] == nums[i-1])
            continue;
        int left = i+1;
        int right = nums.size() - 1;
        while(left <right){
            if(nums[i] + nums[left] + nums[right] == target)
                return target;
            else if(nums[i] + nums[left] + nums[right] > target){
                res1 = min(nums[i] + nums[left] + nums[right], res1);
                --right;}
            else{
                res2 = max(nums[i] + nums[left] + nums[right], res2);
                ++left;}
        }

    }
        if(abs(res1 - target) > abs(res2 - target))
            return res2;
        else
            return res1;


}


int main()
{
    vector<int> ivec = {0,2,1,-3};
    int a = threeSumClosest(ivec, 1);
    printf("%d\n", a);
    return 0;
}
