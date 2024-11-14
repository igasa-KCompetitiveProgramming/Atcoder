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
    ll n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    map<int,map<int,int>> mp2;
    rep(i,m){
        rep(j,3){
            rep(k,3){
                if(j == k) continue;
                if(j == 0 || k == 0) continue;
                int h = a[i] + j;
                int w = b[i] - k;
                if(h < 0 || h >= n || w < 0 || w >= n) continue;
                else mp2[h][w]++;
            }
        }

        rep(j,3){
            rep(k,3){
                if(j == k) continue;
                if(j == 0 || k == 0) continue;
                int h = a[i] - j;
                int w = b[i] + k;
                if(h < 0 || h >= n || w < 0 || w >= n) continue;
                else mp2[h][w]++;
            }
        }

        rep(j,3){
            rep(k,3){
                if(j == k) continue;
                if(j == 0 || k == 0) continue;
                int h = a[i] + j;
                int w = b[i] + k;
                if(h < 0 || h >= n || w < 0 || w >= n) continue;
                else mp2[h][w]++;
            }
        }

        rep(j,3){
            rep(k,3){
                if(j == k) continue;
                if(j == 0 || k == 0) continue;
                int h = a[i] - j;
                int w = b[i] - k;
                if(h < 0 || h >= n || w < 0 || w >= n) continue;
                else mp2[h][w]++;
            }
        }

        int h = a[i]; int w = b[i];
        if(h < 0 || h >= n || w < 0 || w >= n) continue;
        else mp2[h][w]++;
    }
    ll ans = n;
    ans *= n;
    for(auto x: mp2){
        ans -= x.second.size();
    }
    cout << ans << endl;
}