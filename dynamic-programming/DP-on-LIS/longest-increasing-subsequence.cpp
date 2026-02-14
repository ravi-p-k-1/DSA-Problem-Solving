#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Longest Increasing Subsequence

int LIS(vector<int> &nums, int n){
    vector<int> lis;
    lis.push_back(nums[0]);

    for(int i=1;i<n;i++){
        if(nums[i]>lis.back()) lis.push_back(nums[i]);
        else{
            int ind = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            lis[ind] = nums[i];
        }
    }

    return lis.size();
}

int main(){

    vector<int> nums = {0, 1, 0, 3, 2, 3};
    
    int n=nums.size();

    cout<<LIS(nums, n);

    return 0;
}

