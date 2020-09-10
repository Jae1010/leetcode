//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================

// 18. ����֮��
// ��Ŀ������һ������ n ������������ nums ��һ��Ŀ��ֵ target���ж� nums ���Ƿ�����ĸ�Ԫ�� a��b��c �� d ��ʹ�� a + b + c +
// d ��ֵ�� target ��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣 ע�⣺���в����԰����ظ�����Ԫ�顣
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//˫ָ��
//������֮����·��ͬ��������Ҫȷ���ĸ�����������Ҫ4��ָ��,��һ��ѭ��

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if(nums.size()<4) return result;
        for(int i = 0; i < nums.size()-3; i++){
           // if((nums[i] + 3 * nums[nums.size()-1]) < target)
               // break;
            if(i > 0 && nums[i] == nums[i-1] )
                continue;
            for(int j = i+1; j < nums.size()-2; j++){
                //if(nums[i] + nums[j]+ 2*nums[j+1] > target)
                //    break;
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int left = j+1;
                int right = nums.size()-1;
                while(left < right){
                    if(nums[i] + nums[j] + nums[left] + nums[right] == target){
                        result.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if(nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                    else
                        left++;
                }
            }
        }
        return result;
    }

int main()
{
    vector<int> ivec1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> vec = fourSum(ivec1, 0);
    for(int i = 0; i< vec.size();i++){
        for(int j = 0; j < 4; j++)
            cout << vec[i][j]<<" ";
        cout<<endl;}
    return 0;
}
