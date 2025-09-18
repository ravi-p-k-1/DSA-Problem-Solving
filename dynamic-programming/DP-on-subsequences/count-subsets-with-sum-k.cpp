#include<iostream>
#include<vector>

using namespace std;

// Count Subsets with Sum K

int memoization(vector<vector<int>> &dp, vector<int> &vec, int ind, int target){
    if(ind==0){
        if(target==0 && vec[0]==0) return 2;
        if(target==0 || vec[ind]==target) return 1;
        return 0;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int nottake = memoization(dp, vec, ind-1, target);
    int take=0;
    if(vec[ind]<=target){
        take = memoization(dp, vec, ind-1, target-vec[ind]);
    }

    return dp[ind][target] = take + nottake;
}

int main(){

    vector<int> vec = {0, 0, 1};
    int n=vec.size();
    int k=1;

    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    cout<<memoization(dp, vec, n-1, k);

    return 0;
}