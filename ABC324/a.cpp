#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    int n;
    int a[100];
    int ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        if(a[1]==a[i]){
            ans++;
        }
    }
    if(ans==n){
        cout << "Yes";
    }else{
        cout << "No";
    }
}