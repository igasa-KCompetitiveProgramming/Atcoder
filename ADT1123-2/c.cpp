#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int main(){
    int n;
    int a[100000];
    int q;
    int b[3][100000];
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    cin >> q;
    rep(i,q){
        cin >> b[0][i];
        if(b[0][i]==1){
            cin >> b[1][i] >> b[2][i];
        }else{
            cin >> b[1][i];
            b[2][i] = -1;
        }
    }

    rep(i,q){
        if(b[0][i]==1){
            a[b[1][i]-1]=b[2][i];
        }else{
            cout << a[b[1][i]-1] << endl;
        }
    }
}