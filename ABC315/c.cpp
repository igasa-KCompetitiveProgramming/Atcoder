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
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    int n;
    cin >> n;
    vector<int> f(n),s(n);
    rep(i,n){
        cin >> f[i] >> s[i];
    }

    vector<vector<int>> flavor(n);
    rep(i,n){
        flavor[f[i]-1].push_back(s[i]);
    }
    rep(i,n){
        sort(flavor[i].rbegin(), flavor[i].rend());
    }

    vector<int> ans(n);
    pint maxf = {0,0};
    rep(i,n){
        if(flavor[i].size()==0) continue;
        ans.push_back(flavor[i][0]);
        if(maxf.first < flavor[i][0]){
            maxf.first = flavor[i][0];
            maxf.second = i;
        }
    }
    sort(ans.rbegin(), ans.rend());


    if(maxf.first+flavor[maxf.second][1]/2>maxf.first+ans[1]){
        cout << maxf.first+flavor[maxf.second][1]/2 << endl;
    }else{
        cout << maxf.first+ans[1] << endl;  
    }
}