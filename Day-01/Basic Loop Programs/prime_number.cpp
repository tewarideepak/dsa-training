#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = 4, is_prime = 1;

    for(int i = 2; i<= num/2; i++){
        if(num%i==0){
            is_prime = 0;
            break;
        }
    }

    if(is_prime) cout<<"PRIME";
    else cout<<"NOT PRIME";


    return 0;
}