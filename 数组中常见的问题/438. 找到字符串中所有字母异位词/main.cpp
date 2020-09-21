//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 438. �ҵ��ַ�����������ĸ��λ��
// ��Ŀ������һ���ַ��� s ��һ���ǿ��ַ��� p���ҵ� s �������� p ����ĸ��λ�ʵ��Ӵ���������Щ�Ӵ�����ʼ������
// �ַ���ֻ����СдӢ����ĸ�������ַ��� s �� p �ĳ��ȶ������� 20100��
//˵������ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
//      �����Ǵ������˳��
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//˫ָ��  �������� ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, window;
    for( char c : p)
        need[c]++;
    vector<int> result;

    int right = 0, left = 0;
    int valid = 0;
    while(right < s.size()){
        char c = s[right++];
        if(need.count(c)){
            window[c] ++;
            if(window[c] == need[c])
                valid ++;
        }
        while(right - left >= p.size()){
            if( valid == need.size())
                result.push_back(left);
            char d = s[left++];
            if(need.count(d)){
                if(window[d] == need[d])
                    valid--;
                window[d] --;
            }
        }
    }
    return result;
}

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);
    for(auto i : result)
        cout << i << " ";
    return 0;
}
