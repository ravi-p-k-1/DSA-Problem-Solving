#include<iostream>
#include<vector>

using namespace std;

// Count Partitions with Given Difference

int memoization(vector<vector<int>> &dp, vector<int> &vec, int target, int ind){
    if(ind==0){
        if(target==0 && vec[ind]==0) return 2;
        if(target==0 || target==vec[ind]) return 1;
        else return 0;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int notpick = memoization(dp, vec, target, ind-1);
    int pick=0;
    if(vec[ind]<=target){
        pick = memoization(dp, vec, target-vec[ind], ind-1);
    }

    return dp[ind][target] = pick+notpick;
}

int tabulation(vector<vector<int>> &dp, vector<int> &vec, int target){

    int n=vec.size();

    for(int i=0;i<=target;i++){
        if(i==0 && vec[0]==0) dp[0][i]=2;
        if(i==0 || vec[0]==i) dp[0][i]=1;
        else dp[0][i]=0;
    }

    for(int ind=1; ind<n; ind++){
        for(int j=0;j<=target;j++){
            int notpick = dp[ind-1][j];
            int pick=0;
            if(vec[ind]<=j){
                pick = dp[ind-1][j-vec[ind]];
            }
            dp[ind][j] = pick+notpick;
        }
    }

    return dp[n-1][target];
}

int main(){

    vector<int> vec = {5, 2, 6, 4};
    int d=3;
    int n=vec.size();
    int sum=0;

    for(auto &i: vec){
        sum+=i;
    }

    if(sum-d<0 || (sum-d)%2==1) cout<<0;
    else{
        int s2 = (sum-d)/2;
        
        vector<vector<int>> dp(n, vector<int>(s2+1, -1));
    
        // cout<<memoization(dp, vec, s2, n-1);
        cout<<tabulation(dp, vec, s2);
    }

    return 0;
}


