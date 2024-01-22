#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    int n;
    cin >> n;
    int hundred = 0;
    int ten = 0;
    int one = 0;
    hundred = n/100;
    ten = n/10 - hundred*10;
    one = n-(100*hundred)-(10*ten);
    int ans;

    bool check = true;
    while(check){
        if(hundred*ten==one){
            ans = n;
            check = false;
        }else{
            if(one == 9){
                if(ten == 9){
                    one=0;
                    ten=0;
                    hundred++;
                }else{
                one = 0;
                ten++;
                }
            }else{
                one++;
            }
            n++;
        }
    }
    cout << ans << endl;
    
}