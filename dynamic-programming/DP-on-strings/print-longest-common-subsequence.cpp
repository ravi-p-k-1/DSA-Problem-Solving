#include<iostream>
#include<vector>

using namespace std;

// Print Longest Common Subsequence

int memoization(string &s1, string &s2, vector<vector<int>> &dp, int i, int j){
    if(i<1 || j<1) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int val;

    if(s1[i-1]==s2[j-1]){
        val=1+memoization(s1, s2, dp, i-1, j-1);
    }
    else{
        val = max(memoization(s1, s2, dp, i-1, j), memoization(s1, s2, dp, i, j-1));
    }

    return dp[i][j] = val;
}

int main(){

    string s1 = "apple";
    string s2 = "waffle";

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

    memoization(s1, s2, dp, n, m);

    string ans="";

    int i=n;
    int j=m;

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans = s1[i-1] + ans;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>=dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    cout<<ans;

    return 0;
}

