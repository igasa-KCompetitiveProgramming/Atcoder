#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    long long n=0;
    cin >> n;
    while(n%3==0)
    {
        n=n/3;
    }
    while(n%2==0){
        n=n/2;
    }
    if(n==1){
        cout << "Yes";
    }else if(n==0){
        cout << "No";
    }else if(n<0){
        cout << "No";
    }else{
        cout << "No";
    }
}