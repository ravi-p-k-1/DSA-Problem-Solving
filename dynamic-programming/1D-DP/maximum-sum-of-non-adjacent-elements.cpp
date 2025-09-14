#include<iostream>
#include<vector>

using namespace std;

// Maximum sum of non-adjacent elements

int memoization(vector<int> &dp ,vector<int> &vec, int &n, int ind){
    if(ind==0) return vec[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick = vec[ind]+memoization(dp, vec, n, ind-2);
    int notpick = memoization(dp, vec, n, ind-1);
    return dp[ind]=max(pick, notpick);
}

int tabulation(vector<int> &dp, vector<int> &vec, int &n){
    dp[0]=vec[0];
    
    for(int i=1; i<n; i++){
        int pick = vec[i];
        if(i>1) pick += dp[i-2];
        int notpick = dp[i-1];
        dp[i]=max(pick, notpick);
    }

    return dp[n-1];

}

int spaceOptimized(vector<int> &vec, int &n){
    int prev2=0;
    int prev=vec[0];

    for(int i=1;i<n;i++){
        int pick=vec[i];
        if(i>1) pick+=prev2;
        int notpick = prev;
        int curi=max(pick, notpick);
        prev2=prev;
        prev=curi;
    }

    return prev;
}

int main(){

    int n=9;
    vector<int> vec = {1,2,3,1,3,5,8,1,9};
    vector<int> dp(n, -1);

    // cout<<memoization(dp, vec, n, n-1);
    // cout<<tabulation(dp, vec, n);
    cout<<spaceOptimized(vec, n);

    return 0;
}

