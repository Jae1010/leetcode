//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 219. �����ظ�Ԫ�� II
// ��Ŀ������һ�����������һ������ k���ж��������Ƿ����������ͬ������ i �� j��ʹ
// �� nums [i] = nums [j]������ i �� j �Ĳ�� ����ֵ ����Ϊ k��
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//�������һ��������ʱ
bool containsNearbyDuplicate_1(vector<int>& nums, int k) {
    int left = 0, right = 0;
    unordered_map<int, int> record;
    while( right < nums.size()){
        record[right] = nums[right];
        for(int i = left; i < right; ++i){
            if(record[right] == nums[i])
                return true;
        }
        right++;
        while(right - left > k){
            left++;
        }

    }
    return false;
}

//�������ڣ���������ɹ�ϣ��setά��
bool containsNearbyDuplicate_2(vector<int>& nums, int k) {
    unordered_set<int> record;
    for(int i = 0 ; i < nums.size(); ++i){
        if(record.find(nums[i]) != record.end())
            return true;
        record.insert({nums[i], 1});
        if(record.size() == k+1)
            record.erase(nums[i-k]);
    }
    return false;
}

int main()
{
    vector<int> ivec = {1,2,3,1,2,3};
    bool a = containsNearbyDuplicate_3(ivec, 2);
    cout << a;
    return 0;
}
