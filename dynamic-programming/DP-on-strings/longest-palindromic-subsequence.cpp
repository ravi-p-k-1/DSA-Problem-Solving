#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Longest Palindromic Subsequence

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

    string s = "eeeme";
    string rs = s;
    reverse(rs.begin(), rs.end());

    int n = s.size();

    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

    cout<<tabulation(s, rs, dp)<<endl;

    return 0;
}

