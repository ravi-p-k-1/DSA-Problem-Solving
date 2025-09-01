#include<iostream>
#include<vector>

using namespace std;

// Pascal's Triangle

vector<int> rowmaker(int n){
    vector<int> ans;
    
    int num=1;
    ans.push_back(num);

    for(int i=1;i<n;i++){
        num=num*(n-i);
        num=num/i;
        ans.push_back(num);
    }

    return ans;
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;

    for(int i=1; i<=n; i++){
        ans.push_back(rowmaker(i));
    }

    return ans;
}

int main(){

    int n = 6;
    vector<vector<int>> vec = pascalTriangle(n);

    for(auto &i: vec){
        for(auto &j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}