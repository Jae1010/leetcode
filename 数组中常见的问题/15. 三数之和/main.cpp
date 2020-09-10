//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================

// 15. 三数之和
// 题目：给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件
// 不重复的三元组。   注意：答案中不可以包含重复的三元组。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//双指针
//由于确定3个数，需要3个指针

    vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            if(nums.size()<3) return result; //提前判断是否满足条件，以免浪费时间
            sort(nums.begin(), nums.end());  //题目没说是否排序，提前排序
            for(int i =0; i < nums.size();i++){
                if(nums[i] > 0)
                    return result;   //三数之和为0，如果第一个数大于0，必不可能和为0
                if(i > 0 && nums[i] == nums[i-1] ) //去重，如果第一个数连续相同，可能会出现重复结果
                    continue;
                int left = i+1;
                int right = nums.size()-1;
                while(left < right){
                    if(nums[i] + nums[left] + nums[right] == 0){
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        while(left < right && nums[right] == nums[right-1]) right--; //去重，和上边同理
                        while(left < right && nums[left] == nums[left+1]) left++;
                        right--;
                        left++;
                    }
                    else if(nums[i] + nums[left] + nums[right] > 0)
                        right--;
                    else
                        left++;
                }
            }
            return result;

    }

int main()
{
    vector<int> ivec1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> slow1 = threeSum(ivec1);
    for(int i = 0; i< slow1.size();i++){
        for(int j = 0; j < 3; j++)
            cout << slow1[i][j]<<" ";
        cout<<endl;}
    return 0;
}
