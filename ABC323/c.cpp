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
    int n,m;
    cin >> n >> m;
    vector<pint> a(m);
    vector<string> s(n);
    rep(i,m){
        cin >> a[i].first;
        a[i].second = i;
    }   
    rep(i,n){
        cin >> s[i];
    }

    sort(a.rbegin(), a.rend());

    vector<int> point(n);
    int maxP = 0;
    rep(i,n){
        point[i] += i+1;
        rep(j,m){
            if(s[i][a[j].second]=='o'){
                point[i] += a[j].first;
            }
        }
        maxP = max(maxP, point[i]);
    }

    int cnt = 0;
    vector<int> ans(n);
    rep(i,n){
        cnt = 0;
        if(point[i]==maxP){
            ans[i] = 0;
        }else{
            rep(j,m){
                if(s[i][a[j].second]=='x'){
                    point[i] = point[i] + a[j].first;
                    cnt++;
                }
                if(point[i]>=maxP){
                    ans[i] = cnt;
                    break;
                }
            }
        }
    }

    rep(i,n){
        cout << ans[i] << endl;
    }
}