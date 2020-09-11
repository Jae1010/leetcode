//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================

// 75. 颜色分类
// 题目：给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白
//色、蓝色顺序排列。  此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


//时间复杂度O(n),空间复杂度O(k)
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for( int i = 0; i < nums.size(); i++){
            assert( nums[i] >=0 && nums[i] <= 2);
            count[nums[i]]++;
        }

        int index = 0;
        for(int i = 0; i < 3; i++)
            while(count[i]--)
                nums[index++] = i;
    }

//时间复杂度O(n)，空间复杂度O(1)

void sortColors1(vector<int>& nums) {
        int p0 = 0, cur = 0, p2 = nums.size()-1;
        /*for(int cur = 0; cur <= p2;){
            if(nums[cur] == 0)
                swap(nums[p0++],nums[cur++]);
            else if(nums[cur] == 2)
                swap(nums[p2--],nums[cur]);
            else
                cur++*/
        while(cur <= p2){
            if(nums[cur] == 0)
                swap(nums[p0++],nums[cur++]);
            else if(nums[cur] == 2)
                swap(nums[p2--],nums[cur]);
            else
                cur++;
        }
    }


int main()
{
    vector<int> ivec = {2,0,2,1,1,0};
    sortColors(ivec);
    for(int i = 0; i < ivec.size(); i++)
        cout << ivec[i] << " ";

    return 0;
}
