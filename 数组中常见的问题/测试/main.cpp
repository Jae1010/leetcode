#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> ivec = {1,21,213,4,5};
    vector<int> vec;
    //vec.push_back(ivec[1,2]);
    for(auto i : vec)
        cout << i <<" ";
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
