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
    int m;
    cin >> m;
    vector<int> a;
    int cnt = 0;
    while(true){
        if(m == 0) break;
        cnt = 0;
        int tmp = m;
        while(true){
            if(tmp < 3){
                m -= pow(3,cnt);
                a.push_back(cnt);
                break;
            }else{
                cnt++;
                tmp /= 3;
            }
        }
    }
    cout << a.size();
    cout << endl;
    rep(i,a.size()){
        cout << a[i] << " ";
    }
}