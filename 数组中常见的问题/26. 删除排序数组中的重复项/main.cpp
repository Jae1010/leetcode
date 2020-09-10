//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================

// 26：删除排序数组中的重复项
// 题目：给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。 
#include <iostream>
#include <vector>

using namespace std;

//双指针

int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int slowindex = 0;
        for(int fastindex = 0; fastindex < nums.size()-1; fastindex++)
            if( nums[fastindex] != nums[fastindex+1])
                nums[++slowindex] = nums[fastindex+1];
        return slowindex+1;
}


int main()
{
    vector<int> ivec = {1, 1, 2, 2};
    int slow = removeDuplicates(ivec);
    for(int i = 0; i < slow; i++)
        cout << ivec[i] << " ";
    cout << endl;
    vector<int> ivec1 = {1, 1, 2, 2,2,2,2,2,2,3,4,4};
    int slow1 = removeDuplicates(ivec1);
    for(int i = 0; i < slow1; i++)
        cout << ivec1[i] << " ";
    return 0;
}
