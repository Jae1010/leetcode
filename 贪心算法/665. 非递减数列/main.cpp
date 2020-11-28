//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：665. 非递减数列
//
//给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

//我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。

//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
首先判断是否存在逆序（题目要求非递减），

如果存在逆序，判断当前数nums[i]与nums[i-2]的大小，

如果nums[i]<nums[i-2]，类似3,4,2，需要2变成4，nums[i] = nums[i - 1]，3，4，4；

如果nums[i]>nums[i-2]，类似1,4,2，需要4变成2，nums[i - 1] = nums[i]，1，2，2；

在此基础上继续循环判断后续是否存在逆序
*/


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        int n = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] > nums[i]){
                n++;
                if(n == 2)
                    break;
                if(i >= 2 && nums[i - 2] > nums[i])
                    nums[i] = nums[i - 1];
                else
                    nums[i - 1] = nums[i];
            }
        }

        return n <= 1;
    }
};

int main()
{
    vector<int> vec = {1,2,3};
    bool n = Solution().checkPossibility(vec);
    cout << n << endl;
    return 0;
}
