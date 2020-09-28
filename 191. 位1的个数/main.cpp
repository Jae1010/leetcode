//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 191. 位1的个数
// 题目：编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个
//      数（也被称为汉明重量）。
//
//
#include <iostream>
#include <vector>

using namespace std;
//时间复杂度O(logn)
int hammingWeight_1(uint32_t n) {
    int ones = 0;
    while(n > 0){
        ones += ( n & 1);
        n >>= 1;
    }
    return ones;
}

//该算法执行时间正比于n中1的个数  时间复杂度O(logn)
int hammingWeight_2(uint32_t n) {
    int ones = 0;
    while(n > 0){
        ones ++;
        n &= n-1; //最低位1用完就被变为0,
    }
    return ones;
}

int main()
{
    vector<int> ivec = { };

    int a = hammingWeight_2(441);
    cout << a;
    return 0;
}
