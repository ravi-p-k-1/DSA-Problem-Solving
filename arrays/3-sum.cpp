#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 3 Sum : Find triplets that add up to a zero

int main(){

    vector<int> vec = {-1,0,1,0};
    sort(vec.begin(), vec.end());
    vector<vector<int>> ans;

    int n = vec.size();
    
    for(int i=0;i<n;i++){
        if(i!=0 && vec[i]==vec[i-1]) continue;
        int j=i+1;
        int k=n-1;

        while (j<k){
            int sum=vec[j]+vec[k]+vec[i];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                ans.push_back({vec[i], vec[j], vec[k]});
                j++;
                k--;
                while(j<k && vec[j-1]==vec[j]) j++;
                while(j<k && vec[k+1]==vec[k]) k--;
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