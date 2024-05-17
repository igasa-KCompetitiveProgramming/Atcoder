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
// m <- updateする要素数, n <- 加算する値, s <- segの一番下のサイズ
void segAdd(vector<ll>& seg,ll& M, ll& N, ll& S){
    ll s = S;
    ll m = M;
    ll tmp = s;
    seg[m] += N;
    cout << "m = " << m << " s = " << s << " tmp = " << tmp << " N = " << N << endl;
    while(true){
        if(s == 1) break;
        m /= 2;
        s /= 2;
        tmp += s;
        seg[tmp+m] += N;
        cout << "m = " << m << " s = " << s << " tmp = " << tmp << endl;
    }
    cout << "end" << endl;
}

int main(){
    ll n;
    cin >> n;
    vector<pll> a;
    rep(i,n){
        ll n1;
        cin >> n1;
        a.push_back({n1,i});
    }
    rep(i,n){
        cout << a[i].second << " " << a[i].first << endl;
    }   
    sort(a.begin(),a.end());
    ll cnt = n;
    ll tmp = n;
    while(true){
        if(tmp == 0) break;
        tmp /= 2;
        cnt += tmp;
    }
    vector<ll> seg(cnt);
    sort(a.begin(),a.end());
    cout << cnt << endl;
    rep(i,n){
        segAdd(seg,a[i].second,a[i].first,n);
    }
    tmp = n;
    rep(i,cnt){
        if(tmp == 0){
            cout << endl;
            n /= 2;
            tmp = n;
        }
        cout << seg[i] << " ";
        tmp--;
    }
}