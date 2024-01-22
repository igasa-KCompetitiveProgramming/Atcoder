#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(n + 1);
    rep(i,m){
        cin >> a[i];
    }

    int top = 0;
    rep(i,m){
        b[a[i]]++;
        if(b[a[i]]>b[top]){
            top = a[i];
        }else if(b[a[i]]==b[top]){
            top = min(a[i],top);
        }
        cout << top << endl;
    }
}