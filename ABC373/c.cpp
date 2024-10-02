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
    int n;
    cin >> n;
    ll a,b;
    a = -1*INF;
    b = -1*INF;
    rep(i,n){
        ll tmp;
        cin >> tmp;
        a = max(a,tmp);
    }
    rep(i,n){
        ll tmp;
        cin >> tmp;
        b = max(b,tmp);
    }
    cout << a+b << endl;
}