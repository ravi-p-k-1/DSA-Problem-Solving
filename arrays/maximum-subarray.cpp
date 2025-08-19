#include<iostream>
#include<vector>

using namespace std;

// Maximum Subarray

int maxSubArray(vector<int>& nums) {
    int sum=0;
    int ans=INT_MIN;

    for(auto &i: nums){
        sum+=i;
        ans = max(ans,sum);
        if(sum<0) sum=0;
    }

    return ans;
}

int main(){

    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<maxSubArray(vec);

    return 0;
}