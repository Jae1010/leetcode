//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 567. �ַ���������
// ��Ŀ�����������ַ��� s1 �� s2��дһ���������ж� s2 �Ƿ���� s1 �����С�
// ���仰˵����һ���ַ���������֮һ�ǵڶ����ַ������Ӵ���
//
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//�������� ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;
    for(char i : s1) need[i] ++;

    int left = 0, right = 0, valid = 0;
    bool res = false;
    while(right < s2.size()){
        char c = s2[right++];
        if(need.count(c)){
            window[c] ++;
            if(window[c] == need[c])
                valid ++;
        }
        while(right - left >= s1.size()){//������right - left >= need.size(),
            if(valid == need.size())      //��Ϊs1�������ظ���ĸ��need.size()<=s1.size()
                return true;
            char d = s2[left++];
            if(need.count(d)){
                if(need[d] == window[d])
                    valid--;
                window[d] --;
            }
        }
    }
    return res;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool a = checkInclusion(s1 ,s2);
    cout << a << endl;
    return 0;
}
