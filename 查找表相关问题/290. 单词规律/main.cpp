//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 290. ���ʹ���
// ��Ŀ������һ�ֹ��� pattern ��һ���ַ��� str ���ж� str �Ƿ���ѭ��ͬ�Ĺ��ɡ�
// ����� ��ѭ ָ��ȫƥ�䣬���磬 pattern ���ÿ����ĸ���ַ��� str �е�ÿ���ǿյ���֮���
// ����˫�����ӵĶ�Ӧ���ɡ�
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> record;
    vector<string> svec;
    string str1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ')
            str1 += s[i];
        else{
            svec.push_back(str1);
            str1 = "";
        }
    }
    svec.push_back(str1);
    if(pattern.size() != svec.size())
        return false;
    for(int i = 0; i < pattern.size(); i++){
        if(record.count(pattern[i]))
            if(record[pattern[i]] != svec[i])
                return false;
        record[pattern[i]] = svec[i];
    }
    // ������֤
    unordered_map<string, char>  record2;
    for(int i = 0; i < pattern.size(); i++){
        if(record2.count(svec[i]))
        if(record2[svec[i]] != pattern[i])
            return false;
        record2[svec[i]] = pattern[i];
    }
    return true;
}

int main()
{
    string pattern = "abba";
    string str = "dog cat cat dog";
    bool a = wordPattern(pattern, str);
    cout << a << endl;
    return 0;
}
