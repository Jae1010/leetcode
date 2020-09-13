//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 125. ��֤���Ĵ�
// ��Ŀ������һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
// ˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)

bool isPalindrome(string s) {
    int slow = 0;
    if(s.size() == 1)
        return true;
//ת���ַ�����ȥ���ո�ȣ���дתСд
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
        i++;
        j--;

    }
    return true;
}

//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
bool isPalindrome1(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
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
