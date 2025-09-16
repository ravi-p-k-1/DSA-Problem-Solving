#include<iostream>
#include<vector>

using namespace std;

// Grid Unique Paths

int memoization(vector<vector<int>> &dp, int i, int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = memoization(dp, i-1, j) + memoization(dp, i, j-1);
}

int tabulation(vector<vector<int>> &dp){
    int m=dp[0].size();
    int n=dp.size();

    for(int i=0;i<m;i++){
        dp[0][i]=1;
    }
    
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[n-1][m-1];
}

int spaceOptimized(int n, int m){
    vector<int> prev(m, 1);
    
    for(int i=1;i<n;i++){
        vector<int> curr(m, 0);
        curr[0]=1;
        for(int j=1;j<m;j++){
            curr[j] = curr[j-1]+prev[j];
        }
        prev=curr;
    }

    return prev[m-1];
}

int main(){

    int m = 3;
    int n = 2;

    vector<vector<int>> dp(n, vector<int> (m, -1));

    // cout<<memoization(dp, n-1, m-1);
    // cout<<tabulation(dp);
    cout<<spaceOptimized(n,m);

    return 0;
}

