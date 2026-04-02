#include<vector>
#include<queue>
#include<iostream>

// Rotten Oranges

using namespace std;

int BFS(vector<vector<int>> &grid, queue<pair<int, int>> &q){
    int n = grid.size();
    int m = grid[0].size();

    int mins=0;
    int total=0;
    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0) total++;
            if(grid[i][j]==2) q.push({i, j});
        }
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while(!q.empty()){
        int k = q.size();

        cnt+=k;

        while(k--){
            auto item = q.front();
            q.pop();
            int x = item.first;
            int y = item.second;

            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1) continue;
                grid[nx][ny]=2;
                q.push({nx, ny});
            }
        }

        if(!q.empty()) mins++;
    }

    return total==cnt? mins : -1;
}

int main(){

    vector<vector<int>> grid = { 
        {2, 1, 1} , 
        {1, 1, 0} , 
        {0, 1, 1} 
    };

    queue<pair<int, int>> q;

    cout<<BFS(grid, q);

    return 0;
}
