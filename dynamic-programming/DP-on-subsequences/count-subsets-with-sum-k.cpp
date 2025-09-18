#include<iostream>
#include<vector>

using namespace std;

// Count Subsets with Sum K

int memoization(vector<vector<int>> &dp, vector<int> &vec, int ind, int target){

    if(target==0) return 1;
    if(ind==0){
        if(vec[ind]==target) return 1;
        else return 0;
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

    vector<int> vec = {1, 2, 2, 3};
    int n=vec.size();
    int k=3;

    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    cout<<memoization(dp, vec, n-1, k);

    return 0;
}