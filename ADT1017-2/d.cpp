#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main(void){
    int n,a,b;
    cin >> n >> a >> b;
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int l=0;l<a;l++){
                for(int j=0;j<n;j++){
                    if(j%2==0){
                        for(int k=0;k<b;k++){
                            cout << ".";
                        }
                    }else{
                        for(int k=0;k<b;k++){
                            cout << "#";
                        }
                    }
                }
                cout << endl;
            }
        }else{
            for(int l=0;l<a;l++){
                for(int j=0;j<n;j++){
                    if(j%2==0){
                        for(int k=0;k<b;k++){
                            cout << "#";
                        }
                    }else{
                        for(int k=0;k<b;k++){
                            cout << ".";
                        }
                    }
                }
                cout << endl;
            }
        }
    }
}