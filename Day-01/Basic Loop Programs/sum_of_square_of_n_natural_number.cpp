#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = 3, sum = 0;

    for(int i=1; i<=num; i++){
        sum = sum + pow(i, 2);
    }

    cout<<sum;

    return 0;
}