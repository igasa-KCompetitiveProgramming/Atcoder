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
    ll n,t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<ll> x(n);
    vector<ll> right;
    vector<ll> left;
    rep(i,n){
        cin >> x[i];
    }
    ll ans = 0;
    rep(i,n){
        if(s[i] == '1'){
            right.push_back(x[i]);
        }
        else{
            left.push_back(x[i]);
        }
    }
    sort(right.begin(),right.end());
    sort(left.begin(),left.end());
    ll rcnt = 0;
    ll lcnt = 0;
    ll rdl = 0;
    rep(i,n){
        if(lcnt >= left.size()){
            break;
        }
        if(rcnt >= right.size()){
            while(true){
                if(rdl > rcnt) break;
                if(abs(right[rdl]-left[lcnt]) > 2*t){
                    rdl++;
                }else{
                    break;
                }
            }
            ans += max(rcnt-rdl,0LL);
            lcnt++;
            continue;
        }
        if(right[rcnt] < left[lcnt]){
            rcnt++;
        }else{
            while(true){
                if(rdl > rcnt) break;
                if(abs(right[rdl]-left[lcnt]) > 2*t){
                    rdl++;
                }else{
                    break;
                }
            }
            ans += max(rcnt-rdl,0LL);
            lcnt++;
        }
    }
    cout << ans << endl;
}