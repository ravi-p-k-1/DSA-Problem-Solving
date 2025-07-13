#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> vec = {13,46,24,52,20,9};

    int n = vec.size();

    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            if(vec[j]<vec[j-1]) swap(vec[j], vec[j-1]);
        }
    }

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}