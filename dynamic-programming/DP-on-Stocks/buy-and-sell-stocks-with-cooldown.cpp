#include<iostream>
#include<vector>

using namespace std;

// Buy and Sell Stocks With Cooldown

int memoization(vector<int> &prices, vector<vector<int>> &dp, int i, int j){
    if(i>=prices.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans;

    if(j==0) ans = memoization(prices, dp, i+1, 1) - prices[i];
    else ans = memoization(prices, dp, i+2, 0) + prices[i];

    ans = max(ans, memoization(prices, dp, i+1, j));

    return dp[i][j] = ans;
}

int tabulation(vector<int> &prices, vector<vector<int>> &dp){

    int n=prices.size();

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=1; j++){
            int ans;

            if(j==0) ans = dp[i+1][1] - prices[i];
            else ans = dp[i+2][0] + prices[i];
            
            ans = max(ans, dp[i+1][j]);
            
            dp[i][j] = ans;
        }
    }

    return dp[0][0];

}

int main(){

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int n = prices.size();

    // vector<vector<int>> dp(n, vector<int> (2, -1));
    // cout<<memoization(prices, dp, 0, 0);

    vector<vector<int>> dp(n+2, vector<int> (2, 0));
    cout<<tabulation(prices, dp);

    return 0;
}


