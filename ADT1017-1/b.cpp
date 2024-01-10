#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
#include <algorithm>
using namespace std;
int main(void){
    string s;
    cin >> s;
    int n[10];
    int check[10]={};
    transform(begin(s), end(s), n, [](char c) {return c - '0'; });
    for(int i=0;i<9;i++){
        check[n[i]]=1;
    }

    for(int i=0;i<10;i++){
        if(check[i]==0){
            cout << i;
        }
    }
}