#include<iostream>
#include<vector>

using namespace std;

// Minimum Path Sum In a Grid

int memoization(vector<vector<int>> &dp, vector<vector<int>> &vec, int i, int j){
    if(i==0 && j==0) return vec[i][j];
    if(i<0 || j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = vec[i][j] + min(memoization(dp, vec, i-1, j), memoization(dp, vec, i, j-1));
}

int tabulation(vector<vector<int>> &dp, vector<vector<int>> &vec){
    int n=vec.size();
    int m=vec[0].size();

    dp[0][0]=vec[0][0];

    for(int i=1;i<m;i++){
        dp[0][i]=vec[0][i] + dp[0][i-1];
    }
    
    for(int i=1;i<n;i++){
        dp[i][0]=vec[i][0] + dp[i-1][0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j] = vec[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n-1][m-1];
}

int main(){

    vector<vector<int>> vec = {
        {5, 9, 6},
        {11, 5, 2}
    };

    int n=vec.size();
    int m=vec[0].size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    // cout<<memoization(dp, vec, n-1, m-1);
    cout<<tabulation(dp, vec);

    return 0;
}