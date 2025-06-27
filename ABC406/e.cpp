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

template <long long mod>
struct modint {
  modint(ll v = 0) : value(normalize(v)) {}
  ll val() const { return value; }
  void normalize() { value = normalize(value); }
  ll normalize(ll v) {
    if (v <= mod && v >= -mod) {
      if (v < 0) v += mod;
      return v;
    }
    if (v > 0 && v < 2 * mod) {
      v -= mod;
      return v;
    }
    if (v < 0 && v > -2 * mod) {
      v += 2 * mod;
      return v;
    }
    v %= mod;
    if (v < 0) v += mod;
    return v;
  }
  modint<mod>& operator=(ll v) {
    value = normalize(v);
    return *this;
  }
  bool operator==(const modint& o) const { return value == o.val(); }
  bool operator!=(const modint& o) const { return value != o.val(); }
  const modint& operator+() const { return *this; }
  const modint& operator-() const { return value ? mod - value : 0; }
  const modint operator+(const modint& o) const {
    return value + o.val();
  }
  modint& operator+=(const modint& o) {
    value += o.val();
    if (value >= mod) value -= mod;
    return *this;
  }
  const modint operator-(const modint& o) const {
    return value - o.val();
  }
  modint& operator-=(const modint& o) {
    value -= o.val();
    if (value < 0) value += mod;
    return *this;
  }
  const modint operator*(const modint& o) const {
    return (value * o.val()) % mod;
  }
  modint& operator*=(const modint& o) {
    value *= o.val();
    value %= mod;
    return *this;
  }
  const modint operator/(const modint& o) const { return operator*(o.inv()); }
  modint& operator/=(const modint& o) { return operator*=(o.inv()); }
  const modint pow(ll n) const {
    modint ans = 1, x(value);
    while (n > 0) {
      if (n & 1) ans *= x;
      x *= x;
      n >>= 1;
    }
    return ans;
  }
  const modint inv() const {
    ll a = value, b = mod, u = 1, v = 0;
    while (b) {
      ll t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return u;
  }
  friend ostream& operator<<(ostream& os, const modint& x) {
    return os << x.val();
  }
  template <typename T>
  friend modint operator+(T t, const modint& o) {
    return o + t;
  }
  template <typename T>
  friend modint operator-(T t, const modint& o) {
    return -o + t;
  }
  template <typename T>
  friend modint operator*(T t, const modint& o) {
    return o * t;
  }
  template <typename T>
  friend modint operator/(T t, const modint& o) {
    return o.inv() * t;
  }

 private:
  ll value;
};
using modint1000000007 = modint<1000000007>;
using modint998244353 = modint<998244353>;

modint998244353 conbination(ll n, ll k){
    if(n < k) return 0;
    modint998244353 ans = 1;
    rep(i,1,k){
        ans *= (n - i);
        ans /= i;
    }
    return ans;
}

modint998244353 func(ll n, ll k, bitset<64> bs){
    modint998244353 ans = 0;
    modint998244353 cnt = conbination(n + 1, k);
    cout << cnt << endl;
    rep(n + 1){
        ans += power[i] * cnt;
    }
    for(int i = 63; i >= n; i--){
        if(bs[i]){
            ans += power[i] * cnt * 2;
        }
    }
    return ans;
}

vector<modint998244353> power(60);

int main(){
    LL(t);
    power[0] = 1;
    rep(i,1,60){
        power[i] = power[i - 1] * 2;
    }
    rep(t){
        LL(n,k);
        modint998244353 ans = 0;
        bitset<64> bs(n);
        ll tmp = 0;
        rep(64){
            if(bs[i]){
                tmp = max(tmp, i);
            }
        }
        int l = 0,r = 0;
        for(int i = 63; i <= 0; i--){
            if(bs[i] && l == 0){
                l = i;
            }
            if(bs[i] && r == 0){
                r = i;
                break;
            }
        }
        for(int i = r; i <= 0; i--){
            if(bs[i]){
                int cnt = 0,res = inf;
                for(int j = i - 1; j >= 0; j--){
                    if(bs[j]){
                        cnt++;
                        res = min(res, j);
                    }
                }
                ans += func(k - cnt - 1, res, bs);
                

            }
        }
        modint998244353 cnt = conbination(tmp + 1, k);
        cout << cnt << endl;
        rep(tmp + 1){
            ans += power[i] * cnt;
        }
        cout << ans << endl;
    }
}