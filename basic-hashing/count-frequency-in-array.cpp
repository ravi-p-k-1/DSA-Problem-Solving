#include<iostream>
#include<map>
#include<vector>
using namespace std;

// Count frequency of element in an array

int main(){

    map<int, int> mpp;

    vector<int> vec = {10,5,10,15,10,5};

    for(auto &i: vec){
        mpp[i]++;
    }

    for(auto &i: mpp){
        cout<<i.first<<": "<<i.second<<endl;
    }

    return 0;
}