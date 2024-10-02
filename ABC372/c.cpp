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
    int n,q;
    cin >> n >> q;
    string s;
    string t = "ABC";
    vector<int> x(q);
    vector<char> c(q);
    cin >> s;
    rep(i,q){
        cin >> x[i] >> c[i];
        x[i]--;
    }

    int ans = 0;
    int siz = s.size();

    bool check = false;
    int cnt = 1;

    rep(i,siz){
        if(check){
            if(s[i] == t[cnt]) cnt++;
            else{
                check = false;
                cnt = 1;
            }
        }
        if(s[i] == t[0]) check = true;
        if(cnt == 3){
            ans++;
            cnt = 1;
            check = false;
        }
    }


    rep(i,q){
        if(s[x[i]] == c[i]){
            cout << ans << endl;
            continue;
        }
        if(s[x[i]] == 'A'){
            if(x[i] + 2 <= siz - 1){
                if(s[x[i]+1] == 'B' && s[x[i]+2] == 'C') ans--;
            }
        }
        if(s[x[i]] == 'B'){
            if(x[i] + 1 <= siz - 1 && x[i] - 1 >= 0){
                if(s[x[i]-1] == 'A' && s[x[i]+1] == 'C') ans--;
            }
        }
        if(s[x[i]] == 'C'){
            if(x[i] - 2 >= 0){
                if(s[x[i]-2] == 'A' && s[x[i]-1] == 'B') ans--;
            }
        }

        s[x[i]] = c[i];

        if(c[i] == 'A'){
            if(x[i] + 2 <= siz - 1){
                if(s[x[i]+1] == 'B' && s[x[i]+2] == 'C') ans++;
            }
        }
        if(c[i] == 'B'){
            if(x[i] + 1 <= siz - 1 && x[i] - 1 >= 0){
                if(s[x[i]-1] == 'A' && s[x[i]+1] == 'C') ans++;
            }
        }
        if(c[i] == 'C'){
            if(x[i] - 2 >= 0){
                if(s[x[i]-2] == 'A' && s[x[i]-1] == 'B') ans++;
            }
        }
        cout << ans << endl;
    }
}