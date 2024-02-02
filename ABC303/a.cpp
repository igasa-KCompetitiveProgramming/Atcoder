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
    string s,t;
    cin >> s >> t;
    rep(i,s.size()){
        if(s[i] == t[i]){
            continue;
        }else if(s[i]=='o'&&t[i] == '0'){
            continue;
        }else if(s[i]=='0'&&t[i]=='o'){
            continue;
        }else if(s[i]=='1'&&t[i]=='l'){
            continue;
        }else if(s[i]=='l'&&t[i]=='1'){
            continue;
        }
        cout << "No";
        return 0;
    }
    cout << "Yes";
}