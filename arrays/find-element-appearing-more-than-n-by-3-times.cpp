#include<iostream>
#include<vector>

using namespace std;

// Find the elements that appears more than N/3 times in the array

int main(){

    vector<int> vec = {11,33,33,11,33,11};
    int n=vec.size();
    int cnt1=0;
    int cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;

    for(int i=0;i<n;i++){
        if(cnt1==0 && vec[i]!=el2){
            el1=vec[i];
            cnt1++;
        }
        else if(cnt2==0 && vec[i]!=el1){
            el2=vec[i];
            cnt2++;
        }
        else if(vec[i]==el1) cnt1++;
        else if(vec[i]==el2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;

    int mini = n/3 + 1;
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(vec[i]==el1) cnt1++;
        else if(vec[i]==el2) cnt2++;
    }

    if(cnt1>=mini) ans.push_back(el1);
    if(cnt2>=mini) ans.push_back(el2);

    for(auto &i: ans) cout<<i<<" ";

    return 0;
}