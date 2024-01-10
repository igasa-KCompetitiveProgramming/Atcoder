#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    int k;
    cin >> k;
    int check;
    if(k>=60){
        check=1;
    }

    if(check==1&&k<70){
        cout << "22:0" << k-60;
    }else if(check==1){
        cout << "22:" << k-60;
    }else if(k<10){
        cout << "21:0" << k;
    }else{
        cout << "21:" << k; 
    }
}