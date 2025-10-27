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
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

class SOLVE{
  public:
    ll n, m, l, u;
    vector<ll> a, b, answer;

    void input(){
        cin >> n >> m >> l >> u;
        a.resize(n);
        b.resize(m);
        answer.resize(n);
    }

    void intract(){
        //rep(n) cout << i << spa << a[i] << endl;

        rep(n) cout << a[i] << ' ';
        cout << flush << '\n';
        rep(m) cin >> b[i];
    }

    void donyoku(){
        const int firs = 27;
        rep(m){
            a[i] = Pow(10, 15) - 2*Pow(10, 12);
            rep(j,firs) a[i] += rand() % Pow(2, firs - j - 1);
        }
        sort(a.begin(), a.begin() + m);
        vector<ll> checcker = a;
        int cnt = firs;
        vector<int> count(42 - firs, 0);
        rep(i, firs, 42){
            //cout << i << spa << Pow(2, i) << endl;
        }
        rep(i, m, n){
            ll tmp = Pow(2, cnt);
            if(tmp > 4*Pow(10, 12)){
                cnt = firs;
                tmp = Pow(2, cnt);
            }
            a[i] = tmp;
            count[cnt - firs]++;
            cnt++;
        }
        //rep(count.size()) cout << count[i] << spa;
        vector<int> used(count.size(), 0);
        //cout << endl;
        vector<ll> diff(m);
        intract();
        rep(m) diff[i] = b[i] - (Pow(10, 15) - 2*Pow(10, 12));
        //rep(m) cout << diff[i] << spa;
        //cout << endl;
        vector<int> answer(n, 0);
        rep(m) answer[i] = i + 1;
        for(int i = m - 1; i >= 0; i--){
            if(diff[i] <= 0) continue;
            bitset<50> bs(diff[i]);
            rep(j, firs, 42){
                if(checcker[i] + Pow(2, j) > b[i]) break;
                if(bs[j] == 1 && used[j - firs] != count[j - firs]){
                    answer[m + j - firs + used[j - firs] * count.size()] = i + 1;
                    used[j - firs]++;
                }
            }
        }
        vector<ll> check(m, 0);
        vector<pair<ll,int>> sts;
        set<pair<ll,int>> stss;
        rep(n){
            //cout << a[i] << spa << answer[i] << endl;
            //cout << answer[i] << spa;
            //if(answer[i] != 0) check[answer[i] - 1] += a[i];
        }
        rep(n){
            if(answer[i] == 0){
                sts.push_back({a[i], i});
            }else check[answer[i] - 1] += a[i];
        }
        sort(sts.rbegin(), sts.rend());
        //cout << endl;
        rep(m){
            stss.insert({check[i] - b[i], i});
        }
        for(auto x : sts){
            //cout << x.fi << spa << x.se << endl;
        }
        for(auto x : stss){
            //cout << x.fi << spa << x.se << endl;
            ll y = x.fi;
            while(true){
                //cout << "y " << y << endl;
                if(y > 0) break;
                int index = -1;
                ll minIndex = abs(y);
                rep(sts.size()){
                    if(answer[sts[i].se] != 0) continue;
                    //cout << abs(y + sts[i].fi) << spa << minIndex << endl;
                    if(minIndex > abs(y + sts[i].fi)){
                        index = i;
                        minIndex = min(minIndex, abs(y + sts[i].fi));
                    }
                }
                if(index == -1) break;
                //cout << answer[sts[index].se] << endl;
                y += sts[index].fi;
                answer[sts[index].se] = x.se + 1;
                //cout << y << spa << answer[sts[index].se] << endl;
                //break;
            }
            //break;
        }
        //rep(m) cout << check[i] << endl;
        rep(n){
            cout << answer[i] << spa;
            //cout << answer[i] << spa;
        }
    }
};

int main(){
    SOLVE solve;
    solve.input();
    solve.donyoku();
    return 0;
}