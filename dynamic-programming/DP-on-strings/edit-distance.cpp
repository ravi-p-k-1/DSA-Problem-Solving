#include<iostream>
#include<vector>

using namespace std;

// Edit Distance

int memoization(string &s1, string &s2, vector<vector<int>> &dp, int i, int j){
    if(j<0) return i+1;
    if(i<0) return j+1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]) dp[i][j] = memoization(s1, s2, dp, i-1, j-1);
    else{
        int ans = INT_MAX;

        ans = min(ans, 1+memoization(s1, s2, dp, i, j-1)); //insert
        ans = min(ans, 1+memoization(s1, s2, dp, i-1, j)); //delete
        ans = min(ans, 1+memoization(s1, s2, dp, i-1, j-1)); //replace

        dp[i][j] = ans;
    }

    return dp[i][j];
}

int tabulation(string &s1, string &s2, vector<vector<int>> &dp){
    int n=s1.size();
    int m=s2.size();

    for(int i=0;i<=n; i++){
        dp[i][0] = i;
    }

    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int ans = INT_MAX;
                ans = min(ans, 1+dp[i-1][j]); //delete
                ans = min(ans, 1+dp[i][j-1]); //insert
                ans = min(ans, 1+dp[i-1][j-1]); //replace
                dp[i][j]=ans;
            }
        }
    }

    return dp[n][m];
}

int main(){

    string s1 = "abcdefg";
    string s2 = "azced";

    int n=s1.size();
    int m=s2.size();

    // vector<vector<int>> dp(n, vector<int> (m, -1));
    // cout<<memoization(s1, s2, dp, n-1, m-1);

    
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    cout<<tabulation(s1, s2, dp);

    return 0;
}

