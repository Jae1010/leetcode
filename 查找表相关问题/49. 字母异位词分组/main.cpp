//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 49. ��ĸ��λ�ʷ���
// ��Ŀ������һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�
//  ͬ���ַ�����
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> record;
    for(const string& s: strs){
        string t = s;
        sort(t.begin(), t.end());
        record[t].push_back(s);
    }
    for(auto &i : record)
        res.push_back(i.second);
    return res;
}



vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    int sub=0;  //���vector���±�ֵ
    string tmp; //��ʱstring
    unordered_map<string,int> work; //�ж�����󵥴��Ƿ���ڣ�����ĸ����Ƿ�һ��
    for(auto str:strs)
    {
        tmp=str;
        sort(tmp.begin(),tmp.end());
        if(work.count(tmp))
        {
            res[work[tmp]].push_back(str);
        }
        else
        {
            vector<string> vec(1,str);
            res.push_back(vec);
            work[tmp]=sub++;
        }
    }
    return res;
}


int main()
{
    vector<string> ivec = { "eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> str = groupAnagrams(ivec);
    for(auto &i : str){
        for(auto &j : i)
            cout<<j<<" ";
        cout << endl;}
    return 0;
}
