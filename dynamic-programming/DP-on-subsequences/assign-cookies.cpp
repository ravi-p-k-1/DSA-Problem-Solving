#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Assign Cookies

int memoization(vector<vector<int>> &dp, vector<int> &child, vector<int> &cookie, int i, int j){

    if(i>=child.size() || j>=cookie.size()) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];

    int nottake = memoization(dp, child, cookie, i, j+1);
    int take = 0;
    if(child[i]<=cookie[j]) take = 1 + memoization(dp, child, cookie, i+1, j+1);

    return dp[i][j] = max(take, nottake);
}

int tabulation(vector<vector<int>> &dp, vector<int> &child, vector<int> &cookie){
    int n=child.size();
    int m=cookie.size();

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            int nottake = dp[i][j+1];
            int take = 0;
            if(child[i]<=cookie[j]) take = 1 + dp[i+1][j+1];
            dp[i][j] = max(take, nottake);
        }
    }

    return dp[0][0];
}

int main(){

    vector<int> child = {3, 4, 2};
    vector<int> cookie = {1, 2, 3};

    int n=child.size();
    int m=cookie.size();

    sort(child.begin(), child.end());
    sort(cookie.begin(), cookie.end());

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout<<memoization(dp, child, cookie, 0, 0);

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    cout<<tabulation(dp, child, cookie);

    return 0;
}
