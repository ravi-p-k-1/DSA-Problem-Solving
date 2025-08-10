#include<iostream>
#include<vector>

using namespace std;

// Find the number that appears once, and the other numbers twice

int main(){

    vector<int> vec = {4,1,2,1,2};

    int ans = 0;

    for(auto &i: vec){
        ans = ans^i;
    }

    cout<<ans;

    return 0;
}