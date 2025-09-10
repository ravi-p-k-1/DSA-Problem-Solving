#include<iostream>
#include<vector>

using namespace std;

// Count Reverse Pairs

void merge(vector<int> &vec, int low, int mid, int high){
    int i=low;
    int j=mid+1;
    vector<int> temp;

    while(i<=mid && j<=high){
        if(vec[i]>vec[j]){
            temp.push_back(vec[j]);
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
        vec[i] = temp[i-low];
    }
}

void countPairs(vector<int> &vec, int low, int mid, int high, int &ans){
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && vec[i]>(2*vec[right])) right++;
        ans+=right-(mid+1);
    }
}

void countReversePairs(vector<int> &vec, int low, int high, int &ans){
    int mid=(low+high)/2;
    if(low<high){
        countReversePairs(vec, low, mid, ans);
        countReversePairs(vec, mid+1,high, ans);
        countPairs(vec, low, mid, high, ans);
        merge(vec, low, mid, high);
    }
}

int main(){

    vector<int> vec = {3,2,1,4};
    int ans=0;
    int n=vec.size();

    countReversePairs(vec, 0, n-1, ans);

    cout<<ans;

    return 0;
}