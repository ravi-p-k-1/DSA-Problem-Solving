#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Rotate Matrix by 90 degree

void rotateMatrix(vector<vector<int>> &vec){
    int n = vec.size();
    int m=vec[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(vec[i][j], vec[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(vec[i].begin(), vec[i].end());
    }
}

int main(){

    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotateMatrix(vec);

    for(auto &i: vec){
        for(auto &j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}