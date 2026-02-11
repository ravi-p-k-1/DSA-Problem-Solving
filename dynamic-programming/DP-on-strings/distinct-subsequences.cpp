#include<iostream>
#include<vector>

using namespace std;

// Distinct Subsequences

int memoization(string &s, string &t, vector<vector<int>> &dp, int i, int j){
    if(j==-1) return 1;
    if(i==-1) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        dp[i][j] = memoization(s, t, dp, i-1, j-1) + memoization(s, t, dp, i-1, j);
    }
    else{
        dp[i][j] = memoization(s, t, dp, i-1, j);
    }

    return dp[i][j];

}

int main(){

    string s = "babgbag";
    string t = "bag";

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    cout<<memoization(s, t, dp, n-1, m-1);

    return 0;
}


