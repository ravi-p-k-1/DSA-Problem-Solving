#include<iostream>
#include<vector>

using namespace std;

// Subset sum equal to target

bool memoization(vector<vector<int>> &dp, vector<int> &vec, int ind, int target){

    if(target==0) return true;
    if(ind==0) return vec[ind]==target;

    if(dp[ind][target]!=-1) return dp[ind][target];

    bool nottake = memoization(dp, vec, ind-1, target);
    bool take = false;

    if(vec[ind]<=target){
        take = memoization(dp, vec, ind-1, target-vec[ind]);
    }

    return dp[ind][target] = take || nottake;
}

bool tabulation(vector<vector<int>> &dp, vector<int> &vec, int target){
    int n=vec.size();

    for(int i=0;i<=target;i++){
        dp[0][i]=false;
        if(i==vec[0]) dp[0][i]=true;
    }

    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool nottake = dp[i-1][j];

            bool take=false;
            if(vec[i]<=j){
                take = dp[i-1][j-vec[i]];
            }

            dp[i][j] = take || nottake;
        }
    }

    return dp[n-1][target];
}

int main(){

    vector<int> vec = {1, 2, 3, 4};
    int target = 4;
    int n=vec.size();

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    
    // cout<<memoization(dp, vec, n-1, target);
    cout<<tabulation(dp, vec, target);

    return 0;
}