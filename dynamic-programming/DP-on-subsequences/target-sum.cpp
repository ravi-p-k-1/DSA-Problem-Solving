#include<iostream>
#include<vector>

using namespace std;

// Target Sum

int memoization(vector<vector<int>> &dp, vector<int> &vec, int target, int ind){

    if(ind==0){
        if(target==0 && vec[ind]==0) return 2;
        else if (target==0 || vec[ind]==target) return 1;
        else return 0;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int notpick = memoization(dp, vec, target, ind-1);
    int pick=0;
    if(target>=vec[ind]) pick = memoization(dp, vec, target-vec[ind], ind-1);

    return dp[ind][target] = pick + notpick;
}

int main(){

    vector<int> vec = {1, 2, 3, 1};
    int target = 3;
    int n=vec.size();
    int sum=0;

    for(auto &i: vec){
        sum+=i;
    }

    if((sum-target%2==1) || (sum<target)){
        cout<<0;
        return 0;
    }

    int d=(sum-target)/2;   

    vector<vector<int>> dp(n, vector<int> (d+1, -1));

    cout<<memoization(dp, vec, d, n-1);

    return 0;
}
