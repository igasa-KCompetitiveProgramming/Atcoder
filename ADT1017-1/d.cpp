#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
#include<algorithm>
using namespace std;
int main(void){
    int n,m;
    int k[100];
    int x[100][100];
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> k[i];
        for(int j=0;j<k[i];j++){
            x[i][j];
        }
    }

    int check[50][100] = {};
    int ot;
    if(n%2==0){
        ot=n/2;
    }else{
        ot=n/2+1;
    }
    for(int j=0;j<ot;j++){
        for(int l=0;l<m;l++){
            if(find(x[l] ,x[l]+k[m], ot)){
                for(int i=0;i<k[m];i++){
                    check[j][x[l][i]]=1;
                }
            }
        }
    }

    bool anscheck=true;
    for(int i=0;i<50;i++){
        for(int j=0;j<100;j++){
            if(check[i][j]==0){
                anscheck = false;
            }
        }
    }
    
    if(anscheck){
        cout << "Yes";
    }else{
        cout << "No";
    }
}