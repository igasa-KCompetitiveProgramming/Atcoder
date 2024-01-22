#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a[9][9];
    int tmp = 0;
    bool check = true;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> a[i][j];
        }
    }

    for(int i=1;i<10;i++){
        for(int j=0;j<9;j++){
            for(int k=0;k<9;k++){
                if(a[j][k]==i){
                    tmp = 1;
                }
            }
        }
    }

    if(check){
        cout << "Yes";
    }else{
        cout << "No";
    }
}