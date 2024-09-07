#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    int cnt = 0;
    while(true){
        sort(a.rbegin(),a.rend());
        if(a[1] <= 0){
            cout << cnt << endl;
            return 0;
        }else{
            cnt++;
            a[0]--;
            a[1]--;
        }
    }
}