//==================================================================
// Leetcode����
// ���ߣ��ܼ�
//==================================================================
//
// 167. ����֮�� II - ������������
// ��Ŀ������һ���Ѱ����������� ���������飬�ҵ�������ʹ���������֮�͵���Ŀ������
// ����Ӧ�÷����������±�ֵ index1 �� index2������ index1 ����С�� index2��
//˵��:
//���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�
//����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
//
#include <iostream>
#include <vector>

using namespace std;

//�����ⷨ
vector<int> twoSum1(vector<int>& numbers, int target) {
    vector<int> result;
    for(int i = 0; i < numbers.size()-1;i++)
        for(int j = i+1; j < numbers.size(); j++){
            if(numbers[i] + numbers[j] == target){
                result.push_back(++i);
                result.push_back(++j);
                return result;
            }

    }
    return result;
}

//˫ָ�� ʱ�临�Ӷ�O(n)�� �ռ临�Ӷ�O(1)�� ��ײָ��
vector<int> twoSum2(vector<int>& numbers, int target) {
    int i = 0;
     vector<int> result;
    if(numbers[i] > target)
        return result ;
    int j = numbers.size()-1;

    while( j > i){
        if(numbers[j] >= target){
            j--;
            continue;
        }
        if(numbers[i] + numbers[j] > target)
            j--;
        else if(numbers[i] + numbers[j] < target)
            i++;
        else{
            result.push_back(i+1);
            result.push_back(j+1);
            return result;
        }

    }
    return result;
}

int main()
{
    vector<int> ivec = { -1, 0};
    vector<int> vec = twoSum1(ivec, -1);
    for(auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}
