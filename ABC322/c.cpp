#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    int n,m;
    int a[200000];
    int help=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    
    for(int i=1;i<n+1;i++){
        if(a[help]>i){
            cout << a[help]-i << endl;
        }else if(a[help]==i){
            cout << 0 << endl;
            help++;
        }
    }
}