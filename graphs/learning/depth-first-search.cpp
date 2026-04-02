#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Depth First Search (DFS)

void DFS(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans){
    vis[node]=1;
    ans.push_back(node);
    
    for(auto &i: adj[node]){
        if(!vis[i]){
            DFS(i, adj, vis, ans);
        }
    }
}

int main(){

    int n = 5;
    vector<vector<int>> adj = {
        {},
        {2, 3},
        {1, 4, 5},
        {1},
        {2, 5},
        {4, 5}
    };

    vector<int> vis(n+1, 0);
    vector<int> ans;
    int startingNode = 1;

    DFS(startingNode, adj, vis, ans);

    for(auto &i: ans){
        cout<<i<<" ";
    }

    return 0;
}

