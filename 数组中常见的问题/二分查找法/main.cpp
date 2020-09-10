#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

int *generateOrderArray( int n ){
    assert( n > 0);
    int *arr[] = new int[n];
    for( int i = 0; i < n; i++)
        arr[i] = i;
    return **arr;
}

template<typename T>
int binartSearch( T arr[], int n, T target){
    int l = 0,r = n -1 ;
    while(l <= r){
        int mid = l + (r-l)/2;
        if( arr[mid] == target)
            return mid;
        if( arr[mid] < arr[r])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;


}

int main()
{
    int n = 1000000;
    int* data = generateOrderArray(n);
    clock_t startTime = clock();
    int i = binartSearch(data, n, 5000);
    clockid_t endTime = clock();
    cout<<"time cost"<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
