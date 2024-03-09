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
    int n,m,l;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    rep(i,m){
        cin >> b[i];
    }
    cin >> l;
    vector<int> c(l);
    rep(i,l){
        cin >> c[i];
    }
    int q;
    cin >> q;
    vector<pint> x(q);
    rep(i,q){
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    sort(x.begin(),x.end());
    vector<int> check(q);
    rep(i,q){
        check[i] = 0;
    }
    int flg = 0;
    vector<int> sum;
    rep(i,n){
        rep(j,m){
            rep(k,l){
                sum.push_back(a[i]+b[j]+c[k]);
            }
        }
    }
    sort(sum.begin(),sum.end());
    rep(i,q){
        if(binary_search(sum.begin(),sum.end(),x[i].first)){
            check[x[i].second] = 1;
        }
    }
    rep(i,q){
        if(check[i]==1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}