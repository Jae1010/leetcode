//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 125. 验证回文串
// 题目：给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
// 说明：本题中，我们将空字符串定义为有效的回文串。
//
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//

bool isPalindrome(string s) {
    int slow = 0;
    if(s.size() == 1)
        return true;
//转换字符串，去除空格等，大写转小写
    for(int fast = 0; fast<s.size();fast++){
        if((s[fast]>='a'&&s[fast]<='z') || (s[fast]>='A'&&s[fast]<='Z')||(s[fast]>='0'&&s[fast]<='9'))
            if(s[fast] <= 'Z'&&s[fast] >='A')
                    s[slow++] = s[fast]+32;
                else
                    s[slow++] = s[fast];
    }
    int i= 0, j = slow-1;
    while(i < j){
        if(s[i] != s[j])
            return false;
        else{
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string str = "A man, a plan, a canal: Panama";
    string str1 = "!!!";
    bool a = isPalindrome(str);
    bool b = isPalindrome((str1));
    cout << a << b<<endl;
    return 0;
}
