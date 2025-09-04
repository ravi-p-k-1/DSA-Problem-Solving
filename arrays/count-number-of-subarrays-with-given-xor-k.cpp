#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Count number of subarrays with given xor K

int main(){

    vector<int> vec = {4, 2, 2, 6, 4};
    int k=6;
    int xornum=0;
    int n=vec.size();
    int ans=0;
    map<int, int> mpp;
    mpp[0]=1;

    for(int i=0;i<n;i++){
        xornum=xornum^vec[i];
        if(mpp.find(xornum^k)!=mpp.end()) ans+=mpp[xornum^k];
        mpp[xornum]++;
    }

    cout<<ans;

    return 0;
}



