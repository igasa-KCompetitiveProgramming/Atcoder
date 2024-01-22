#include <cstdio>
#include<iostream>
#include <string>
using namespace std;
int main(void){
    int n;
    string s[100];
    int ans[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='o'){
                ans[i]++;
            }
        }
    }
    
    for(int i=n-1;i>-1;i--){
        for(int j=0;j<n;j++){
            if(ans[j]==i){
                cout << j+1 << ' ';
            }
        }
    }
}