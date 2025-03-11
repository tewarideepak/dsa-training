#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = 5, pow = 3, res = 1;

    for(int i=0; i<pow; i++){
        res = res * num;
    }

    cout<<res;
}