#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minInsertToMakeStringPalindrome(string &s, string &rs, vector<vector<int>> &dp, int i, int j){

    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans;

    if(s[i]==rs[j]) ans = 1 + minInsertToMakeStringPalindrome(s, rs, dp, i-1, j-1);
    else ans = max(minInsertToMakeStringPalindrome(s, rs, dp, i, j-1), minInsertToMakeStringPalindrome(s, rs, dp, i-1, j));
    
    return dp[i][j] = ans;

}

int main(){

    string s = "abcaa";
    string rs = s;
    reverse(rs.begin(), rs.end());
    int n=s.size();
    int m=n;

    vector<vector<int>> dp(n, vector<int> (m, -1));

    cout<<n-minInsertToMakeStringPalindrome(s, rs, dp, n-1, m-1);

    return 0;
}


