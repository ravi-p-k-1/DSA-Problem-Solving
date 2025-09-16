#include<iostream>
#include<vector>

using namespace std;

// Minimum path sum in Triangular Grid

int memoization(vector<vector<int>> &dp, vector<vector<int>> &vec, int &n, int i, int j){
    if(i==n-1) return vec[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = vec[i][j] + min(memoization(dp, vec, n, i+1, j), memoization(dp, vec, n, i+1, j+1));
}


int tabulation(vector<vector<int>> &dp, vector<vector<int>> &vec, int &n){

    for(int i=0;i<n;i++){
        dp[n-1][i]=vec[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j] = vec[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    return dp[0][0];
}

int spaceOptimized(vector<vector<int>> &vec, int &n){

    vector<int> prev(n, -1);

    for(int i=0;i<n;i++){
        prev[i]=vec[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        vector<int> curr(i+1, -1);
        for(int j=0;j<=i;j++){
            curr[j] = vec[i][j] + min(prev[j], prev[j+1]);
        }
        prev=curr;
    }

    return prev[0];
}

int main(){

    vector<vector<int>> vec = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };

    int n=vec.size();

    vector<vector<int>> dp(n, vector<int> (n ,-1));

    // cout<<memoization(dp, vec, n, 0, 0);
    // cout<<tabulation(dp, vec, n);
    cout<<spaceOptimized(vec, n);

    return 0;
}