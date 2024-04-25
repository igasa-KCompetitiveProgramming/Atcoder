#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i < (int)(n); i++)
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
    vector<ll> leftSum(n);
    vector<ll> rightSum(n);
    ll ans = INF;
    leftSum[0] = 0;
    rightSum[n-1] = 0;
    rep(i,n-1){
        if(s[i] == '1'&& i%2 == 0){
            leftSum[i+1] += c[i];
        }else if(s[i] == '0' && i%2 == 1){
            leftSum[i+1] += c[i];
        }
        leftSum[i+1] += leftSum[i];
    }
    for(int i=n-1;i>0;i--){
        if(s[i] == '1'&& i%2 == 0){
            rightSum[i-1] += c[i];
        }else if(s[i] == '0' && i%2 == 1){
            rightSum[i-1] += c[i];
        }
        rightSum[i-1] += rightSum[i];
    }
    rep(i,n-1){
        ans = min(ans, leftSum[i+1] + rightSum[i]);
        cout << ans << " ";
    }
    cout << endl;
    rep(i,n){
        cout << leftSum[i] << " ";
    }
    cout << endl;
    rep(i,n){
        cout << rightSum[i] << " ";
    }
    rep(i,n-1){
        if(s[i] == '0'&& i%2 == 0){
            leftSum[i+1] += c[i];
        }else if(s[i] == '1' && i%2 == 1){
            leftSum[i+1] += c[i];
        }
        leftSum[i+1] += leftSum[i];
    }
    for(int i=n-1;i>0;i--){
        if(s[i] == '0'&& i%2 == 0){
            rightSum[i-1] += c[i];
        }else if(s[i] == '1' && i%2 == 1){
            rightSum[i-1] += c[i];
        }
        rightSum[i-1] += rightSum[i];
    }
    cout << endl;
    rep(i,n-1){
        ans = min(ans, leftSum[i] + rightSum[i-1]);
        cout << ans << " ";
    }
    cout << endl;
    rep(i,n){
        cout << leftSum[i] << " ";
    }
    cout << endl;
    rep(i,n){
        cout << rightSum[i] << " ";
    }
    cout << endl;
    cout << ans;
}