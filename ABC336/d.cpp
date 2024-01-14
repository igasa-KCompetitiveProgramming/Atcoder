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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }

    int ans = 1;
    int cnt = 1;
    int checkingPoint[2];
    int maximum;
    int dx[2] = {1,-1};

    if(n%2==0){
        rep(i,n/2-1){
            checkingPoint[0] = n/2+i*dx[0];
            checkingPoint[1] = n/2-1+i*dx[1];
            cout << checkingPoint[0] << " " << checkingPoint[1] << endl;
            rep(k,2){
                maximum = a[checkingPoint[k]];
                cnt = 1;
                rep(j,n/2-1){
                    if(maximum-1<=a[checkingPoint[k]+dx[0]+j]&&maximum-1<=a[checkingPoint[k]+dx[1]-j]){
                        maximum = max(a[checkingPoint[k]+dx[0]+j],a[checkingPoint[k]+dx[1]-j]);
                        maximum = min(maximum,a[checkingPoint[k]]);
                        cnt++;
                    }else{
                        ans = max(ans,cnt);
                        break;
                    }
                }
            }
            if(ans>=n/2-1)break;
        }
        cout << ans << endl;
    }else{
        rep(i,n/2-1){
            if(i==0){
                cnt = 1;
                if(a[n/2]-1<=a[n/2-1]&&a[n/2]-1<=a[n/2+1]){
                    cnt++;
                    maximum = min(a[n/2-1],a[n/2+1]);
                    maximum = min(maximum,a[n/2]);
                    cout << cnt << endl;
                }else{
                    ans = max(ans,cnt);
                    break;
                }
            }else{
                cout << "b" << endl;
                checkingPoint[0] = n/2+i*dx[0];
                checkingPoint[1] = n/2+i*dx[1];
                rep(k,2){
                    rep(j,n/2-1){
                        if(maximum-1<=a[checkingPoint[k]+dx[0]+j]&&maximum-1<=a[checkingPoint[k]+dx[1]-j]){
                            maximum = min(a[checkingPoint[k]+dx[0]+j],a[checkingPoint[k]+dx[1]-j]);
                            maximum = min(maximum,a[checkingPoint[k]]);
                            cnt++;
                        }else{
                            ans = max(ans,cnt);
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

}