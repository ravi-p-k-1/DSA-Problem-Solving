#include<iostream>
#include<vector>

using namespace std;

// Selection Sort

int main(){

    vector<int> vec = {13,46,24,52,20,9};
    int n = vec.size();

    for(int i=0; i<n; i++){
        int mini=i;

        for(int j=i; j<n; j++){
            if(vec[mini]>vec[j]) mini=j;
        }

        swap(vec[i], vec[mini]);
    }

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}