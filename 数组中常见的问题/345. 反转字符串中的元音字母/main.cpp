//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 345. ��ת�ַ����е�Ԫ����ĸ
// ��Ŀ����дһ�����������ַ�����Ϊ���룬��ת���ַ����е�Ԫ����ĸ��
//
//
//
#include <iostream>
#include <vector>

using namespace std;


string reverseVowels(string s){
    int left = 0, right = s.size()-1;
    string yuanyin = "aeiouAEIOU";
    while( left < right ){
        while( left<right && yuanyin.find(s[left]) == -1)//string��find()����
                    left++;
        while( left<right && yuanyin.find(s[right]) == -1)
            right--;
        swap(s[left++], s[right--]);
    }
    return s;
}


int main()
{
    string s = "hello";
    string str = reverseVowels(s);
    cout<<str<<endl;
    return 0;
}
