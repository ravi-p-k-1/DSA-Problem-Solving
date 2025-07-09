#include<cmath>
#include<iostream>
#include <set>
using namespace std;

void printDivisors(int n, set<int>& ans){
    int root = sqrt(n);

    for(int i=1;i<=root;i++){
        if(n%i==0){
            ans.insert(i);
            ans.insert(n/i);
        }
    }

    return;
}

int main(){

    int n=4;
    set<int> ans;
    printDivisors(n, ans);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}