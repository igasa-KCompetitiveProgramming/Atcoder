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
    vector<int> mod = {1,5,10,50,100,500};
    vector<int> num(6);
    rep(i,6){
        cin >> num[i];
    }
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n){
        cin >> x[i];
    }
    rep(i,5){
        int cnt = 0;
        int need = 0;
        rep(j,n){
            if(x[j] % mod[i+1] == 0){
                continue;
            }else{
                need += x[j] % mod[i+1];
            }
        }
        need /= mod[i];
        if(need > num[i]){
            cout << "No" << endl;
            return 0;
        }else{
            rep(j,n){
                x[j] -= (x[j] % mod[i+1]);
            }
            num[i] -= need;
            num[i+1] += (num[i]*mod[i])/mod[i+1];
        }
    }
    int tmp = 0;
    rep(i,n){
        tmp += x[i]/mod[5];
    }
    if(tmp > num[5]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}