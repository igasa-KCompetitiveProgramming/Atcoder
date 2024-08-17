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

ll POWER(ll a, ll b){
    ll ans = 1;
    rep(i,b){
        ans *= a;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bitset<32>> b(n);
    rep(i,n){
        cin >> a[i];
        b[i] = bitset<32>(a[i]);
    }
    ll ans = 0;
    rep(i,3){
        bool flag = false;
        int cnt = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        rep(j,n){
            if(!b[j][i]){
                flag = true;
                cnt3++;
            }
            if(b[j][i]) cnt++;
            if(!flag) continue;
            if(!b[j][i]){
                ans += (cnt+1)/2 * (POWER(2,i));
                cout << ans << " ";
            }else{
                if(cnt2/2==cnt/2) continue;
                cnt2 = cnt;
                ans += (cnt+cnt3+1)/2 * (POWER(2,i));
                cout << ans << " ";
            }
        }
        cout << endl;
    }
    cout << ans << endl;
}
