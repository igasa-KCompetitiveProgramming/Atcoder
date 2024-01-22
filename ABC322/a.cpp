#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    int n;
    string s;
    cin >> n >> s;
    int ans=-1;
    for(int i=0;i<n-2;i++){
        if(s[i]=='A'){
            if(s[i+1]=='B'){
                if(s[i+2]=='C'){
                    ans = i+1;
                    break;
                }
            }
        }
    }

    cout << ans;
}