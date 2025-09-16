#include<iostream>
#include<vector>

using namespace std;

// Grid Unique Paths 2

int memoization(vector<vector<int>> &dp, vector<vector<int>> &vec, int i, int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    if(vec[i][j]==-1) return dp[i][j]=0;
    return dp[i][j] = memoization(dp, vec, i-1, j) + memoization(dp, vec, i, j-1);
}

int tabulation(vector<vector<int>> &dp, vector<vector<int>> &vec){
    int m=dp[0].size();
    int n=dp.size();

    for(int i=0;i<m;i++){
        if(vec[0][i]==0) dp[0][i]=1;
        else dp[0][i]=0;
    }
    
    for(int i=0;i<n;i++){
        if(vec[i][0]==0) dp[i][0]=1;
        else dp[i][0]=0;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(vec[i][j]==0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else dp[i][j]=0;
        }
    }

    return dp[n-1][m-1];
}

int main(){

    int n=3;
    int m=3;

    vector<vector<int>> vec={
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    vector<vector<int>> dp(n, vector<int> (m, -1));

    // cout<<memoization(dp, vec, n-1, m-1);
    cout<<tabulation(dp, vec);

    return 0;
}