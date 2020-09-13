//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 215. 数组中的第K个最大元素
// 题目：在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序
//      后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//需要手写排序算法

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
