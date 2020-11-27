//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��455. �ַ�����
//��������һλ�ܰ��ļҳ�����Ҫ����ĺ�����һЩС���ɡ����ǣ�ÿ���������ֻ�ܸ�һ����ɡ�
//��ÿ������ i������һ��θ��ֵ g[i]���������ú���������θ�ڵı��ɵ���С�ߴ磻����ÿ����� j������һ���ߴ�
//s[j] ����� s[j] >= g[i]�����ǿ��Խ�������� j ��������� i ��������ӻ�õ����㡣���Ŀ���Ǿ���������Խ��
//�����ĺ��ӣ��������������ֵ��
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int gi = 0, si = 0;
        int res = 0;
        while(gi < g.size() && si <s.size()){
            if(g[gi] <= s[si]){
                res++;
                gi++;
                si++;
            }
            else
                gi++;
        }
        return res;
    }

    int findContentChildren_2(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0, si = 0;
        while(gi < g.size() && si <s.size()){
            if(g[gi] <= s[si])
                gi++;
            si++;
        }
        return gi;
    }
};

int main()
{
    vector<int> g = {1,2,3};
    vector<int> s = {2,3,4};
    int res = Solution().findContentChildren_2(g, s);
    cout << res << endl;
    return 0;
}
