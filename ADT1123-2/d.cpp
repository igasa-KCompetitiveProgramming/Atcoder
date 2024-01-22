#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int main(){
    int n,x;
    int a[100000];
    int f[100000]={};
    int tmp = 0;
    cin >> n >> x;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        if(i==0){
            f[x]=1;
            if(f[a[x]]==0){
                f[a[x]]=1;
                tmp = a[x];
            }else{
                f[x]=1;
                break;
            }
        }else{
            if(f[a[tmp]]==1){
                f[a[tmp]]=1;
                tmp = a[tmp];
            }else{
                f[tmp]=1;
                break;
            }
        }
    }
    f[tmp] = 1;
    int ans = 0;
    rep(i,n){
        if(f[i]==1){
            ans++;
        }
    }
    cout << ans;
}