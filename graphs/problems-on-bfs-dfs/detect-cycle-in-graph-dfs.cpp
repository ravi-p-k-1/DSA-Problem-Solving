#include<vector>
#include<iostream>

// Detect Cycle in Graph using DFS

using namespace std;

bool DFS(vector<vector<int>> &adj, vector<int> &vis, int node, int parent){
    vis[node]=1;
    for(auto &v: adj[node]){
        if(vis[v]!=1){
            if(DFS(adj, vis, v, node)) return true;
        }
        else if(v!=parent){
            return true;
        }
    }

    return false;
}

int main(){

    int n = 5;

    vector<vector<int>> adj(n, vector<int> (0));

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1);
    adj[1].push_back(4); 

    vector<int> vis(n, 0);

    cout<<DFS(adj, vis, 0, -1);

    return 0;
}

