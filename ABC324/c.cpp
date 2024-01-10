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
    int k;
    string t;
    cin >> k;
    cin >> t;
    vector<string> s(k);
    rep(i,k){
        cin >> s[i];
    }

    int Tsize = t.size();
    int Ssize;
    int ans = 0;
    vector<int> ansList;

    rep(i,k){
        Ssize = s[i].size();
        if(Ssize==Tsize&&s[i]==t){
            ans++;
            ansList.push_back(i);
        }else if(Ssize==Tsize){
            rep(j,Ssize){
                if(s[i][j]!=t[j]){
                    s[i][j] = t[j];
                    if(s[i]==t){
                        ans++;
                        ansList.push_back(i);
                        break;
                    }else{
                        break;
                    }
                }
            }
        }else if(Ssize+1==Tsize){
            if(t[0]+s[i]==t){
                ans++;
                ansList.push_back(i);
                continue;
            }
            rep(j,Ssize){
                if(s[i][j]!=t[j]){
                    s[i].insert(s[i].begin()+j,t[j]);
                    if(s[i]==t){
                        ans++;
                        ansList.push_back(i);
                        break;
                    }else{
                        break;
                    }
                }
                if(j==Ssize-1){
                    s[i].push_back(t[Tsize-1]);
                    if(s[i]==t){
                        ans++;
                        ansList.push_back(i);
                        break;
                    }else{
                        break;
                    }
                }
            }
        }else if(Ssize==Tsize+1){
            rep(j,Tsize){
                if(s[i][j]!=t[j]){
                    s[i].erase(s[i].begin()+j);
                    if(s[i]==t){
                        ans++;
                        ansList.push_back(i);
                        break;
                    }else{
                        break;
                    }
                }
                if(j==Tsize-1){
                    s[i].pop_back();
                    if(s[i]==t){
                        ans++;
                        ansList.push_back(i);
                        break;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    rep(i,ansList.size()){
        cout << ansList[i]+1 << " ";
    }
}