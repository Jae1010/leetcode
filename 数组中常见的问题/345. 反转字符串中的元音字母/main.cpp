//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 345. 反转字符串中的元音字母
// 题目：编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
//
//
//
#include <iostream>
#include <vector>

using namespace std;


string reverseVowels(string s){
    int left = 0, right = s.size()-1;
    string yuanyin = "aeiouAEIOU";
    while( left < right ){
        while( left<right && yuanyin.find(s[left]) == -1)//string的find()函数
                    left++;
        while( left<right && yuanyin.find(s[right]) == -1)
            right--;
        swap(s[left++], s[right--]);
    }
    return s;
}


int main()
{
    string s = "hello";
    string str = reverseVowels(s);
    cout<<str<<endl;
    return 0;
}
