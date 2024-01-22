#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    int a,b,ans;
    cin >> a >> b;
    
    ans = pow(a,b)+pow(b,a);
    cout << ans;
}