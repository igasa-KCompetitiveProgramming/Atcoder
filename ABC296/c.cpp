#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
#include <set>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    int x;
    int a[200000];
    bool check = true;
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);

    int mainasuA;
    if(a[0]<0){
        mainasuA = -a[0];
    }else{
        mainasuA = a[0];
    }

    int* help1 = lower_bound(a, a+n, x+a[0])-1;
    if(x==0){
        cout << "Yes";
        check = false;
    }else if(*help1-mainasuA==x){
        cout << "Yes";
        check = false;
    }else{
        for(int i=1;i<n;i++){
            if(a[i]<0){
                mainasuA = -a[i];
            }else{
                mainasuA = a[i];
            }
            int* help2 = lower_bound(help1,a+n,x+mainasuA)-1;
            help1++;
            if(*help2-a[i]==x){
                cout << "Yes";
                check = false;
                break;    
            }
        }
    }

    if(check)
    cout << "No";
}