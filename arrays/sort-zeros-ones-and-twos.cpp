#include<iostream>
#include<vector>

using namespace std;

// Sort an array of 0s, 1s and 2s, without using inbuilt sort.

int main(){

    vector<int> vec = {2,0,2,1,1,0};

    int n = vec.size();

    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high){
        if(vec[mid]==0){
            swap(vec[low], vec[mid]);
            low++;
            mid++;
        }
        else if(vec[mid]==1){
            mid++;
        }
        else {
            swap(vec[mid], vec[high]);
            high--;
        }
    }

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}