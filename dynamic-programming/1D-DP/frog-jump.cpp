#include<iostream>
#include<vector>

using namespace std;

// Frog Jump

int tabulation(vector<int> &dp, vector<int> &height, int n){
    dp[0]=0;
    dp[1]=abs(height[0]-height[1]);

    for(int i=2;i<n;i++){
        int last = dp[i-1]+abs(height[i]-height[i-1]);
        int seclast = dp[i-2]+abs(height[i]-height[i-2]);
        dp[i] = min(last, seclast);
    }

    return dp[n-1];
}

int spaceOptimized(vector<int> &height, int n){
    int prev2=0;
    int prev=abs(height[0]-height[1]);

    for(int i=2;i<n;i++){
        int curi=min(prev+abs(height[i]-height[i-1]), prev2+abs(height[i]-height[i-2]));
        prev2=prev;
        prev=curi;
    }

    return prev;

}

int main(){

    int n=4;

    vector<int> dp(n, -1);
    vector<int> height = {10, 20, 30, 10};

    // cout<<tabulation(dp, height, n);
    cout<<spaceOptimized(height, n);

    return 0;
}