#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Subarray Sum Equals K

int countSubarraySum(vector<int> &vec, int &k){
    map<int, int> mpp;
    int sum=0;
    int n=vec.size();
    int ans=0;
    mpp[0]=1;

    for(int i=0; i<n; i++){
        sum+=vec[i];

        if(mpp.find(sum-k)!=mpp.end()){
            ans+=mpp[sum-k];
        }
        
        mpp[sum]++;
    }

    return ans;
}

int main(){

    vector<int> vec = {3, 1, 2, 4};
    int k=6;

    cout<<countSubarraySum(vec, k);

    return 0;
}