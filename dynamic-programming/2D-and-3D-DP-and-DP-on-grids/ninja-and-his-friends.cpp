#include<iostream>
#include<vector>

using namespace std;

// Ninja and his friends

int memoization(vector<vector<vector<int>>> &dp, vector<vector<int>> &vec, int ind, int i, int j){
    int n=vec.size();
    int m=vec[0].size();

    if(i<0 || j<0 || i>=m || j>=m) return INT_MIN;
    if(ind==n-1){
        if(i==j) return vec[ind][i];
        else return vec[ind][i]+vec[ind][j];
    }

    if(dp[ind][i][j]!=-1) return dp[ind][i][j];

    int maxi=INT_MIN;

    for(int i1=-1;i1<=1;i1++){
        for(int i2=-1;i2<=1;i2++){
            int temp = memoization(dp, vec, ind+1, i+i1, j+i2);
            if(i==j) temp += vec[ind][i];
            else temp += vec[ind][i]+vec[ind][j];
            maxi = max(maxi, temp);
        }
    }

    return dp[ind][i][j] = maxi;
}

int tabulation(vector<vector<vector<int>>> &dp, vector<vector<int>> &vec){
    int n=vec.size();
    int m=vec[0].size();

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j) dp[n-1][i][j] = vec[n-1][i];
            else dp[n-1][i][j] = vec[n-1][i] + vec[n-1][j];
        }
    }

    for(int ind=n-2;ind>=0;ind--){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                int maxi=INT_MIN;
                for(int i1=-1;i1<=1;i1++){
                    for(int i2=-1;i2<=1;i2++){
                        int temp=INT_MIN;
                        if(!(i+i1<0 || i+i1>=m || j+i2<0 || j+i2>=m)) temp = dp[ind+1][i+i1][j+i2];
                        if(i==j) temp += vec[ind][i];
                        else temp += vec[ind][i]+vec[ind][j];
                        maxi = max(maxi, temp);
                    }
                }
                dp[ind][i][j] = maxi;
            }
        }
    }

    return dp[0][0][m-1];
}

int main(){

    vector<vector<int>> vec = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n=vec.size();
    int m=vec[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m, -1)));

    // cout<<memoization(dp, vec, 0, 0, m-1);
    cout<<tabulation(dp, vec);

    return 0;
}