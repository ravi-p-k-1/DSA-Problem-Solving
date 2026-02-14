#include<iostream>
#include<vector>

using namespace std;

// Stock Buy And Sell 3

int memoization(vector<int> &prices, vector<vector<vector<int>>> &dp, int i, int j, int k){

    if(i==prices.size() || k==0) return 0;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int ans;

    if(j==1) ans = memoization(prices, dp, i+1, 0, k) - prices[i];
    else ans = prices[i] + memoization(prices, dp, i+1, 1, k-1);

    ans = max(ans, memoization(prices, dp, i+1, j, k));

    return dp[i][j][k] = ans;

}

int tabulation(vector<int> &prices, vector<vector<vector<int>>> &dp){
    int n = prices.size();

    for(int i=n-1; i>=0; i--){
        for(int j=1; j>=0; j--){
            for(int k=1; k<=2; k++){
                int ans;
                
                if(j==1) ans = dp[i+1][0][k] - prices[i];
                else ans = prices[i] + dp[i+1][1][k-1];

                dp[i][j][k] = max(ans, dp[i+1][j][k]);
            }
        }
    }

    return dp[0][1][2];
}

int main(){

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int n = prices.size();

    // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    // cout<<memoization(prices, dp, 0, 1, 2);

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
    cout<<tabulation(prices, dp);

    return 0;
}


