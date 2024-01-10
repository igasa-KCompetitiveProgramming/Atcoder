#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    int n,p;
    int a[100000];
    int ans = 0;
    cin >> n >> p;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<p){
            ans++;
        }
    }
    cout << ans;
}