#include<iostream>
#include<vector>

using namespace std;

// Coin Change 2

int memoization(vector<vector<int>> &dp, vector<int> &coins, int ind, int target){

    if(ind==0){
        if(target==0) return 1;
        else if(target%coins[ind]==0) return 1;
        else return 0;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int notpick = memoization(dp, coins, ind-1, target);
    int pick = 0;
    if(target>=coins[ind]) pick = memoization(dp, coins, ind, target-coins[ind]);

    return dp[ind][target] = pick+notpick;
}

int tabulation(vector<vector<int>> &dp, vector<int> &coins, int target){
    int n=coins.size();

    for(int i=0;i<=target;i++){
        dp[0][i] = (i%coins[0]==0);
    }

    for(int i=1;i<n;i++){
        for(int j=0; j<=target; j++){
            int notpick = dp[i-1][j];
            int pick=0;
            if(j>=coins[i]) pick = dp[i][j-coins[i]];
            dp[i][j] = pick + notpick;
        }
    }

    return dp[n-1][target];
}

int main(){

    vector<int> coins = {1, 2, 3};
    int target=4;
    int n=coins.size();

    vector<vector<int>> dp(n, vector<int> (target+1, -1));

    // cout<<memoization(dp, coins, n-1, target);
    cout<<tabulation(dp, coins, target);

    return 0;
}