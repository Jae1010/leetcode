//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================

// 80. 删除排序数组中的重复项 II
// 题目：给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
#include <iostream>
#include <vector>

using namespace std;

//这个解法可以推广到保留n个相同元素

int removeDuplicates(vector<int>& nums) {
    int slowIndex = 0;
    for( int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        if( slowIndex < 2 || nums[fastIndex] != nums[slowIndex-2] )
            if(slowIndex == fastIndex)  //如果快慢指针相同，慢指针可直接前进，不用复制，耗费时间
                slowIndex++;
            else
                nums[slowIndex++] = nums[fastIndex];
    return slowIndex;
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

    return 0;
}
