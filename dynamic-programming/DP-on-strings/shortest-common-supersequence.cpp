#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Shortest Common Supersequence

int tabulation(string &s1, string &s2, vector<vector<int>> &dp){
    int n=s1.size();
    int m=s2.size();

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int ans=0;

            if(s1[i-1]==s2[j-1]) ans = 1+dp[i-1][j-1];
            else ans = max(dp[i-1][j], dp[i][j-1]);
            
            dp[i][j] = ans;
        }
    }

    return dp[n][m];
}

int main(){

    string s1 = "mno";
    string s2 = "nop";

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    tabulation(s1, s2, dp);

    int i=n;
    int j=m;

    string ans="";

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            ans+=s2[j-1];
            j--;
        }
        else{
            ans+=s1[i-1];
            i--;
        }
    }

    while(j>0){
        ans+=s2[j-1];
        j--;
    }

    while(i>0){
        ans+=s1[i-1];
        i--;
    }

    reverse(ans.begin(), ans.end());

    cout<<ans;

    return 0;
}


