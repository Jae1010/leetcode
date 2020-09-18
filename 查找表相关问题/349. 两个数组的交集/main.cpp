//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 349. ��������Ľ���
// ��Ŀ�������������飬��дһ���������������ǵĽ�����
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
        return {resultSet.begin(), resultSet.end()}; // C++ �±�׼ ��������ֵ�б��ʼ��
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
