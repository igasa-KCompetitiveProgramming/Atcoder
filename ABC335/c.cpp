#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    int n,q;
    cin >> n >> q;
    vector<int> x(2000000),y(2000000);
    int count = n-1;
    string s[200000];
    int f[200000];
    rep(i,q){
        cin >> f[i];
        cin >> s[i];
    } 
    rep(i,n){
        x[i] = n - i;
        y[i] = 0;
    }

    rep(i,q){
        if(f[i]==1){
            count++;
            if(s[i]=="U"){
                x[count] = x[count-1];
                y[count] = y[count-1]+1;
            }else if(s[i]=="D"){
                x[count] = x[count-1];
                y[count] = y[count-1]-1;
            }else if(s[i]=="R"){
                x[count] = x[count-1]+1;
                y[count] = y[count-1];
            }else if(s[i]=="L"){
                x[count] = x[count-1]-1;
                y[count] = y[count-1];
            }
            
        }else{
            int tmp = stoi(s[i],nullptr,10);
            cout << x[count - tmp + 1] << " " << y[count - tmp + 1] << endl;
        }
    }
}