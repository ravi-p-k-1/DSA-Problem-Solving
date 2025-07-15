#include<iostream>
#include<vector>

using namespace std;

// Largest element in an Array

int main(){

    vector<int> vec = {8,10,5,7,9};

    int maxi=INT_MIN;

    for(auto &i: vec){
        maxi= max(i, maxi);
    }

    cout<<maxi;

    return 0;
}
