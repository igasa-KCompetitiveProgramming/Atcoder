#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    int n,m;
    string s,t;
    cin >> n >> m;
    cin >> s >> t;
    int check1 = 0;
    int check2 = 0;
    for(int i=0;i<n;i++){
        if(s[i]==t[i]){
            check1++;
        }
        if(s[i]==t[m-n+i]){
            check2++;
        }
    }

    if(check1==n && check2==n){
        cout << 0;
    }else if(check1==n){
        cout << 1;
    }else if(check2==n){
        cout << 2;
    }else{
        cout << 3;
    }
}