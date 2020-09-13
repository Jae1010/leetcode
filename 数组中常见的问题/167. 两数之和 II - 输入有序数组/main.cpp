//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 167. 两数之和 II - 输入有序数组
// 题目：给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
// 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
//说明:
//返回的下标值（index1 和 index2）不是从零开始的。
//你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
//
#include <iostream>
#include <vector>

using namespace std;

//暴力解法
vector<int> twoSum1(vector<int>& numbers, int target) {
    vector<int> result;
    for(int i = 0; i < numbers.size()-1;i++)
        for(int j = i+1; j < numbers.size(); j++){
            if(numbers[i] + numbers[j] == target){
                result.push_back(++i);
                result.push_back(++j);
                return result;
            }

    }
    return result;
}

//双指针 时间复杂度O(n)， 空间复杂度O(1)， 对撞指针
vector<int> twoSum2(vector<int>& numbers, int target) {
    int i = 0;
     vector<int> result;
    if(numbers[i] > target)
        return result ;
    int j = numbers.size()-1;

    while( j > i){
        if(numbers[j] >= target){
            j--;
            continue;
        }
        if(numbers[i] + numbers[j] > target)
            j--;
        else if(numbers[i] + numbers[j] < target)
            i++;
        else{
            result.push_back(i+1);
            result.push_back(j+1);
            return result;
        }

    }
    return result;
}

int main()
{
    vector<int> ivec = { -1, 0};
    vector<int> vec = twoSum1(ivec, -1);
    for(auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}
