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

using namespace std;

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

int main()
{
    string str = "tree";
    string st = frequencySort(str);
    cout << st << endl;
    return 0;
}
