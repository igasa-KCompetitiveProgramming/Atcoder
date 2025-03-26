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

int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19

class solve{
  public:
    int n;
    int week;
    ll score = 0;
    vector<int> a;
    vector<pint> ans;
    vector<pint> sorted_index;
    vector<pint> final_ans;

    void input(){
        cin >> n >> week;
        a.resize(n);
        ans.resize(n);
        final_ans.resize(n);
        sorted_index.resize(n);
        rep(n) cin >> a[i];
    }

    void third(){
        rep(n){
            sorted_index[i] = {a[i],i};
        }
        sort(sorted_index.rbegin(), sorted_index.rend());\
        rep(n){
            if(i == n-1) ans[sorted_index[i].se].fi = sorted_index[0].se;
            else ans[sorted_index[i].se].fi = sorted_index[i+1].se;
        }
        rep(n){
            if(i == 0) ans[sorted_index[i].se].se = sorted_index[i].se;
            else ans[sorted_index[i].se].se = sorted_index[i-1].se;
        }
        vector<int> time(n);
        int now = 0;
        rep(week){
            time[now]++;
            if(time[now] % 2 == 1){
                now = ans[now].fi;
            }else{
                now = ans[now].se;
            }
        }
        ll tmp = pow(10,6);
        rep(n){
            tmp -= abs(a[i] - time[i]);
        }
        score = tmp;
        final_ans = ans;
    }

    void forth(){
        rep(n){
            sorted_index[i] = {a[i],i};
        }
        sort(sorted_index.rbegin(), sorted_index.rend());\
        rep(n){
            if(i == n-1) ans[sorted_index[i].se].se = sorted_index[0].se;
            else ans[sorted_index[i].se].se = sorted_index[i+1].se;
        }
        rep(n){
            if(i == 0) ans[sorted_index[i].se].fi = sorted_index[i].se;
            else ans[sorted_index[i].se].fi = sorted_index[i-1].se;
        }
        vector<int> time(n);
        int now = 0;
        rep(week){
            time[now]++;
            if(time[now] % 2 == 1){
                now = ans[now].fi;
            }else{
                now = ans[now].se;
            }
        }
        ll tmp = pow(10,6);
        rep(n){
            tmp -= abs(a[i] - time[i]);
        }
        if(tmp > score){
            score = tmp;
            final_ans = ans;
        }
    }

    void answer(){
        rep(n){
            cout << final_ans[i].fi << spa << final_ans[i].se << endl;
        }
    }
};

int main(){
    solve s;
    s.input();
    s.third();
    s.forth();
    s.answer();
}