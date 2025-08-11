#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Longest Subarray with sum K | [Postives and Negatives]

int main(){

    map<int, int> mpp;
    vector<int> vec = {-1, 1, 1};
    int k = 0;
    int n=vec.size();
    int ans=0;
    int x=0;

    for(int i=0;i<n;i++){
        x += vec[i];
        if(x==k){
            ans = max(ans, i+1);
        }

        if(mpp.find(x-k)!=mpp.end()){
            ans = max(ans, i-mpp[x-k]);
        }
        
        if(mpp.find(x)==mpp.end()) mpp[x]=i;
    }

    cout<<ans;

    return 0;
}