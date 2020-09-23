//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 451. �����ַ�����Ƶ������
// ��Ŀ������һ���ַ������뽫�ַ�������ַ����ճ��ֵ�Ƶ�ʽ������С�
//
//
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

//�����¼Ƶ��
string frequencySort(string s) {
    int arr[256] = {0};
    for(int i = 0; i < s.size(); ++i){
        ++arr[s[i]] ;
    }
    char c;
    string  str;
    for(int i = 0; i < s.size(); ++i){
        c = max_element(arr, arr + 256) - arr;
        while(arr[c]){
            str += c;
            -- arr[c];
        }
    }
    return str;
}

//���ȶ���
string frequencySort1(string s) {
    unordered_map<char, int> record;
    for(const auto &i : s)
        ++record[i];
    priority_queue<pair<char, int>> pq;
    for(const auto &i : record)
        pq.push(make_pair(i.second, i.first));
    string res;
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        //while(t.first--)
        //res+=t.second;//res.push_back(t.second_;
        res.append(t.first, t.second);
    }
    return res;
}

int main()
{
    string str = "tree";
    string st = frequencySort1(str);
    cout << st << endl;
    return 0;
}
