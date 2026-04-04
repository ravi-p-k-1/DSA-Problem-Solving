#include<vector>
#include<iostream>

// Surrounded Regions

using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void DFS(vector<vector<char>> &mat, vector<vector<int>> &vis, pair<int, int> cood){

    int n = mat.size();
    int m = mat[0].size();

    int x = cood.first;
    int y = cood.second;
    vis[x][y]=1;

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny] || mat[nx][ny]=='X') continue;

        DFS(mat, vis, {nx, ny});
    }
}

int main(){

    vector<vector<char>> mat = {
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','O','O','X'},
        {'X','X','X','X'}
    };

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && mat[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1)) DFS(mat, vis, {i, j});
        }
    }

    for(auto &i: vis){
        for(auto &j: i){
            if(j) cout<<'O';
            else cout<<'X';
        }
        cout<<endl;
    }

    return 0;
}

