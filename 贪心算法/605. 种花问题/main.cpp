//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
//
// ��Ŀ��605.�ֻ�����
// ��������һ���ܳ��Ļ�̳��һ���ֵؿ���ֲ�˻�����һ����ȴû�С����ǣ����ܲ�����ֲ�����ڵĵؿ��ϣ����ǻ�����ˮԴ�����߶�����ȥ��
//����һ����̳����ʾΪһ���������0��1������0��ʾû��ֲ����1��ʾ��ֲ�˻�������һ���� n ���ܷ��ڲ�������ֲ�����
//��������� n �仨�����򷵻�True�������򷵻�False��
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//����0�ĸ�����ÿ3��0������һ�仨
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int num = 1;   //��0�ĸ�������ʼΪ1�� ������߽��һ��0

        for(int i = 0; i < flowerbed.size(); i++){

            if(flowerbed[i] == 0)
                num++;
            else
                num = 0;

            if(num == 3){
                n--;
                num = 1;  //������3��0�м�λ���ֻ����ұߵ�һ��0��������һ��3��0�ĵ�һ��0
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
