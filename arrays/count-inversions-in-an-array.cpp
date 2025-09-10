#include<iostream>
#include<vector>

using namespace std;

// Count inversions in an array

void merge(vector<int> &vec, int low, int mid, int high, int &ans){
    
    int i=low;
    int j=mid+1;
    vector<int> temp;

    while(i<=mid && j<=high){
        if(vec[i]>vec[j]){
            temp.push_back(vec[j]);
            ans+=mid-i+1;
            j++;
        }
        else{
            temp.push_back(vec[i]);
            i++;
        }
    }

    while(i<=mid){
        temp.push_back(vec[i]);
        i++;
    }
    
    while(j<=high){
        temp.push_back(vec[j]);
        j++;
    }

    for(int i=low;i<=high;i++){
        vec[i]=temp[i-low];
    }
}

void countInversions(vector<int> &vec, int low, int high, int &ans){
    int mid = (low+high)/2;
    if(low<high){
        countInversions(vec, low, mid, ans);
        countInversions(vec, mid+1, high, ans);
        merge(vec, low, mid, high, ans);
    }
}

int main(){
    
    vector<int> vec = {5,4,3,2,1};
    int n=vec.size();
    int ans=0;
    countInversions(vec, 0, n-1, ans);

    cout<<ans;

    return 0;
}