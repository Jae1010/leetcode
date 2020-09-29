//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 219. 存在重复元素 II
// 题目：给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使
// 得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//力扣最后一个用例超时
bool containsNearbyDuplicate_1(vector<int>& nums, int k) {
    int left = 0, right = 0;
    unordered_map<int, int> record;
    while( right < nums.size()){
        record[right] = nums[right];
        for(int i = left; i < right; ++i){
            if(record[right] == nums[i])
                return true;
        }
        right++;
        while(right - left > k){
            left++;
        }

    }
    return false;
}

//滑动窗口，这个窗口由哈希表set维护
bool containsNearbyDuplicate_2(vector<int>& nums, int k) {
    unordered_set<int> record;
    for(int i = 0 ; i < nums.size(); ++i){
        if(record.find(nums[i]) != record.end())
            return true;
        record.insert({nums[i], 1});
        if(record.size() == k+1)
            record.erase(nums[i-k]);
    }
    return false;
}

int main()
{
    vector<int> ivec = {1,2,3,1,2,3};
    bool a = containsNearbyDuplicate_3(ivec, 2);
    cout << a;
    return 0;
}
