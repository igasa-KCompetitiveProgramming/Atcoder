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
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    rep(i,n){
        rep(j,i+1){
            rep(k,(n-i)/2){
                if(s[j+k]==s[j+n-i-1-k]){
                    cnt++;
                }
            }
            if(cnt==(n-i)/2){
                cout << n-i << endl;
                return 0;
            }
            cnt = 0; 
        }
    }
    cout << 0 << endl;
}