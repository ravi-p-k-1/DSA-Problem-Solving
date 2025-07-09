#include<iostream>
using namespace std;

int findGCD(int n, int m){
    if(n==0) return m;
    if(m==0) return n;

    if(m-n<=n) return findGCD(m-n, n);
    else return findGCD(n, m-n);
}

int main(){
    int n=14;
    int m=28;

    if(n<=m) cout<<findGCD(n, m);
    else cout<<findGCD(m, n);

    return 0;
}