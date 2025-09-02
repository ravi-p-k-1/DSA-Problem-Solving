#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 4 Sum | Find Quads that add up to a target value

int main(){

    vector<int> vec = {4,3,3,4,4,2,1,2,1,1};
    vector<vector<int>> ans;
    int target=9;
    int n=vec.size();
    sort(vec.begin(), vec.end());

    for(int i=0;i<n;i++){
        if(i!=0 && vec[i-1]==vec[i]) continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && vec[j-1]==vec[j]) continue;
            int k=j+1;
            int l=n-1;

            while(k<l){
                int sum = vec[i]+vec[j]+vec[k]+vec[l];
                if(sum<target) k++;
                else if(sum>target) l--;
                else{
                    ans.push_back({vec[i], vec[j], vec[k], vec[l]});
                    k++;
                    l--;
                    while(k<l && vec[k-1]==vec[k]) k++;
                    while(k<l && vec[l+1]==vec[l]) l--;
                }
            }
        }
    }

    for(auto &i: ans){
        for(auto &j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}