#include<iostream>
#include<vector>

using namespace std;

// Longest Common Subsequence

int memoization(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){

    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans;
    
    if(s1[i]==s2[j]){
        ans = 1+memoization(s1, s2, i-1, j-1, dp);
    }
    else{
        ans = max(memoization(s1, s2, i-1, j, dp), memoization(s1, s2, i, j-1, dp));
    }

    return dp[i][j] = ans;
}

int tabulation(string &s1, string &s2, vector<vector<int>> &dp){
    int n=s1.size();
    int m=s2.size();

    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }

    for(int i=0; i<=m; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int val=0;
            if(s1[i-1]==s2[j-1]){
                val = 1 + dp[i-1][j-1];
            }
            else{
                val = max(dp[i-1][j], dp[i][j-1]);
            }
            dp[i][j] = val;
        }
    }

    return dp[n][m];

}

int main(){

    string s1 = "eeeme";
    string s2 = "emeee";

    int n = s1.size();
    int m = s2.size();

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout<<memoization(s1, s2, n-1, m-1, dp);

    
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout<<tabulation(s1, s2, dp);

    return 0;
}


