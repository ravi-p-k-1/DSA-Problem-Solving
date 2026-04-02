#include<vector>
#include<queue>
#include<iostream>

using namespace std;

// Connected Components

int BFS(vector<vector<int>> &adj, vector<int> &vis){
    int n=adj.size();
    int ans=0;

    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i]=1;
        ans++;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &v: adj[node]){
                if(vis[v]) continue;
                q.push(v);
                vis[v]=1;
            }
        }
    }

    return ans;
}

int main(){

    vector<vector<int>> edges = { 
        {0, 1}, 
        {1, 2}, 
        {2, 3}, 
        {4, 5} 
    };

    int n=7;

    vector<vector<int>> adj(n, vector<int> (0));

    for(auto &i: edges){
        int u = i[0];
        int v = i[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);

    cout<<BFS(adj, vis);

    return 0;
}


