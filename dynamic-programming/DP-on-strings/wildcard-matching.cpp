#include<iostream>
#include<vector>

using namespace std;

// Wildcard Matching

bool tabulation(string &s1, string &s2, vector<vector<int>> &dp){
    int n = s1.size();
    int m = s2.size();

    dp[0][0] = 1;

    for(int i=1;i<=m;i++){
        if(s1[i-1]=='*') dp[0][i]=1;
        else break; 
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]=='*') dp[i][j] = dp[i][j-1] || dp[i-1][j];
            else if(s1[i-1]=='?') dp[i][j] = dp[i-1][j-1];
            else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 0;
        }
    }

    return dp[n][m];
}

int main(){

    string s1 = "ab*cd";
    string s2 = "abdefcd";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    cout<<tabulation(s1, s2, dp);
    

    return 0;
}

