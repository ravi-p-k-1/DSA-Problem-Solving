#include<cmath>
#include <iostream>

using namespace std;

int countDigits(int n){
    return log10(n)+1;
}

int main(){

    int n=213;

    cout<<countDigits(n);

    return 0;
}