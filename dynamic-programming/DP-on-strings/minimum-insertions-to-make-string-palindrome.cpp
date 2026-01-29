#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Minimum insertions to make string palindrome

int minInsertToMakeStringPalindrome(string &s, string &rs, vector<vector<int>> &dp, int i, int j){

    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans;

    if(s[i]==rs[j]) ans = 1 + minInsertToMakeStringPalindrome(s, rs, dp, i-1, j-1);
    else ans = max(minInsertToMakeStringPalindrome(s, rs, dp, i, j-1), minInsertToMakeStringPalindrome(s, rs, dp, i-1, j));
    
    return dp[i][j] = ans;

}

int tabulation(string &s, string &rs, vector<vector<int>> &dp){
    
    int n=s.size();
    int m=n;

    for(int i=0;i<n;i++){
        if(s[i]==rs[0]) dp[i][0]=1;
        else dp[i][0]=0;
        
        if(rs[i]==s[0]) dp[0][i]=1;
        else dp[0][i]=0;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            int ans;
            if(s[i]==rs[j]) ans = 1+dp[i-1][j-1];
            else ans = max(dp[i][j-1], dp[i-1][j]);
            dp[i][j]=ans;
        }
    }

    // length of string - length of longest palindromic subsequence = minimum insertions to make string palindrome
    return n-dp[n-1][m-1];
}

int main(){

    string s = "abcaa";
    string rs = s;
    reverse(rs.begin(), rs.end());
    int n=s.size();
    int m=n;

    vector<vector<int>> dp(n, vector<int> (m, -1));
    
    // length of string - length of longest palindromic subsequence = minimum insertions to make string palindrome
    // cout<<n-minInsertToMakeStringPalindrome(s, rs, dp, n-1, m-1);
    cout<<tabulation(s, rs, dp);

    return 0;
}


