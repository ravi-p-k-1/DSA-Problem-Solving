#include<iostream>
#include<vector>

using namespace std;

// Maximum Product Subarray in an Array

int main(){

    vector<int> vec = {1,2,3,4,5,0};
    int n=vec.size();
    int pre=1;
    int suff=1;
    int ans=INT_MIN;

    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre*=vec[i];
        suff*=vec[n-1-i];
        ans = max(ans, max(pre, suff));
    }

    cout<<ans;

    return 0;
}