#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Two Sum Problem

int main(){

    vector<int> vec = {2,6,5,8,11};

    int target = 14;

    int n=vec.size();

    pair<int,int> ans = {-1, -1};
    
    map<int, int> mpp;

    for(int i=0;i<n;i++){
        mpp[vec[i]] = i;
    }

    for(int i=0;i<n;i++){
        if(mpp.find(target-vec[i])!=mpp.end()){
            ans = {i, mpp[target-vec[i]]};
            break;
        }
    }

    cout<<ans.first<<" "<<ans.second;

    return 0;
}