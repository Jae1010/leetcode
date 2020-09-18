//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 349. 两个数组的交集
// 题目：给定两个数组，编写一个函数来计算它们的交集。
//
//
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record(nums1.begin(), nums1.end());
        set<int> resultSet;
        for(vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it){
            if( record.find(*it) != record.end())
                resultSet.insert(*it);
        }
        return {resultSet.begin(), resultSet.end()}; // C++ 新标准 函数返回值列表初始化
    }

int main()
{
    vector<int> ivec = {1,2,2,1};
    vector<int> ivec1 = {2,2};
    vector<int> ivec2 = intersection(ivec, ivec1);
    for( auto i : ivec2)
        cout << i << " ";
    cout << endl;
    return 0;
}
