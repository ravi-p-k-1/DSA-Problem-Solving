#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Printing Longest Increasing Subsequence

vector<int> tabulation(vector<int> &nums, int n){
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
                prev[i] = j;
            }
        }
    }
    
    int maxind = 0;
    int maxlen = 0;
    
    for(int i=0;i<n;i++){
        if(dp[i]>maxlen){
            maxind=i;
            maxlen=dp[i];
        }
    }

    vector<int> ans;
    int curr=maxind;

    while(curr!=-1){
        ans.push_back(nums[curr]);
        curr = prev[curr];
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){

    vector<int> nums = {1, 3, 2, 4, 6, 5};

    int n = nums.size();

    vector<int> ans = tabulation(nums, n);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}

