//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 209. 长度最小的子数组
// 题目：给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的
// 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
//
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//错误解法
int minSubArrayLen1(int s, vector<int>& nums) {
    int slow = -1, fast = 0, sum = 0, size = nums.size(); //slow,fast设置有问题，(-1,0)->(0,0)？
    while(slow < fast){//slow和fast可以重合
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

//双指针 滑动窗口 时间复杂度O(n),空间复杂度O(1)
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
