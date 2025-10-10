#include<iostream>
#include<vector>

using namespace std;

// Rod Cutting Problem

int memoization(vector<vector<int>> &dp, vector<int> &price, int len, int ind){

    if(ind == 0) return price[ind]*len;

    if(dp[ind][len]!=-1) return dp[ind][len];

    int notpick = memoization(dp, price, len, ind-1);
    int pick=0;
    if(len>=(ind+1)) pick = price[ind] + memoization(dp, price, len-(ind+1), ind);

    return dp[ind][len] = max(notpick, pick);
}

int main(){

    vector<int> price = {2, 5, 7, 8, 10};
    int len = 5;

    int n=price.size();

    vector<vector<int>> dp(n, vector<int> (len+1, -1));

    cout<<memoization(dp, price, len, n-1);


    return 0;
}