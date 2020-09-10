//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================

// 15. ����֮��
// ��Ŀ������һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 �������ҳ�������������
// ���ظ�����Ԫ�顣   ע�⣺���в����԰����ظ�����Ԫ�顣
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//˫ָ��
//����ȷ��3��������Ҫ3��ָ��

    vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            if(nums.size()<3) return result; //��ǰ�ж��Ƿ����������������˷�ʱ��
            sort(nums.begin(), nums.end());  //��Ŀû˵�Ƿ�������ǰ����
            for(int i =0; i < nums.size();i++){
                if(nums[i] > 0)
                    return result;   //����֮��Ϊ0�������һ��������0���ز����ܺ�Ϊ0
                if(i > 0 && nums[i] == nums[i-1] ) //ȥ�أ������һ����������ͬ�����ܻ�����ظ����
                    continue;
                int left = i+1;
                int right = nums.size()-1;
                while(left < right){
                    if(nums[i] + nums[left] + nums[right] == 0){
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        while(left < right && nums[right] == nums[right-1]) right--; //ȥ�أ����ϱ�ͬ��
                        while(left < right && nums[left] == nums[left+1]) left++;
                        right--;
                        left++;
                    }
                    else if(nums[i] + nums[left] + nums[right] > 0)
                        right--;
                    else
                        left++;
                }
            }
            return result;

    }

int main()
{
    vector<int> ivec1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> slow1 = threeSum(ivec1);
    for(int i = 0; i< slow1.size();i++){
        for(int j = 0; j < 3; j++)
            cout << slow1[i][j]<<" ";
        cout<<endl;}
    return 0;
}
