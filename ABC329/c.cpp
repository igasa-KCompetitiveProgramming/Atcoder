#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int main(){
    int n;
    int ans = 0;
    string s;
    map<char, int> a;
    cin >> n;
    cin >> s;
    int check = 1;
    rep(i,n){
        if(s[i-1]!=s[i]){
            if(check>a[s[i-1]]){
            a[s[i-1]] = check;
            }
            check = 1;
        }else if(i==n-1){
            check++;
            if(check>a[s[i-1]]){
                a[s[i-1]] = check;
            }
        }else{
            check++;
        }
    }
    rep(i,27){
        ans += a['a'+i];
    }
    if(n!=1){
    cout << ans << endl;
    }else{
        cout << n << endl;
    }
}