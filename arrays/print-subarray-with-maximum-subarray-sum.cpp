#include<iostream>
#include<vector>

using namespace std;

// Print subarray with maximum subarray sum

void maxSubArray(vector<int>& nums) {
    int sum=0;
    int ans=INT_MIN;
    int n = nums.size();
    pair<int, int> ind1 = {0, 0};
    int start=0;

    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum>ans){
            ans = sum;
            ind1 = {start, i};
        }
        if(sum<0){
            sum=0;
            start=i+1;
        }
    }

    for(int i = ind1.first; i<=ind1.second; i++){
        cout<<nums[i]<<" ";
    }

    return;
}

int main(){

    vector<int> vec = {-4, -1, -5};

    maxSubArray(vec);

    return 0;
}