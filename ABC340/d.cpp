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
    int n;
    cin >> n;
    vector<int> a(n),b(n),x(n);
    rep(i,n-1){
        cin >> a[i] >> b[i] >> x[i];
        x[i]--;
    }
    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> q;
    vector<bool> used(n,false);
    vector<ll> ans(n,INF);
    ans[0] = 0;
    q.push({a[0],0,1});
    q.push({b[0],0,x[0]});
    while(true){
        if(q.empty()) break;
        ll length = get<0>(q.top());
        int now = get<1>(q.top());
        int next = get<2>(q.top());
        q.pop();
        if(next>n-1||now>=n-1){
            continue;
        }
        if(used[next]) continue;
        used[next] = true;
        if(length < ans[next]){
            ans[next] = length;
            q.push({length+a[next],next,next+1});
            q.push({length+b[next],next,x[next]});
        }
    }
    cout << ans[n-1] << endl;
}