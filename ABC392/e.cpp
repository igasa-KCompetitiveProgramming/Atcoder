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

//vectorのcin,cout
template<typename T>
std::istream &operator>>(std::istream&is,std::vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
//dequeのcin,cout
template<typename T>
std::istream &operator>>(std::istream&is,std::deque<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::deque<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
//pairのcin,cout
template<typename T,typename U>
std::ostream &operator<<(std::ostream&os,const std::pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T,typename U>
std::istream &operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
//vector<vector<T>>のcout
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v) {
for (const auto &row : v) {for (auto it = row.begin(); it != row.end(); ++it) { os << *it; if (std::next(it) != row.end()) { os << " "; } } os << "\n";} return os;}

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19

class UnionFind{
    public:
    UnionFind() = default;

    explicit UnionFind(size_t n) : m_parents(n){
        iota(m_parents.begin(), m_parents.end(), 0);
    }

    ll root(ll i){
        if(m_parents[i] == i) return i;
        return(m_parents[i] = root(m_parents[i]));
    }

    void merge(ll a,ll b){
        a = root(a);
        b = root(b);
        if(a != b) m_parents[b] = a;
    }

    bool connecter(ll a,ll b){
        return root(a) == root(b);
    }
    private:
    vector<ll> m_parents;
};

int main(){
    LL(n,m);
    vector<ll> a(m),b(m);
    queue<int> q;
    UnionFind uf(n);
    rep(m){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        if(uf.connecter(a[i],b[i])){
            q.push(i);
        }else{
            uf.merge(a[i],b[i]);
        }
    }
    vector<tuple<int,int,int>> ans;
    vector<bool> connected(n,false);
    connected[0] = true;
    set<int> s;
    rep(n){
        s.insert(uf.root(i));
    }

    while(s.size() > 1){
        int f = *s.begin(); s.erase(s.begin());
        int g = uf.root(a[q.front()]), x = q.front(); q.pop();
        s.erase(g);
        if(f == g){
            f = *s.begin(); s.erase(s.begin());
        }
        //cout << x << spa << f << spa << g << endl;
        ans.push_back({x+1,a[x]+1,f+1});
        uf.merge(a[x],f);
        s.insert(uf.root(a[x]));
    }
    
    cout << ans.size() << endl;
    rep(ans.size()){
        cout << get<0>(ans[i]) << spa << get<1>(ans[i]) << spa << get<2>(ans[i]) << endl;
    }
}