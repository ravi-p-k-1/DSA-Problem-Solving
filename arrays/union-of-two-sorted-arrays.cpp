#include<iostream>
#include<vector>

using namespace std;

// Union of 2 sorted arrays

vector<int> arrayUnion(vector<int> &vec1, vector<int> &vec2){
    int i=0;
    int j=0;
    int n=vec1.size();
    int m=vec2.size();
    vector<int> ans;

    while(i<n && j<m){
        if(vec1[i]<=vec2[j]){
            if(ans.size()==0 || ans.back()!=vec1[i]) ans.push_back(vec1[i]);
            i++;
        }
        else{
            if(ans.size()==0 || ans.back()!=vec2[j]) ans.push_back(vec2[j]);
            j++;
        }
    }

    return ans;
}

int main(){

    vector<int> vec1 = {1,2,3,4,5};
    vector<int> vec2 = {2,3,4,4,5};

    vector<int> ans = arrayUnion(vec1, vec2);

    for(auto &i: ans){
        cout<<i<<" ";
    }

    return 0;
}