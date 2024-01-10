#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    string num;
    if(n!=0){
        num = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
        for(int i=0;i<n+2;i++){
            cout << num[i];
        }
    }else{
        cout << "3";
    }    
}
