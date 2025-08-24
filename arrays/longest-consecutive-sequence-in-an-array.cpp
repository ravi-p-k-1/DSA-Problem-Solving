#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// Longest Consecutive Sequence in an Array

int longestConsecutiveSequence(vector<int> &vec){
    int cnt=0;
    int longest=0;
    unordered_set<int> st;

    int n=vec.size();

    for(int i=0; i<n; i++){
        st.insert(vec[i]);
    }

    for(int i=0; i<n; i++){
        if(st.find(vec[i]-1) == st.end()){
            cnt=1;
            int num=vec[i];
            while(st.find(num+1)!=st.end()){
                num++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}

int main(){

    vector<int> vec = {3, 8, 5, 7, 6, 9};

    cout<<longestConsecutiveSequence(vec);

    return 0;
}