#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int main(){
    ll d;
    cin >> d;
    ll ans = 2000000000000;
    ll tmpx = sqrtl(d);
    ll x = static_cast<ll>(tmpx);
    ll y = 0;
    rep(i,x){
        ll tmp = d-abs((x-i)*(x-i));
        ll tmpy = sqrtl(tmp);
        y = static_cast<ll>(tmpy);
        if(abs(d-((x-i)*(x-i))-(y*y))<ans){
            ans = abs(d-((x-i)*(x-i))-(y*y));
        }
        if(abs(d-((x-i)*(x-i))-((y+1)*(y+1)))<ans){
            ans = abs(d-((x-i)*(x-i))-((y+1)*(y+1)));
        }
    }
    cout << ans;
}