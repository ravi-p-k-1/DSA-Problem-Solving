#include<iostream>
#include<vector>

using namespace std;

// Minimum Coins

int memoization(vector<vector<int>> &dp, vector<int> &coins, int target, int ind){

    if(ind==0){
        if(target%coins[ind]==0) return target/coins[ind];
        return INT_MAX;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int nottake = memoization(dp, coins, target, ind-1);
    int take=1e9;
    if(target>=coins[ind]) take = 1 + memoization(dp, coins, target-coins[ind], ind);

    return dp[ind][target] = min(take, nottake);
}

int tabulation(vector<vector<int>> &dp, vector<int> &coins, int target){
    int n=coins.size();

    for(int i=0;i<=target;i++){
        dp[0][i] = INT_MAX;
        if(i%coins[0]==0) dp[0][i] = i/coins[0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int nottake = dp[i-1][j];
            int take=INT_MAX;
            if(j>=coins[i]) take = 1 + dp[i][j-coins[i]];
            dp[i][j] = min(take, nottake);
        }
    }

    return dp[n-1][target];
}

int main(){
    
    vector<int> coins = {1, 2, 3};
    int target = 7;

    int n=coins.size();

    vector<vector<int>> dp(n, vector<int> (target+1, -1));

    // cout<<memoization(dp, coins, target, n-1);
    cout<<tabulation(dp, coins, target);

    return 0;
}