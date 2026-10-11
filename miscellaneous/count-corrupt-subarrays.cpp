#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

/*
Title: Count Corrupt Subarrays

Problem Statement:  Count the number of corrupt subarrays where corrupt is all of its 
                    elements bitwise OR resulting in an element that is present in the whole array
                    
                    Note: a subarray with 1 element is always corrupt.

Example:
[1, 2, 3]: all 6 subarrays are corrupt. [1,2], [2,3] and [1,2,3] all OR to 3, which is in the array.
[1, 2, 4]: only the 3 single-element subarrays are corrupt. The ORs 3, 6 and 7 aren’t in the array.
*/

long long countCorrupt(vector<int> &vec){
    unordered_set<int> st(vec.begin(), vec.end());
    vector<pair<int, long long>> cur, nxt;

    long long ans=0;

    for(auto &i: vec){
        nxt.clear();
        nxt.push_back({i, 1});

        for(auto &j: cur){
            int v = j.first;
            int c = j.second;

            int nv = v | i;
            if(nxt.back().first == nv) nxt.back().second += c;
            else nxt.push_back({nv, c});
        }

        swap(cur, nxt);

        for(auto &j: cur){
            int v = j.first;
            int c = j.second;

            if(st.count(v)) ans+=c;
        }
    }

    return ans;
}

int main(){

    vector<int> vec = {1, 2, 4};

    cout<<countCorrupt(vec);

    return 0;
}

