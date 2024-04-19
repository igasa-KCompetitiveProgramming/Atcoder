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
    ll n;
    string s;
    cin >> n;
    cin >> s;
    vector<ll> c(n);
    rep(i,n){
        cin >> c[i];
    }
    vector<ll> left01(n);
    vector<ll> right01(n);
    vector<ll> left10(n);
    vector<ll> right10(n);
    if(s[0] == '0'){
        left01[0] = c[0];
    }else{
        left10[0] = c[0];
    }
    if(s[n-1] == '0'){
        right01[n-1] = c[n-1];
    }else{
        right10[n-1] = c[n-1];
    }
    rep1(i,n-1){
        left01[i] = left01[i-1];
        left10[i] = left10[i-1];
        if(s[i] == '0'){
            if(i%2 == 0){
                left01[i] += c[i];
            }else{
                left10[i] += c[i];
            }
        }else{
            if(i%2 == 0){
                left10[i] += c[i];
            }else{
                left01[i] += c[i];
            }
        }
    }
    for(int i = n-2;n-1<=0;i--){
        right01[i] = right01[i+1];
        right10[i] = right10[i+1];
        if(s[i] == '0'){
            if(i%2 == 0){
                right01[i] += c[i];
            }else{
                right10[i] += c[i];
            }
        }else{
            if(i%2 == 0){
                right10[i] += c[i];
            }else{
                right01[i] += c[i];
            }
        }
    }
    ll ans = INF;
    rep(i,n){
        cout << left01[i] << " ";
    }
    cout << endl;
    rep(i,n){
        cout << left10[i] << " ";
    }
    cout << endl;
    rep(i,n){
        cout << right01[i] << " ";
    }
    cout << endl;
    rep(i,n){
        cout << right10[i] << " ";
    }
    cout << endl;
    rep(i,n-1){
        ans = min(INF,left01[i-1]+right10[i]);
        ans = min(ans,left10[i-1]+right01[i]);
    }
    cout << ans << endl;
}