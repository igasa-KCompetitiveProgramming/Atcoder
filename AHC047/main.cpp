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

class solv{
public:
    ll n,m,l;
    vector<pair<ll,string>> s;


    vector<pair<char, vector<ll>>> ans;

    void input(){
        cin >> n >> m >> l;
        s.resize(n);
        rep(n) cin >> s[i].se >> s[i].fi;
        sort(s.begin(), s.end(), greater<pair<ll,string>>());

        ans.resize(m);
        rep(m){
            ans[i].fi = ';';
            ans[i].se.resize(m, 0);
        }
    }

    void solve(){
        rep(s[0].se.size()){
            ans[i].fi = s[0].se[i];
            int cnt = 40;
            rep(j,m){
                if((i == m-1 && j == 0) || j == i + 1){
                    ans[i].se[j] = cnt;
                }
            }
        }
        vector<vector<ll>> tmp(10);
        rep(s[0].se.size()){
            tmp[s[0].se[i] - 'a'].pb(i);
        }

        vector<vector<ll>> tmp2 = tmp;
        int bef = -1,aft = -1;
        vector<ll> res;
        rep(j,1,n){
            bool flag = false;
            tmp2 = tmp;
            rep(i,s[j].se.size()){
                if(tmp[s[j].se[i] - 'a'].size() == 0){
                    flag = true;
                    break;
                }else{
                    if(tmp2[s[j].se[i] - 'a'].size() == 0){
                        rep(k,tmp[s[j].se[i] - 'a'].size()){
                            tmp2[s[j].se[i] - 'a'].pb(tmp[s[j].se[i] - 'a'][k]);
                        }
                    }
                    res.pb(tmp2[s[j].se[i] - 'a'].back());
                    tmp2[s[j].se[i] - 'a'].pop_back();
                }
            }
            if(!flag) break;
        }
        
        vector<ll> tmp3(res.size(),0);
        rep(res.size()){
            tmp3[res[i]]++;
        }
        

        rep(res.size() - 1){
            if(ans[res[i]].se[res[i+1]] != 0) continue;
            if(tmp3[res[i]] == 1) ans[res[i]].se[res[i+1]] += 47;
            else ans[res[i]].se[res[i+1]] += ll(60/tmp3[res[i]]);
        }


        rep(s[0].se.size()){
            int cnt = 0;
            vector<bool> used(m, false);
            rep(j,m){
                cnt += ans[i].se[j];
                if(ans[i].se[j] != 0) used[j] = true;
            }


            if(cnt == 100) continue;
            else{
                int j = 0;
                while(cnt < 100){
                    if(j == m) j = 0;
                    if(used[j]){
                        j++;
                        continue;
                    }else{
                        ans[i].se[j]++;
                        j++;
                        cnt++;
                    }
                }
            }
        }
    }

    void check(){
        vector<bool> used(m, false);
        rep(m){
            if(ans[i].fi == ';') continue;
            used[ans[i].fi - 'a'] = true;
        }
        rep(m){
            if(ans[i].fi == ';'){
                int cnt = 100;
                int j = 0;
                while(cnt > 0){
                    if(j == m) j = 0;
                    ans[i].se[j]++;
                    cnt--;
                    j++;
                }
                bool flag = false;
                rep(j,6){
                    if(used[j]) continue;
                    else{
                        ans[i].fi = char('a' + j);
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    ans[i].fi = 'a';
                    m++;
                }
            }
        }
    }

    void answer(){
        rep(i, ans.size()){
            cout << ans[i].fi << spa;
            rep(j, ans[i].se.size()){
                cout << ans[i].se[j] << spa;
            }
            cout << endl;
        }
    }
};

int main(){
    solv s;
    s.input();
    s.solve();
    s.check();
    s.answer();
}