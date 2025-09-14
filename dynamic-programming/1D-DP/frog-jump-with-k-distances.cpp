#include<iostream>
#include<vector>

using namespace std;

// Frog Jump with k Distances

int memoization(vector<int> &dp, vector<int> &height, int k, int n){
    
    dp[0]=0;
    dp[1]=abs(height[1]-height[0]);

    for(int i=2;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0) dp[i] = min(dp[i], dp[i-j]+abs(height[i]-height[i-j]));
        }
    }

    return dp[n-1];
}

int main(){

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, INT_MAX);

    cout<<memoization(dp, height, k, n);

    return 0;
}