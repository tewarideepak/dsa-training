#include<bits/stdc++.h>
using namespace std;

int main(){
    int num=5, sum = 0;

    for(int i=1; i<=num; i++){
        sum = sum + i;
    }

    cout<<"Sum of "<<num<<" is: "<<sum;

    return 0;
}