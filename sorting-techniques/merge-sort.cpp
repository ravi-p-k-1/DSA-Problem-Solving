#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &vec, int low, int mid, int high){

    vector<int> temp;

    int i=low;
    int j=mid+1;

    while(i<=mid && j<=high){
        if(vec[i]<vec[j]){
            temp.push_back(vec[i]);
            i++;
        }
        else{
            temp.push_back(vec[j]);
            j++;
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

    for(int i=0; i<temp.size(); i++){
        vec[low+i] = temp[i];
    }
}

void mergeSort(vector<int> &vec, int low, int high){
    if(low>=high) return;

    int mid = (low+high)/2;

    mergeSort(vec, low, mid);
    
    mergeSort(vec, mid+1, high);

    merge(vec, low, mid, high);
}

int main(){

    vector<int> vec = {3,2,8,5,1,4,23};

    int n = vec.size();

    mergeSort(vec, 0, n-1);

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}