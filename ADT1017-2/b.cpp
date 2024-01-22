#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    bool check=true;
    int s[8];
    for(int i=0;i<8;i++){
        cin >> s[i];
    }
    for(int i=0;i<7;i++){
        if(s[i]>s[i+1]){
            check = false;
        }
    }
    for(int i=0;i<8;i++){
        if(s[i]%25!=0){
            check = false;
        }
    }
    if(s[0]<100){
        check = false;
    }else if(s[7]>675){
        check = false;
    }

    if(check){
        cout << "Yes";
    }else{
        cout << "No";
    }
}