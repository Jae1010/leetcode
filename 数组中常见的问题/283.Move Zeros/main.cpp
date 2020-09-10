#include <iostream>
#include <vector>

using namespace std;

class Solution1{
public:
    void moveZeroes(vector<int>& nums){
        vector<int> ivec;
        for( int i = 0; i < nums.size(); i++)
            if (nums[i])
                ivec.push_back(nums[i]);
        for( int i = 0; i < ivec.size();i++)
            nums[i] = ivec[i];
        for( int i = ivec.size(); i < nums.size(); i++)
            nums[i] = 0;


    }
};

class Solution2{
public:
    void moveZeroes(vector<int>& nums){
        int k = 0;  //[0,k)
        for(int i = 0; i < nums.size(); i++)
            if(nums[i])
                if(i != k)
                nums[k++] = nums[i];
            else k++;
        for(int i = k; i < nums.size(); i++)
            nums[i] = 0;
    }
};

class Solution3{
public:
    void moveZeroes(vector<int>& nums){
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i])
                if(i != k)
                    swap(nums[k++], nums[i]);
                else{
                    k++;
                    cout<<k<<"   ";}


    }

};

class Solution4{
public:
    void moveZeroes(vector<int>& nums){
        int k = 0;
        int n = nums.size();
        while( k < n){
            if(nums[k] == 0){
                nums[k] = nums[n-1];
                n--;
            }
            else
                k++;
        }
        for(int i = n; i < nums.size(); i++)
            nums[i] = 0;
    }
};
int main()
{
    int arr[] = {0,1,0,3,12,0};
    vector<int> ivec(arr, arr+sizeof(arr)/sizeof(int));
    //vector<int> arr = {0,1,0,3,12};
    Solution2().moveZeroes(ivec);
    for(int i = 0; i < ivec.size(); i++)
        cout<< ivec[i] <<" ";

    cout <<endl<< "Hello world!" << endl;
    return 0;
}
