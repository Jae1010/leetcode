//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================

// 18. 四数之和
// 题目：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。 注意：答案中不可以包含重复的四元组。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//双指针
//和三数之和思路相同，由于需要确定四个数，所以需要4个指针,多一层循环

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if(nums.size()<4) return result;
        for(int i = 0; i < nums.size()-3; i++){
           // if((nums[i] + 3 * nums[nums.size()-1]) < target)
               // break;
            if(i > 0 && nums[i] == nums[i-1] )
                continue;
            for(int j = i+1; j < nums.size()-2; j++){
                //if(nums[i] + nums[j]+ 2*nums[j+1] > target)
                //    break;
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int left = j+1;
                int right = nums.size()-1;
                while(left < right){
                    if(nums[i] + nums[j] + nums[left] + nums[right] == target){
                        result.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if(nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                    else
                        left++;
                }
            }
        }
        return result;
    }

int main()
{
    vector<int> ivec1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> vec = fourSum(ivec1, 0);
    for(int i = 0; i< vec.size();i++){
        for(int j = 0; j < 4; j++)
            cout << vec[i][j]<<" ";
        cout<<endl;}
    return 0;
}
