#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Stock Buy And Sell 2

int memoization(vector<int> &prices, vector<vector<int>> &dp, int i, int j){

    if(i==prices.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int buy = INT_MIN;
    if(j==1) buy = memoization(prices, dp, i+1, 0) - prices[i];

    int sell = INT_MIN;
    if(j==0) sell = prices[i] + memoization(prices, dp, i+1, 1);

    int skip = memoization(prices, dp, i+1, j);

    return dp[i][j] = max(buy, max(sell, skip));
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));

    cout<<memoization(prices, dp, 0, 1);

    return 0;
}


