#include<vector>
#include<iostream>

using namespace std;

// Number of Provinces

void DFS(int node, vector<vector<int>> &adj, vector<int> &vis){
    vis[node] = 1;
    for(auto &i: adj[node]){
        if(!vis[i]) DFS(i, adj, vis);
    }
}

int main(){

    vector<vector<int>> adjMat = { 
        {1, 0, 0, 1}, 
        {0, 1, 1, 0}, 
        {0, 1, 1, 0}, 
        {1, 0, 0, 1} 
    };

    int n=adjMat.size();

    vector<vector<int>> adj(n, vector<int> (0));

    for(int i=0; i<n; i++){
        int u = i;
        for(int j=0; j<n; j++){
            int v = j;
            if(adjMat[u][v] && u!=v) adj[u].push_back(v);
        }
    }

    vector<int> vis(n, 0);
    int ans=0;

    for(int i=0; i<n; i++){
        if(vis[i]!=1){
            DFS(i, adj, vis);
            ans++;
        }
    }

    cout<<ans;

    return 0;
}


