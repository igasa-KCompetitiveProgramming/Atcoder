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
    int n,s,t;
    cin >> n >> s >> t;
    vector<vector<int>> a(n,vector<int>(4));
    rep(i,n){
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }
    vector<int> permi(n);
    bitset<6> b;
    rep(i,n){
        permi[i] = i;
    }
    long double ans = inf;
    do{
        rep(i,pow(2,n)){
            long double sum = 0;
            b = i;
            long double nx = 0;
            long double ny = 0;
            rep(j,n){
                long double x = nx;
                long double y = ny;
                if(b[j]){
                    sum += sqrt(pow(x-a[permi[j]][0],2)+pow(y-a[permi[j]][1],2))/s;
                    //cout << a[permi[j]][0] << " " << a[permi[j]][1] << " " << a[permi[j]][2] << " " << a[permi[j]][3] << endl;
                    //cout << sum << " ";
                    sum += sqrt(pow(a[permi[j]][0]-a[permi[j]][2],2)+pow(a[permi[j]][1]-a[permi[j]][3],2))/t;
                    nx = a[permi[j]][2];
                    ny = a[permi[j]][3];
                    //cout << sum << " ";
                }else{
                    sum += sqrt(pow(x-a[permi[j]][2],2)+pow(y-a[permi[j]][3],2))/s;
                    //cout << a[permi[j]][2] << " " << a[permi[j]][3] << " " << a[permi[j]][0] << " " << a[permi[j]][1] << endl;
                    //cout << sum << " ";
                    sum += sqrt(pow(a[permi[j]][0]-a[permi[j]][2],2)+pow(a[permi[j]][1]-a[permi[j]][3],2))/t;
                    nx = a[permi[j]][0];
                    ny = a[permi[j]][1];
                    //cout << sum << " ";
                }
            }
            ans = min(ans,sum);
        }
    }while(next_permutation(permi.begin(),permi.end()));
    cout << ans << endl;
}