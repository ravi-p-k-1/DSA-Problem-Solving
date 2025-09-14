#include<iostream>
#include<vector>

using namespace std;

// Ninja's Training

int memoization(vector<vector<int>> &dp, vector<vector<int>> &vec, int ind, int last){
    if(dp[ind][last]!=-1) return dp[ind][last];
    
    int maxi=INT_MIN;
    
    if(ind==0){
        for(int i=1;i<=3;i++){
            if(i!=last){
                maxi=max(maxi, vec[ind][i]);
            }
        }
    }
    else{
        for(int i=1;i<=3;i++){
            if(i!=last){
                maxi=max(maxi, vec[ind][i] + memoization(dp, vec, ind-1, i));
            }
        }
    }
    
    return dp[ind][last] = maxi;
}

int tabulation(vector<vector<int>> &dp, vector<vector<int>> &vec){
    int n=vec.size();
    
    dp[0][0]=max(vec[0][1], max(vec[0][2], vec[0][3]));
    dp[0][1]=max(vec[0][2], vec[0][3]);
    dp[0][2]=max(vec[0][1], vec[0][3]);
    dp[0][3]=max(vec[0][1], vec[0][2]);

    for(int ind=1;ind<n;ind++){
        for(int last=0;last<=3;last++){
            int maxi=INT_MIN;
            for(int i=1;i<=3;i++){
                if(i!=last){
                    maxi=max(maxi, vec[ind][i] + dp[ind-1][i]);
                }
            }
            dp[ind][last]=maxi;
        }
    }

    return dp[n-1][0];
}

int spaceOptimized(vector<vector<int>> &vec){
    int n=vec.size();
    vector<int> prev(vec[0].size()+1, -1), curr(vec[0].size()+1, -1);
    
    prev[0]=max(vec[0][1], max(vec[0][2], vec[0][3]));
    prev[1]=max(vec[0][2], vec[0][3]);
    prev[2]=max(vec[0][1], vec[0][3]);
    prev[3]=max(vec[0][1], vec[0][2]);

    for(int ind=1;ind<n;ind++){
        for(int last=0;last<=3;last++){
            int maxi=INT_MIN;
            for(int i=1;i<=3;i++){
                if(i!=last){
                    maxi=max(maxi, vec[ind][i] + prev[i]);
                }
            }
            curr[last]=maxi;
        }
        prev=curr;
    }

    return prev[0];
}

int main(){

    vector<vector<int>> vec = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n=vec.size();

    vector<vector<int>> dp(n, vector<int> (4, -1));

    // cout<<memoization(dp, vec, n-1, 0);
    // cout<<tabulation(dp, vec);
    cout<<spaceOptimized(vec);

    return 0;
}