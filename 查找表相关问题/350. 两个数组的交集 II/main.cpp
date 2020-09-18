//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 350. ��������Ľ��� II
// ��Ŀ�������������飬��дһ���������������ǵĽ�����
//
//
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //if (nums1.size() > nums2.size())
   //         return intersect(nums2, nums1);
    map<int,int> record;
    for ( int i = 0; i < nums1.size(); i++){
        record[nums1[i]] ++;
    }
    vector<int> result;
    for(int i = 0; i < nums2.size(); i ++){
        if( record[nums2[i]] > 0){
            result.push_back(nums2[i]);
            record[nums2[i]] --;
        }
    }
    /*for( auto i : nums2){
        if(record[i] > 0){
            result.push_back(i);
            record[i] --;
        }
    }*/
    return result;
}

int main()
{
    vector<int> ivec1 = { 1,2,2,2,2,2,1};
    vector<int> ivec2 = {2,2};
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> ivec3 = intersect(ivec2,ivec1);
    vector<int> ivec4 = intersect(nums2, nums1);
    for( auto i : ivec3)
        cout << i << " ";
    cout << endl;
     for( auto i : ivec4)
        cout << i << " ";
    cout << endl;
    return 0;
}
