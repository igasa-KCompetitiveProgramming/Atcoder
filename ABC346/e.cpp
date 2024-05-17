#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    ll h,w,m;
    cin >> h >> w >> m;
    vector<ll> t(m),a(m),x(m);
    rep(i,m){
        cin >> t[i] >> a[i] >> x[i];
    }
    rep(i,m){
        a[i]--;
    }
    vector<ll> cnt(200010);
    vector<bool> f(h,false),g(w,false);
    ll hc = h,wc = w;
    for(ll i = m-1; i >= 0; i--){
        if(t[i] == 1){
            if(f[a[i]] == false){
                f[a[i]] = true;
                hc--;
                cnt[x[i]] += wc;
            }
        }else{
            if(g[a[i]] == false){
                g[a[i]] = true;
                cnt[x[i]] += hc;
                wc--;
            }
        }
    }
    cnt[0] += hc*wc; 
    vector<pair<ll, ll>> ans;
    rep(i, 200010) if (cnt[i]) ans.push_back({ i,cnt[i] });
    cout << ans.size() << '\n';
    for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
}