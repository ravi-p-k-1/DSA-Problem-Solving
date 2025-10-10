#include<iostream>
#include<vector>

using namespace std;

// Unbounded Knapsack

int memoization(vector<vector<int>> &dp, vector<int> &wt, vector<int> &val, int ind, int target){

    if(ind==0){
        return (target/wt[ind])*val[ind];
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int notpick = memoization(dp, wt, val, ind-1, target);
    int pick = 0;
    if(target>=wt[ind]) pick = val[ind] + memoization(dp, wt, val, ind, target - wt[ind]);

    return dp[ind][target] = max(notpick, pick);
}

int main(){

    vector<int> wt = {2, 4 ,6};
    vector<int> val = {5, 11, 13};
    
    int w=10;
    int n=wt.size();

    vector<vector<int>> dp(n, vector<int> (w+1, -1));

    cout<<memoization(dp, wt, val, n-1, w);

    return 0;
}