#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Largest Subarray with 0 Sum

int main(){

    vector<int> vec = {1, 3, -5, 6, -2};
    int sum=0;
    int ans=0;
    int n=vec.size();
    map<int, int> mpp;

    for(int i=0;i<n;i++){
        sum+=vec[i];

        if(sum==0) ans=max(ans, i+1);
        else if(mpp.find(sum)!=mpp.end()){
            ans = max(ans, i-mpp[sum]);
        }
        else mpp[sum]=i;
    }

    cout<<ans;

    return 0;
}