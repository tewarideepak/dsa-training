#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = 5, fact = 1;

    for(int i=2; i<=num; i++){
        fact = fact * i;
    }

    cout<<fact;
    return 0;
}