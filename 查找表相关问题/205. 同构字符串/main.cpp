//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 205. ͬ���ַ���
// ��Ŀ�����������ַ��� s �� t���ж������Ƿ���ͬ���ġ���� s �е��ַ����Ա��滻�õ� t ����ô�������ַ�����ͬ���ġ�
// ���г��ֵ��ַ�����������һ���ַ��滻��ͬʱ�����ַ���˳�������ַ�����ӳ��
// �ϣ����ַ�����ӳ���Լ�����
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ����case100%
bool isIsomorphic1(string s, string t) {
    unordered_map<char, int> sRecord;
    unordered_map<char, int> tRecord;
    if(s.size() != t.size())
        return false;
    for(int i = 0; i < s.size(); i++){
        sRecord[s[i]]++;
        tRecord[t[i]]++;
        if(sRecord.size() != tRecord.size()||sRecord[s[i]] != tRecord[t[i]])
            return false;
    }
    return true;
}
//˫��ϣ��ӳ��
bool isIsomorphic(string s, string t) {
    if(s.size() != t.size())
        return false;
    unordered_map<char, char> s_to_t;
    for(int i = 0; i < s.size(); i++){
        if(s_to_t.count(s[i]))
            if(s_to_t[s[i]] != t[i])
                return false;
        s_to_t[s[i]] = t[i];
    }
    unordered_map<char, char> t_to_s;
    for(int i = 0; i < s.size(); i++){
        if(t_to_s.count(t[i]))
            if(t_to_s[t[i]] != s[i])
                return false;
        t_to_s[t[i]] = s[i];
    }
    return true;

}
//ͬ��ӳ�䵽���������Ƚ��Ƿ���ͬ
bool isIsomorphic2(string s, string t) {
    if(s.size() != t.size())
        return false;
    int sArr[256] = {0};
    int tArr[256] = {0};
    for( int i = 0; i < s.size(); i++){
        if(sArr[s[i]] != tArr[t[i]])
            return false;
        else
            if(sArr[s[i]] == 0){
                sArr[s[i]] = i+1;
                tArr[t[i]] = i+1;
            }
    }
    return true;

}


int main()
{
    string s = "aabb", t = "abba";
    bool a = isIsomorphic2(s, t);
    cout << a << endl;
    return 0;
}
