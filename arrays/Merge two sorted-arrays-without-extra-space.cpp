#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Merge two Sorted Arrays Without Extra Space

int main(){

    vector<int> vec1 = {1, 4, 8, 10};
    vector<int> vec2 = {2, 3, 9};

    int n=vec1.size();
    int m=vec2.size();

    int left=n-1;
    int right=0;

    while(left>=0 && right<=m && vec1[left]>vec2[right]){
        swap(vec1[left], vec2[right]);
        left--;
        right++;
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    for(auto &i: vec1){
        cout<<i<<" ";
    }
    
    for(auto &i: vec2){
        cout<<i<<" ";
    }

    return 0;
}


