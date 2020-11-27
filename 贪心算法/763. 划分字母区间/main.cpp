//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��763. ������ĸ����
// �ַ��� S ��Сд��ĸ��ɡ�����Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ��ĸ��������һ��Ƭ���С�
//����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�
//
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char, int> m;
        for(int i = 0; i < S.size(); i++){
            m[S[i]] = i;
        }

        int be = 0, la = 0;
        for(int i = 0; i < S.size(); i++){
            la = max(la, m[S[i]]);
            if( i == la){
                res.push_back(la - be + 1);
                be = i + 1;
            }
        }
        return res;
    }
};

int main()
{
    string S = "ababcbacadefegdehijhklij";
    vector<int> res = Solution().partitionLabels(S);
    for(auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
