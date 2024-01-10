#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}
int main(){
    ll n;
    vector<pair<ll,ll>> ans;
    pair<ll, ll> tmp;
    ll a[200000];
    ll check=1;
    ll max=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        max += a[i];
        tmp.first = a[i];
        tmp.second = i;
        ans.push_back(tmp);
    }
    sort(ans.begin(),ans.end());
    sort(a, a+n); 
    rep(i,n){
    }
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            check++;
        }else if(i==n-1){             
            max = max-a[i]*check;
            for(int j=0;j<check;j++){
                ans[i-j].first = max;
            }
        }else{
        max = max-a[i]*check;
            for(int j=0;j<check;j++){
                ans[i-j].first = max;
            }
            check = 1;
        }
    }
    
    sort(ans.begin(), ans.end(), compare);

    rep(i,n){
        cout << ans[i].first << " ";
    }
}