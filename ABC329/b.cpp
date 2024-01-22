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
    vector<int> a;
    int x[100];
    cin >> n;
    rep(i, n){
        cin >> x[i];
        a.push_back(x[i]);
    }
    int max=0;
    int max2 = 0;
    int count = 0;
    sort(a.rbegin(),a.rend());
    max = a[0];
    rep(i, n){
        if(max2<a[i]&&max!=a[i]){
            max2 = a[i];
        }
    }
    cout <<  max2;
}