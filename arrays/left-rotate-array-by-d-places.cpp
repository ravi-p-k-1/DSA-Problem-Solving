#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Left rotate the array by D places

int main(){

    int d=2;
    vector<int> vec={1, 2, 3, 4, 5, 6, 7};

    int n=vec.size();
    d%=n;

    reverse(vec.begin(), vec.begin()+d);
    reverse(vec.begin()+d, vec.end());
    reverse(vec.begin(), vec.end());

    for(auto &i: vec){
        cout<<i<<" ";
    }

    return 0;
}

