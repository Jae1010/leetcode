//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 1. 两数之和
// 题目：给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的
// 那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//暴力循环 时间复杂度O(n2)
vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); ++i)
        for(int j = i+1; j < nums.size(); ++j)
            if(nums[i] + nums[j] == target)
                return {i, j};
    return {};
}
//哈希表 时间复杂度O(n)，空间复杂度O(n)
vector<int> twoSum1(vector<int>& nums, int target) {
    unordered_map<int, int> record;
    for(int i = 0;i < nums.size();++i)
        record.insert({nums[i], i});
    for(int i = 0;i < nums.size();++i){
        int otherNum = target - nums[i];
        if(record.count(otherNum) && record.at(otherNum) != i)
            return {i, record.at(otherNum)};
    }
    return {};
}

//哈希表 时间复杂度O(n)，空间复杂度O(n)
vector<int> twoSum2(vector<int>& nums, int target) {
    unordered_map<int, int> record;
    for(int i = 0;i < nums.size();++i){
        int otherNum = target - nums[i];
        if(record.count(otherNum))
            return {i, record.at(otherNum)};
        record.insert({nums[i], i});//最后插入元素
    }
    return {};
}

int main()
{
    vector<int> ivec = {1,2,3,4,5,10,12,};
    vector<int> vec = twoSum2(ivec, 9);
    for(const auto &i : vec)
        printf("%d ", i);
    return 0;
}
