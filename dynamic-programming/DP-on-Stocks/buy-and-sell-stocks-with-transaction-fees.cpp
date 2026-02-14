#include<iostream>
#include<vector>

using namespace std;

// Buy and Sell Stocks With Transaction Fees

int memoization(vector<int> &prices, vector<vector<int>> &dp, int i, int j, int k){

    if(i==prices.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans;

    if(j==0) ans = memoization(prices, dp, i+1, 1, k) - prices[i];
    else ans = memoization(prices, dp, i+1, 0, k) + prices[i] - k;

    ans = max(ans, memoization(prices, dp, i+1, j, k));

    return dp[i][j] = ans;
}

int main(){

    vector<int> prices = {1, 3, 2, 8, 4, 9};

    int n = prices.size();

    int fees = 2;

    vector<vector<int>> dp(n, vector<int>(2, -1));

    cout<<memoization(prices, dp, 0, 0, fees);

    return 0;
}

