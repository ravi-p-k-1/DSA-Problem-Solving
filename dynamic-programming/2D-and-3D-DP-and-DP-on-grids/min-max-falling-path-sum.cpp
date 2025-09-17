#include<iostream>
#include<vector>

using namespace std;

// Minimum/Maximum Falling Path Sum

int memoization(vector<vector<int>> &dp, vector<vector<int>> &vec, int i, int j){

    if(j<0 || j>=vec[0].size()) return INT_MIN;
    if(i==vec.size()-1) return vec[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int left=0, mid=0, right=0;
    left=memoization(dp, vec, i+1, j-1);
    mid=memoization(dp, vec, i+1, j);
    right=memoization(dp, vec, i+1, j+1);

    return dp[i][j] = vec[i][j] + max(left, max(mid, right));
}

int tabulation(vector<vector<int>> &dp, vector<vector<int>> &vec){
    int n=vec.size();
    int m=vec[0].size();
    int ans=INT_MIN;

    for(int i=0;i<m;i++){
        dp[n-1][i]=vec[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            int left=INT_MIN, mid=INT_MIN, right=INT_MIN;
            if(j-1>=0) left=dp[i+1][j-1];
            mid=dp[i+1][j];
            if(j+1<m) right=dp[i+1][j+1];
            dp[i][j] = vec[i][j] + max(left, max(mid, right));
        }
    }

    for(int i=0;i<m;i++){
        ans = max(ans, dp[0][i]);
    }

    return ans;
}

int main(){

    vector<vector<int>> vec = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };

    
    int n=vec.size();
    int m=vec[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans=INT_MIN;

    // Method 1: Memoization
    // for(int i=0;i<m;i++) ans = max(ans, memoization(dp, vec, 0, i));
    // cout<<ans;

    // Method 2: Tabulation
    cout<< tabulation(dp, vec);


    return 0;
}