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
    ll mod = 998244353;
    ull n,m;
    cin >> n >> m;
    ull cnt = 0;
    ull tmp2 = n;
    while(true){
        if(tmp2 == 0) break;
        tmp2 /= 2;
        cnt++;
    }
    bitset<60> a(m);
    vector<ull> pow2;
    ull tmp = 2;
    rep(i,60){
        tmp*=2;
        pow2.push_back(tmp);
    }
    ull ans = 0;
    n++;
    rep(i,cnt){
        if(a[i] == 0){
            continue;
        }
        if(i == 0){
            n--;
            ans += (((n-1)/2)+1)%mod;
            n++;
            ans %= mod;
            continue;
        }
        cout << "i=" << i << endl;
        ll q = n/pow2[i-1];
        ans += q*(pow2[i-1]/2)%mod;
        ans %= mod;
        q = n%pow2[i-1];
        if(q<0) continue;
        ans += q%pow2[i-1]/2;
        ans %= mod;
        cout << ans << endl;
    }
    cout << ans%mod;
}