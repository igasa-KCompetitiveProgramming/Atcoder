#include <cstdio>
#include <iostream>
#include <string> 
using namespace std;
int main(void){
    string s;
    cin >> s;
    int ans=0;
    int help;
    for(int i=1;i<9;i++){
        help=(i*2)-1;
        if(s[help]=='1'){
            ans=1;
        }
    }
    if(ans==1){
        cout << "No";
    }else if(ans==0){
        cout << "Yes";
    }
}