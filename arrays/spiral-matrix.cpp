#include<iostream>
#include<vector>

using namespace std;

// Spiral Matrix

void spiralTraversal(vector<vector<int>> &vec){
    int n=vec.size();
    int m=vec[0].size();

    int top=0;
    int bottom=n-1;
    int right=m-1;
    int left=0;

    while(top<=bottom && left<=right){
        for(int i=left; i<=right; i++){
            cout<<vec[top][i]<<" ";
        }
        top++;
        for(int i=top; i<=bottom; i++){
            cout<<vec[i][right]<<" ";
        }
        right--;
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                cout<<vec[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom; i>=top;i--){
                cout<<vec[i][left]<<" ";
            }
            left++;
        }
    }
}

int main(){

    vector<vector<int>> vec = { 
        { 1, 2, 3},
		{ 5, 6, 7},
		{ 9, 10, 11},
	    { 13, 14, 15 }
    };

    spiralTraversal(vec);

    return 0;
}