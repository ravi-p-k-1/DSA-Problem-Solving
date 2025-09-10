#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Find the repeating and missing numbers

int main(){

    vector<int> vec = {3, 1, 2, 5, 4, 6, 7, 5};

    int xr = 0;
    int n = vec.size();

    for(int i=0;i<n;i++){
        xr = xr^vec[i];
        xr=xr^(i+1);
    }

    int num = xr & ~(xr-1);
    int one=0;
    int zero=0;

    for(auto &i: vec){
        if((num & i) !=0) one = one ^ i;
        else zero = zero ^ i;
    }
    
    for(int i=1;i<=n;i++){
        if((num & i) !=0) one = one ^ i;
        else zero = zero ^ i;
    }

    cout<<one<<" "<<zero;

    return 0;
}