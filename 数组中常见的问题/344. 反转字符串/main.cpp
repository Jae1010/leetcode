//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 344. ��ת�ַ���
// ��Ŀ����дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������
// ��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
// ����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���
//
#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int left = 0, right = s.size()-1;
    while( left < right ){
        s[left] = s[left] + s[right];
        s[right] = s[left] - s[right];
        s[left] = s[left] - s[right];
        left++;
        right--;
    }
}

int main()
{
    vector<char> ivec = {'h','e','l','l','o'};
    reverseString(ivec);
    for(auto i : ivec)
        cout<<i<<" ";
    return 0;
}
