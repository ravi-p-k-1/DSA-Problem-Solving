#include<iostream>
#include<vector>

using namespace std;

// Leaders in an Array

void printLeadersInAnArray(vector<int> &vec){
    
    int n = vec.size();

    int maxi = INT_MIN;

    for(int i=n-1; i>=0; i--){
        if(maxi<vec[i]){
            maxi=vec[i];
            cout<<vec[i]<<" ";
        }
    }

    return;

}

int main(){

    vector<int> vec = {4, 7, 1, 0};

    printLeadersInAnArray(vec);

    return 0;
}