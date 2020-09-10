//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================

// 80. ɾ�����������е��ظ��� II
// ��Ŀ������һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ������Ƴ���������³��ȡ�
// ��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
#include <iostream>
#include <vector>

using namespace std;

//����ⷨ�����ƹ㵽����n����ͬԪ��

int removeDuplicates(vector<int>& nums) {
    int slowIndex = 0;
    for( int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        if( slowIndex < 2 || nums[fastIndex] != nums[slowIndex-2] )
            if(slowIndex == fastIndex)  //�������ָ����ͬ����ָ���ֱ��ǰ�������ø��ƣ��ķ�ʱ��
                slowIndex++;
            else
                nums[slowIndex++] = nums[fastIndex];
    return slowIndex;
    }

int main()
{
    vector<int> ivec = {1, 1, 2, 2};
    int slow = removeDuplicates(ivec);
    for(int i = 0; i < slow; i++)
        cout << ivec[i] << " ";
    cout << endl;
    vector<int> ivec1 = {1, 1, 2, 2,2,2,2,2,2,3,4,4};
    int slow1 = removeDuplicates(ivec1);
    for(int i = 0; i < slow1; i++)
        cout << ivec1[i] << " ";
    return 0;

    return 0;
}
