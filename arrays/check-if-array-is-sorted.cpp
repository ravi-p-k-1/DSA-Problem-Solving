#include<iostream>
#include<vector>

using namespace std;

// Check if array is sorted

bool check(vector<int> &vec, int n){
    
    for(int i=0;i<n-1;i++){
        if(vec[i]>vec[i+1]){
            return false;
        }
    }

    return true;
}

int main(){

    vector<int> vec = {1,2,3,4,5};

    int n=vec.size();

    bool flag=check(vec, n);

    if(!flag) cout<<"Not sorted";
    else cout<<"Sorted";

    return 0;
}