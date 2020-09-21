//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 88. �ϲ�������������
// ��Ŀ���������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ nums1 ��Ϊһ���������顣
//
//
#include <iostream>
#include <vector>

using namespace std;

//O(n)ʱ�临�Ӷ� O(n+m) �ռ临�Ӷ�O(m)
void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    vector<int> vec;
    for(int i = 0; i < m; i++)
        vec.push_back(nums1[i]);
    nums1.clear();
    int p0 = 0, p1 = 0;
    while( p0 < m && p1 < n){
        if(vec[p0] <= nums2[p1])
            nums1.push_back(vec[p0++]);
        else
            nums1.push_back(nums2[p1++]);
    }
    if( p0 < m)
        for( int i = p0; i < m; i++)
            nums1.push_back(vec[i]);
    if(p1 < n)
        for( int i = p1; i < n; i++)
            nums1.push_back(nums2[i]);
}

////O(n)ʱ�临�Ӷ� O(n+m) �ռ临�Ӷ�O(1)

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m-1, p2 = n-1;
    int cur = m + n -1;
    while( p1 >= 0 && p2 >= 0 ){
        if(nums1[p1] > nums1[p2])
            nums1[cur--] = nums1[p1--];
        else
            nums1[cur--] = nums2[p2--];
    }
    if(p1 < 0)
        while(p2>=0)
            nums1[cur--] = nums2[p2--];

}

//��merge2һ����д����ͬ
void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = n + m - 1;
    m--;
    n--;
    while (n >= 0) {
        while (m >= 0 && nums1[m] > nums2[n]) {
            nums1[i--] = nums1[m--];
        }
        nums1[i--] = nums2[n--];
    }
}
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;
        m--;
        n--;
        while( n >= 0){
            while(m >= 0){
                if(nums1[m] > nums2[n])
                    nums1[i--] = nums1[m--];
                else
                    nums1[i--] = nums2[n--];
            }
            nums1[i--] = nums2[n--];
        }
    }


int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
    for(auto i : nums1)
        cout << i << " ";
    cout << endl;
    return 0;
}
