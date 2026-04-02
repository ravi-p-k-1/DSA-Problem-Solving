#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Breadth First Search (BFS): Level Order Traversal

vector<int> BFS(vector<vector<int>> &adj, int start){
    queue<int> q;
    q.push(start);

    int n=adj.size();
    
    vector<int> vis (n, 0);
    vis[start]=1;

    vector<int> ans;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto &i: adj[node]){
            if(vis[i]==1) continue;
            q.push(i);
            vis[i]=1;
        }
    }

    return ans;

}

int main(){

    int n = 5;
    int edges[4][2] = { {0, 1}, {1, 2}, {1, 3}, {0, 4} };
    vector<vector<int>> adj(n);

    for(auto &i: edges){
        int u = i[0];
        int v = i[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = BFS(adj, 0);

    for(auto &i: ans){
        cout<<i<<" ";
    }

    return 0;
}

