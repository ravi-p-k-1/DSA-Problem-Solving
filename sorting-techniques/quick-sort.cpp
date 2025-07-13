#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &vec, int low, int high){
    swap(vec[(low+high)/2], vec[low]);

    int pivot=low;

    int i=low;
    int j=high;

    while(i<j){
        while(vec[i]<=vec[pivot] && i<high){
            i++;
        }

        while(vec[j]>vec[pivot] && j>low){
            j--;
        }

        if(i<j) swap(vec[i], vec[j]);
    }

    swap(vec[pivot], vec[j]);

    return j;

}

void quickSort(vector<int> &vec, int low, int high){
    if(low>=high) return;

    int pindex = partition(vec, low, high);

    quickSort(vec, low, pindex-1);

    quickSort(vec, pindex+1, high);
}

int main(){

    vector<int> vec = {4,6,2,5,7,9,1,3};

    int n = vec.size();

    quickSort(vec, 0, n-1);

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}