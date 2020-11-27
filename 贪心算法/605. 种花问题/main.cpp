//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
//
// 题目：605.种花问题
// 假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的
//情况下种入 n 朵花？能则返回True，不能则返回False。
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//计数0的个数，每3个0可以种一朵花
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int num = 1;   //计0的个数，初始为1， 虚拟左边界加一个0

        for(int i = 0; i < flowerbed.size(); i++){

            if(flowerbed[i] == 0)
                num++;
            else
                num = 0;

            if(num == 3){
                n--;
                num = 1;  //由于在3个0中间位置种花，右边第一个0可以算下一组3个0的第一个0
            }
        }
        if(num == 2)
            n--;

        if(n <= 0)
            return true;

        return false;
    }
};

int main()
{
    vector<int> ivec = {0,0,0,0,1};
    int n = 2;
    bool b = Solution().canPlaceFlowers(ivec, n);
    cout << b << endl;
    return 0;
}
