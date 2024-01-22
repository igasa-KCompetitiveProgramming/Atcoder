#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    int a;
    bool check = false;
    cin >> a;
    cin >> s;
    for(int i=0;i<a-1;i++){
        if((s[i]=='a'&&s[i+1]=='b')||(s[i+1]=='a'&&s[i]=='b')){
            check = true;
        }
    }
    if(check){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
