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
    //int res2 = -1e7;
    if(nums.size() < 3)
        return 0;
    auto update = [&](int cur){
        if(abs(cur - target) < abs(res1 - target))
            res1 = cur;
    };
    for (int i = 0; i < nums.size()-2; ++i){
        if(i > 0&& nums[i] == nums[i-1])
            continue;
        int left = i+1;
        int right = nums.size() - 1;
        while(left <right){
            int sum = nums[i] + nums[left] + nums[right];
            update(sum);
            if(sum == target)
                return target;
            else if(sum > target){
                //res1 = min(nums[i] + nums[left] + nums[right], res1);
                --right;
               // while(left < right&&nums[right] == nums[right-1])
                   // --right;
                }
            else{
                //res2 = max(nums[i] + nums[left] + nums[right], res2);
                ++left;
               // while(left < right&&nums[left] == nums[left+1])
                   // ++left;
                    }
        }

    }
        /*if(abs(res1 - target) > abs(res2 - target))
            return res2;
        else*/
            return res1;


}


int main()
{
    vector<int> ivec = {3,4,5,5,7};
    int a = threeSumClosest(ivec, 13);
    printf("%d\n", a);
    return 0;
}
