#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
//bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    int n,x;
    cin >> n;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(40));
    rep(i,n){
        cin >> c[i];
        rep(j,c[i]){
            cin >> a[i][j];
        }
    }
    cin >> x;
    
    int minimum = 1000000000;
    vector<pint> ans;
    rep(i,n){
        rep(j,c[i]){
            if(a[i][j]==x){
                pint tmp;
                minimum = min(minimum,c[i]);
                tmp.first = i;
                tmp.second = c[i];
                ans.push_back(tmp);

            }
        }
    }
    
    int cnt = 0;

    rep(i,ans.size()){
        if(ans[i].second==minimum){
            cnt++;
        }
    }
    cout << cnt << endl;
    rep(i,ans.size()){
        if(ans[i].second==minimum){
            cout << ans[i].first+1 << " ";
        }
    }
}