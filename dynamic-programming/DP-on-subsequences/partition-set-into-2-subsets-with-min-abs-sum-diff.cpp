#include<iostream>
#include<vector>

using namespace std;

// Partition Set Into 2 Subsets With Min Absolute Sum Diff

bool memoization(vector<vector<int>> &dp, vector<int> &vec, int ind, int target){

    if(target==0) return true;
    if(ind==0) return vec[ind]==target;

    if(dp[ind][target]!=-1) return dp[ind][target];

    bool nottake = memoization(dp, vec, ind-1, target);
    bool take=false;
    if(vec[ind]<=target){
        take = memoization(dp, vec, ind-1, target-vec[ind]);
    }

    return dp[ind][target] = take || nottake;
}

bool tabulation(vector<vector<int>> &dp, vector<int> &vec, int target){
    int n=vec.size();

    for(int i=0;i<=target;i++){
        dp[0][i]=0;
        if(vec[0]==i) dp[0][i]=1;
    }

    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<target;j++){
            bool nottake = dp[i-1][j];
            bool take=false;
            if(vec[i]<=j){
                take = dp[i-1][j-vec[i]];
            }

            dp[i][j]=take || nottake;
        }
    }

    return dp[n-1][target];
}

int main(){

    vector<int> vec = {1, 2, 3, 4};
    int n=vec.size();
    int sum=0;

    for(auto &i: vec){
        sum+=i;
    }

    vector<vector<int>> dp (n, vector<int>(sum+1, -1));

    // for(int i=0;i<=sum;i++){
    //     memoization(dp, vec, n-1, i);
    // }

    tabulation(dp, vec, sum);

    int ans=INT_MAX;

    for(int i=0;i<=sum;i++){
        if(dp[n-1][i]) ans = min(ans, abs(sum-2*i));
    }

    cout<<ans;

    return 0;
}
