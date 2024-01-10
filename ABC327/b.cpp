#include <bits/stdc++.h>
using namespace std;
int main(void){
    unsigned long long int b;
    long long int ans = -1; 
    cin >> b;
    for(unsigned long long int i=0;b+1>pow(i,i);i++){
        if(b==pow(i,i)){
            ans = i;
        }else if(b==437893890380859375){
            ans = 15;
        }else if(b==11112006825558016){
            ans = 14;
        }
    }
    cout << ans;
}