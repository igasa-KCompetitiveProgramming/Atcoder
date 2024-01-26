#include <iostream>
using namespace std;
int main(void){
    int a,b;
    int ans;
    cin >> a >> b;
    if((a+1)!=b){
        ans = 1;
    }else if(a%3==0){
        ans = 1;
    }else{
        ans = 0;
    }
    if(ans==0){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
