#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void recursion(vector<int> &arr, int start, int end){
    if(start<end){
        swap(arr[start], arr[end]);
        recursion(arr, start+1, end-1);
    }
}

void twoPointer(vector<int> &arr, int start, int end){
    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){

    vector<int> arr = {1, 2, 3};
    int n=arr.size();

    // Method 1: using in-built reverse function
    // reverse(arr.begin(), arr.end());

    // Method 2: recursion
    // recursion(arr, 0, n-1);

    // Method 3: 2 pointer
    twoPointer(arr, 0, n-1);

    for(auto i: arr){
        cout<<i<<" ";
    }

    return 0;
}