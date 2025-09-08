#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Merge Overlapping Sub-intervals

bool comparator(vector<int> &a, vector<int> &b){
    return a[0]<b[0];
}

void mergeOverlapIntervals(vector<vector<int>> &vec, vector<vector<int>> &ans){

    sort(vec.begin(), vec.end(), comparator);
    int n=vec.size();

    for(int i=0;i<n;i++){
        if(!ans.empty() && ans.back()[1]>=vec[i][0]){
            ans.back()[1] = max(ans.back()[1], vec[i][1]);
        }
        else{
            ans.push_back(vec[i]);
        }
    }

}

int main(){

    vector<vector<int>> vec = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};

    vector<vector<int>> ans;

    mergeOverlapIntervals(vec, ans);

    for(auto &i: ans){
        for(auto &j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}



