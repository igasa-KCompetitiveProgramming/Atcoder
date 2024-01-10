#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
#include <algorithm>
using namespace std;
int main(void){
    long long n;
    long long inf[2][1000];
    cin >> n ;
    for(int i=0;i<n;i++){
        cin >> inf[0][i];
        cin >> inf[1][i];
    }

    int ans[24]={};
    for(int i=0;i<24;i++){
        for(int j=0;j<n;j++){
            if(i>=16){
                if((inf[1][j]>=i&&inf[1][j]<=24)||inf[1][j]<=i-16){
                    ans[i] += inf[0][j];
                }
            }else{
                if(inf[1][j]>=i&&inf[1][j]<=i+8){
                    ans[i] += inf[0][j];
                }
            }
        }
    }


    long long max = *std::max_element(ans, ans + 24);

    

    cout << max;
    
}