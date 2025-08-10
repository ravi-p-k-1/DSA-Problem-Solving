#include<iostream>
#include<vector>

using namespace std;

// Find the missing number in the array containing numbers from 1-N, the array size is N-1

int main(){

    vector<int> vec={1, 2, 3, 4, 5, 7, 8, 9};
    int n=9;

    int sum=n*(n+1)/2;

    for(auto &i: vec){
        sum-=i;
    }

    cout<<sum;

    return 0;
}