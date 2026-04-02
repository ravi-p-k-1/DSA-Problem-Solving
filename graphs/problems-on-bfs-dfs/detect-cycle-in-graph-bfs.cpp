#include<vector>
#include<queue>
#include<iostream>

// Detect Cycle in Graph using BFS

using namespace std;

bool BFS(vector<vector<int>> &adj){

    int n = adj.size();

    vector<int> vis(n, 0);

    queue<pair<int, int>> q;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            q.push({i, -1});
            vis[i]=1;
            while(!q.empty()){
                auto item = q.front();
                int node = item.first;
                int parent = item.second;
                q.pop();
                for(auto &v: adj[node]){
                    if(!vis[v]){
                        vis[v]=1;
                        q.push({v, node});
                    }
                    else if(v != parent){
                        return true;
                    }
                }
            }
        }
    }

    return false;

}

int main(){

    vector<vector<int>> adj = {{}, {2}, {1, 3}, {2}};

    cout<<BFS(adj);

    return 0;
}

