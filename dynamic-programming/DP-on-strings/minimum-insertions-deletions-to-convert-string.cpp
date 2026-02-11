#include<iostream>
#include<vector>

using namespace std;

// Minimum Insertions/Deletions to Convert String

int tabulation(string &s1, string &s2, vector<vector<int>> &dp){
    int n=s1.size();
    int m=s2.size();

    for(int i=0;i<n;i++){
        if(s1[i]==s2[0]) dp[i][0]=1;
        else dp[i][0] = 0;
    }
    
    for(int i=0;i<m;i++){
        if(s1[0]==s2[i]) dp[0][i]=1;
        else dp[0][i] = 0;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            int ans=0;

            if(s1[i]==s2[j]) ans = 1+dp[i-1][j-1];
            else ans = max(dp[i-1][j], dp[i][j-1]);
            
            dp[i][j] = ans;
        }
    }

    return dp[n-1][m-1];
}

int main(){

    string s1 = "flaw";
    string s2 = "lawn";

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    cout<<n+m-2*tabulation(s1, s2, dp);

    return 0;
}



