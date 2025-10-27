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

ll Pow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main(){
    LL(t);
    rep(timer, t){
        LL(n, k, x);
        vector<pair<long double, ll>> a(n);
        vector<long double> a_copy(n);
        rep(n) cin >> a[i].first;
        rep(n) a[i].second = 1;
        rep(n) a_copy[i] = a[i].first;
        sort(a.begin(), a.end());
        ll power = 0;
        ll tmp = a[0].first;
        while(true){
            if(tmp <= 1) break;
            tmp /= 2;
            power++;
        }
        ll cnt = 0;
        rep(n){
            ll res = 0;
            while(true){
                if(a[i].first <= pow(2, power)) break;
                res += a[i].second;
                a[i].first /= 2;
                a[i].second *= 2;
            }
            cnt += res;
        }
        if(cnt > k){
            priority_queue<pair<long double, ll>> pq;
            rep(n) pq.push({a_copy[i], 1});
            cnt = 0;
            while(true){
                auto [v, idx] = pq.top();
                if(cnt >= k) break;
                pq.pop();
                if(cnt + idx > k){
                    pq.push({v/2, 2*(k - cnt)});
                    pq.push({v, cnt - k});
                    break;
                }else{
                    cnt += idx;
                    //cout << v << spa << idx << endl;
                    pq.push({v/2, 2*idx});
                }
            }
            while(!pq.empty()){
                auto [v, idx] = pq.top(); pq.pop();
                //cout << fixed << setprecision(15) << v << " " << idx << endl;
                if(x - idx <= 0){
                    cout << fixed << setprecision(15) << v << endl;
                    break;
                }
                x -= idx;
            }
        }else{
            sort(a.rbegin(), a.rend());
            while(true){
                if(cnt >= k) break;
                rep(n){
                    if(a[i].second + cnt > k){
                        cout << a[i].se << spa << cnt << spa << k << endl;
                        a.pb({(long double)(a[i].first / (long double)2), (ll)((ll)2 * (k - cnt))});
                        a[i].second -= (k - cnt);
                        cnt = k;
                        break;
                    }else{
                        cnt += a[i].second;
                        a[i].first /= 2;
                        a[i].second *= 2;
                    }
                }
            }
            sort(a.rbegin(), a.rend());
            //rep(a.size()) cout << fixed << setprecision(15) << a[i].first << " " << a[i].second << endl;
            rep(n){
                cout << fixed << setprecision(15) << a[i].first << " " << a[i].second << endl;
                if(x - a[i].second <= 0){
                    cout << fixed << setprecision(15) << a[i].first << endl;
                    break;
                }
                x -= a[i].second;
            }
        }
    }
}