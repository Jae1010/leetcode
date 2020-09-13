//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 11. ʢ���ˮ������
// ��Ŀ������ n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ���������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�
// Ϊ (i, ai) �� (i, 0)���ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
// ˵�����㲻����б�������� n ��ֵ����Ϊ 2��
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//˫ָ��

int maxArea(vector<int>& height) {
    int left = 0, right = height.size()-1,volume = 0;
    while(left < right){
        if(volume < (right - left) * min(height[left], height[right]))
            volume = (right - left) * min(height[left], height[right]);
        if(height[left] > height[right])
            right--;
        else
            left++;
    }
    return volume;
}

int main()
{
    vector<int> ivec = {1,8,6,2,5,4,8,3,7 };
    int a = maxArea(ivec);
    cout << a << endl;//Ԥ�ڽ��49
    return 0;
}
