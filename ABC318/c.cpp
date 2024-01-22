#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
int main(){
    ll n,d,p;
    vector<ll> f;
    ll check = 0;
    ll check2 = 0;
    ll ans =0;
    cin >> n >> d >> p;
    ll tmp;
    rep(i,n){
        cin >> tmp;
        f.push_back(tmp);
    }

    sort(f.rbegin(), f.rend());
    rep(i,n){
        if(f[i]>p/d){
            check = i;
        }
    }

    ans += (check/d)*p;
    for(int i = check - (check%d);i<d + check - (check%d);i++){
        if(i>n-1){
            break;
        }else{
            check2 += f[i];
        }
    }
    if(check2>p){
        ans += p;
    }else{
        ans += check2;
    }
    if(n > d + check - (check%d)){
        for(int i=d + check - (check%d);i<n;i++){
            ans += f[i];
        }
    }

    cout << ans;
}