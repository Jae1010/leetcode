//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��135. �ַ��ǹ�
// ��ʦ��������Ƿַ��ǹ����� N ������վ����һ��ֱ�ߣ���ʦ�����ÿ�����ӵı��֣�Ԥ�ȸ��������֡�
//����Ҫ��������Ҫ�󣬰�����ʦ����Щ���ӷַ��ǹ���ÿ���������ٷ��䵽 1 ���ǹ������ڵĺ����У����ָߵĺ��ӱ����ø�����ǹ���
//��ô������������ʦ������Ҫ׼�����ٿ��ǹ��أ�
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candise(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1] )
                candise[i] = candise[i-1] + 1;
        }
        for(int i = ratings.size() - 1; i > 0; i--){
            if(ratings[i] < ratings[i-1] )
                candise[i-1] = max(candise[i] + 1, candise[i-1]);
        }

        return accumulate(candise.begin(), candise.end(), 0);
    }
};

int main()
{
    vector<int> r = {1,3,2,2,1};
    int sum = Solution().candy(r);
    cout << sum << endl;
    return 0;
}
