#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    int x,y;
    cin >> x >> y;
    if(x-y<0){
        if(x-y<-2){
        cout << "No";
        }else{
        cout << "Yes";
        }
    }else if(x-y>0){
        if(x-y>3){
            cout << "No";
        }else{
        cout << "Yes";
        }
    }
}