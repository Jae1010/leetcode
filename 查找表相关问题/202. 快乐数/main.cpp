//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 202. 快乐数
// 题目：编写一个算法来判断一个数 n 是不是快乐数。
// 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复
//这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
//如果 n 是快乐数就返回 True ；不是，则返回 False 。
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int getNext(int n){
    int sum = 0;
    while ( n > 0){
        int d = n % 10; //十进制除十取余
        n = n/10;
        sum += d*d;
    }
    return sum;
}

// 转化为寻找链表是否有环的问题
bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    while( fast != 1 && fast != slow){
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast == 1;
}

int main()
{
    int n;
    while(cin >> n){
    bool a = isHappy(n);
    cout << (a ? "is a happy numer!" : "is not a happy numer!")<< endl;}
    return 0;
}
