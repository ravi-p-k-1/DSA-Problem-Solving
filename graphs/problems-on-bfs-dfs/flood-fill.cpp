#include<vector>
#include<queue>
#include<iostream>

// Flood Fill

using namespace std;

void BFS(vector<vector<int>> &image, queue<pair<int, int>> &q, int sr, int sc, int color){
    q.push({sr, sc});
    int originalColor = image[sr][sc];
    image[sr][sc] = color;

    if(originalColor == color) return;

    int n = image.size();
    int m = image[0].size();

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while(!q.empty()){
        auto item = q.front();
        int x = item.first;
        int y = item.second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m || image[nx][ny] != originalColor) continue;

            q.push({nx, ny});
            image[nx][ny] = color;
        }
    }
}

int main(){

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};

    int n = image.size();
    int m = image.size();

    int sr = 1;
    int sc = 1;
    int color = 2;

    queue<pair<int, int>> q;

    BFS(image, q, sr, sc, color);

    for(auto &i: image){
        for(auto &j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
