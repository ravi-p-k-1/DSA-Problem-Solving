#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Remove duplicates from array

int main(){

    vector<int> vec = {1,1,2,2,2,3,3};

    int n=vec.size();
    
    int i=0, j=0;

    while(j<n){
        if(vec[j]!=vec[i]){
            i++;
            vec[i]=vec[j];
        }
        j++;
    }
    i++;

    while(i<n){
        vec.pop_back();
        i++;
    }

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}