#include<iostream>
#include<vector>

using namespace std;

// Count maximum consecutive 1s in an array.

int main(){

    vector<int> vec = {1, 1, 0, 1, 1, 1};
    int ans=0;
    int cnt=0;

    for(auto &i: vec){
        if(i==1) cnt++;
        else {
            ans=max(ans, cnt);
            cnt=0;
        }
    }

    ans=max(ans, cnt);

    cout<<ans;

    return 0;
}