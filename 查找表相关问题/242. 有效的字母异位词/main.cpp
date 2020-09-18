//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 242. ��Ч����ĸ��λ��
// ��Ŀ�����������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
//
//
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if( s.size() != t.size())
       return false;
    unordered_map<char, int> record;
    for(int i = 0; i < s.size(); i++)
        record[s[i]] ++;
    for(int i = 0; i < t.size(); i++){
        if( record[t[i]] > 0)
            record[t[i]] --;
        else
            return false;
        /* if(record[t[i]] == 0)
         return false;*/
    }
    return true;
}

int main()
{
    string s = "anagram", t = "anagram";
    string s1 = "ab", t1 = "a";
    bool a = isAnagram(s, t);
    bool b = isAnagram(s1, t1);
    cout << a << b <<endl;
    return 0;
}
