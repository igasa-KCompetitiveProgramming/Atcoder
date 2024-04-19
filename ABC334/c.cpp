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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(k);
    rep(i,k){
        cin >> a[i];
    }
    ll ans = 0;
    if(k==1){
        cout << 0;
        return 0;
    }
    if(k%2==0){
        rep(i,k/2){
            ans += a[2*i+1] - a[2*i];
        }
    }else{
        int tmp = 0;
        int diff = 0;
        rep(i,k-1){
            if(diff < a[i+1] - a[i]){
                diff = a[i+1] - a[i];
                tmp = i;
            }
        }
        a.erase(a.begin()+tmp);
        rep(i,k/2){
            ans += a[2*i+1] - a[2*i];
        }
    }
    cout << ans << endl;
}