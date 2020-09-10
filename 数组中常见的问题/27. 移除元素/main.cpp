#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != val)
                if(i != k)
                    swap(nums[k++], nums[i]);
                else
                    k++;

        /*for(int i = nums.size()-1; i>=k; i--)
            nums.pop_back();*/

        return k;

    }
};

int main()
{
    int arr[] = {0,1,0,3,12,0};
    vector<int> ivec(arr, arr+sizeof(arr)/sizeof(int));
    //vector<int> arr = {0,1,0,3,12};
    int k = Solution().removeElement(ivec,0);
    for(int i = 0; i < k; i++)
        cout<< ivec[i] <<" ";
    return 0;
}
