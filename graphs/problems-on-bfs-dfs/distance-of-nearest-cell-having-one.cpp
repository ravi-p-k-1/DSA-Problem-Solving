#include<vector>
#include<queue>
#include<iostream>

// Distance of Nearest Cell having 1

using namespace std;

vector<vector<int>> BFS(vector<vector<int>> &grid){
    int n=grid.size();
    int m=grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> dist(n, vector<int> (m, 0));
    vector<vector<int>> vis(n, vector<int> (m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                q.push({{i, j}, 0});
                vis[i][j]=1;
            }
        }
    }

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while(!q.empty()){
        auto item = q.front();
        int x = item.first.first;
        int y = item.first.second;
        int d = item.second;
        q.pop();

        dist[x][y]=d;

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny]==1) continue;

            q.push({{nx, ny}, d+1});
            vis[nx][ny]=1;
        }
    }

    return dist;
}

int main(){

    vector<vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {1,0,1}
    };

    vector<vector<int>> ans = BFS(grid);

    for(auto &i: ans){
        for(auto &j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}

