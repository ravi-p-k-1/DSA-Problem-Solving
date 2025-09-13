#include<iostream>
#include<vector>

using namespace std;

// Climbing Stairs

int memoization(vector<int> &dp, int ind){
    if(dp[ind]!=-1) return dp[ind];
    return dp[ind] = memoization(dp, ind-1) + memoization(dp, ind-2);
}

void tabulation(vector<int> &dp, int n){
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
}

int spaceOptimized(int n){
    int prev=1;
    int prev2=1;

    for(int i=2;i<=n;i++){
        int curi=prev+prev2;
        prev2=prev;
        prev=curi;
    }

    return prev;
}

int main(){

    int n=3;

    vector<int> dp(n+1, -1);

    dp[0]=1;
    dp[1]=1;

    // memoization(dp, n);
    tabulation(dp, n);
    // cout<<spaceOptimized(n);

    cout<<dp[n];

    return 0;
}