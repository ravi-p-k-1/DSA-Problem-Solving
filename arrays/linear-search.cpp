#include<iostream>
#include<vector>

using namespace std;

// Linear search

int main(){

    vector<int> vec = {1, 2, 3, 4, 5};
    int num=3;
    int i;

    for (i = 0; i < vec.size(); i++)
    {
        if(vec[i]==num) break;
    }

    cout<<i;

    return 0;
}