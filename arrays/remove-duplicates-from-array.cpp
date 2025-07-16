#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Remove duplicates from array

int main(){

    vector<int> vec = {1,1,2,2,2,3,3};

    map<int, int> mpp;

    for(auto &i: vec){
        mpp[i]=1;
    }

    vec.clear();

    for(auto &i: mpp){
        vec.push_back(i.first);
    }

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}