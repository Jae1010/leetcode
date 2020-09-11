//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================

// 75. ��ɫ����
// ��Ŀ������һ��������ɫ����ɫ����ɫ��һ�� n ��Ԫ�ص����飬ԭ�ض����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����
//ɫ����ɫ˳�����С�  �����У�����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(k)
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

//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)

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
