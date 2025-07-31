#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> vec = {1, 2, 3, 4, 5};

    int store = vec[0];

    int n=vec.size();

    for(int i=0;i<n-1;i++){
        vec[i]=vec[i+1];
    }

    vec[n-1] = store;

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}


