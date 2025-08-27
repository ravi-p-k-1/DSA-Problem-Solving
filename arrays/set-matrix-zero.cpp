#include<iostream>
#include<vector>

using namespace std;

// Set Matrix Zero

void setMatZero(vector<vector<int>> &vec){

    int n=vec.size();
    int m = vec[0].size();

    int col0=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vec[i][j]==0){
                vec[i][0] = 0;
                if(j!=0) vec[0][j]=0;
                else col0=0; 
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(vec[i][0]==0 || vec[0][j]==0) vec[i][j]=0;
        }
    }

    if(vec[0][0]==0){
        for(int j=0;j<m;j++){
            vec[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            vec[i][0]=0;
        }
    }

}

int main(){

    vector<vector<int>> vec = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};

    setMatZero(vec);

    for(auto &i: vec){
        for(auto &j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}