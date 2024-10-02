#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
int main(){
    char s[3];
    int a,b,c;
    rep(i,3){
        cin >> s[i];
    }
    if(s[0] == s[1]){
        if(s[0] == '>'){
            if(s[2] == '>'){
                cout << "B";
            }else{
                cout << "C";
            }
        }else{
            if(s[2] == '>'){
                cout << "C";
            }else{
                cout << "B";
            }
        }
    }else{
        cout << "A";
    }

}