#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Max and Min frequency element in an array using hash

int main(){

    map<int, int> mpp;

    vector<int> vec = {10,5,10,15,10,5};

    for(auto &i: vec){
        mpp[i]++;
    }

    int maxi = vec[0];
    int mini = vec[0];

    for(auto &i: mpp){
        if(mpp[maxi]<i.second) maxi=i.first;
        if(mpp[mini]>i.second) mini=i.first;
    }

    cout<<"max: "<<maxi<<endl;
    cout<<"min: "<<mini;

    return 0;
}