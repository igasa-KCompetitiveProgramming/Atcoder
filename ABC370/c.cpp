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
    string s,t;
    cin >> s >> t;
    vector<string> x;
    while(true){
        bool check = false;
        rep(i,s.size()){
            if(s[i] > t[i]){
                s[i] = t[i];
                x.push_back(s);
                check = true;
                break;
            }
        }
        if(check) continue;
        else break;
    }
    while(true){
        bool flag = false;
        rep(i,s.size()){
            if(s[s.size()-i-1] != t[s.size()-i-1]){
                s[s.size()-i-1] = t[s.size()-i-1];
                x.push_back(s);
                flag = true;
                break;
            }
        }
        if(!flag) break;
    }
    cout << x.size() << endl;
    rep(i,x.size()){
        cout << x[i] << endl;
    }
}