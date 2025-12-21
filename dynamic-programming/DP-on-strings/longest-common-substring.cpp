#include<iostream>
#include<vector>

using namespace std;

// Longest Common Substring

int tabulation(string &s1, string &s2, vector<vector<int>> &dp){

    int n=s1.size();
    int m=s2.size();

    int ans=0;

    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }

    return ans;

}

int main(){

    string s1 = "abcdxyz";
    string s2 = "xyzabcd";

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    cout<<tabulation(s1, s2, dp);

    return 0;
}

