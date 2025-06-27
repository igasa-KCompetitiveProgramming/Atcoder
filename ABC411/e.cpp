#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rrep1(a)          for(ll i = (ll)(a-1); i >= (ll)0 ; i--)
#define rrep2(i, a)       for(ll i = (ll)(a-1); i >= (ll)0; i--)
#define rrep3(i, a, b)    for(ll i = (ll)(a-1); i >=(b); i--)
#define rrep4(i, a, b, c) for(ll i = (ll)(a-1); i >=(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define rep1(a)          for(ll i = 0; i < (ll)(a); i++)
#define rep2(i, a)       for(ll i = 0; i < (ll)(a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (ll)(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define fi first
#define se second
#define pb push_back
#define spa " "

//！？！？
#define O print

inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

//int INF = 2147483647; // おおよそ2*10^9
ll inf = 1LL<<60; //おおよそ10^18
//ull UINF == おおよそ1.8*10^19

const ll mod = 998244353;
class mint{
  public:
    ll x;

    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint power(ll n) const {
        mint res = 1;
        mint b = *this;
        while(n > 0){
            if(n & 1) res *= b;
            b *= b;
            n >>= 1;
        }
        return res;
    }
    mint inv() const {
        return power(mod - 2);
    }

    mint& operator+=(const mint& a){
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a){
        if((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint& a){
        (x *= a.x) %= mod;
        return *this;
    }
    mint& operator/=(const mint& a){
        return *this = *this * a.inv();
    }

    mint operator+(const mint& a){
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint& a){
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint& a){
        mint res(*this);
        return res *= a;
    }
    mint operator/(const mint& a){
        mint res(*this);
        return res /= a;
    }
};

int main(){
    LL(n);
    vector<vector<ll>> a(n, vector<ll>(6));
    vector<int> s;
    rep(n){
        rep(j,6){
            cin >> a[i][j];
            s.pb(a[i][j]);
        }
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int k = s.size();
    vector<vector<int>> cnt(k);
    rep(n){
        rep(j,6){
            int idx = lower_bound(s.begin(), s.end(), a[i][j]) - s.begin();
            cnt[idx].pb(i);
        }
    }
    
    mint ans = 0;

    vector<int> perm(n,0);
    int zero_cnt = n;
    mint p = 1;
    
    rep(k-1){
        for(auto idx : cnt[i]){
            if(perm[idx] == 0){
                zero_cnt--;
            }else{
                p /= perm[idx];
            }
            perm[idx]++;
            p *= perm[idx];
        }
        if(zero_cnt == 0) ans -= p * mint(s[i + 1] - s[i]);
    }

    ans /= mint(6).power(n);
    ans += mint(s[k - 1]);
    cout << ans.x << endl;
}