//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：135. 分发糖果
// 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
//你需要按照以下要求，帮助老师给这些孩子分发糖果：每个孩子至少分配到 1 个糖果。相邻的孩子中，评分高的孩子必须获得更多的糖果。
//那么这样下来，老师至少需要准备多少颗糖果呢？
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
