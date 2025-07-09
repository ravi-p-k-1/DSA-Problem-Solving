#include<cmath>
#include<set>
#include<iostream>
using namespace std;

string checkPrime(int n, set<int>& ans){
    int root = sqrt(n);

    for(int i=1; i<=root; i++){
        if(n%i==0){
            ans.insert(i);
            ans.insert(n/i);
        }
    }

    if(ans.size()==2) return "It is Prime";
    else return "It is not a Prime";
}

int main(){

    int n=2;
    set<int> ans;
    cout<<checkPrime(n, ans);

    return 0;
}