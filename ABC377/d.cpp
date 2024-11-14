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
    ll n,m;
    cin >> n >> m;
    vector<ll> l(n),r(n);
    map<ll,ll> lmp,rmp;
    rep(i,n){
        cin >> l[i] >> r[i];
    }
    rep(i,m){
        lmp[i+1] = INF;
        rmp[i+1] = 0;
    }
    rep(i,n){
        lmp[l[i]] = min(lmp[l[i]],r[i]);
        rmp[r[i]] = max(rmp[r[i]],l[i]);
    }
    ll ans = 0;
    ll nl = 1, nr = m, lcheck = 0;
    rep1(i,m){
        if(lmp[i] != 0){
            if(nr >= lmp[i]) lcheck = i;
            nr = min(nr,lmp[i]-1);
            lmp[i] = 0;
        }
        cout << nr << " " << i << endl;
        if(nr == i) break;
    }
    rep1(i,m){
        ans += max(nr - nl + 1,0ll);
        cout << nr << " " << nl << " " << ans << "  " << lcheck << " " << i << endl;
        if(lmp[nl] == 0){
            nl++;
            continue;
        }
        if(lcheck > i) continue;
        int tmp = i;
        nr = m;
        while(true){
            if(lmp[tmp] != 0){
                if(nr >= lmp[tmp]) lcheck = tmp;
                nr = min(nr,lmp[tmp]-1);
                lmp[tmp] = 0;
            }
            cout << tmp << " " << nr << endl;
            if(nr == tmp) break;
            tmp++;
        }
    }
    cout << endl << ans << endl;
}