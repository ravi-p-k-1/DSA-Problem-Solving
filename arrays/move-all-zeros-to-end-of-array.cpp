#include<iostream>
#include<vector>

using namespace std;

// Move all zeroes to the end of the array.

int main(){

    vector<int> vec = {1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};

    int i=0, j=0;

    int n=vec.size();

    while(j<n){
        if(vec[j]==0) break;
        else j++;
    }

    i=j+1;

    while(i<n){
        if(vec[i]==0) i++;
        else{
            swap(vec[i], vec[j]);
            i++;
            j++;
        }
    }

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}