#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> s[i] >> a[i];
    }
    int minYear = 1000000010;
    int minN = 0;
    for(int i=0;i<n;i++){
        if(minYear > a[i]){
            minYear = a[i];
            minN = i;
        }
    }
    for(int i=0;i<n;i++){
        if(i+minN>=n){
            minN = -1*i;
            cout << s[i+minN] << endl;
        }else{
            cout << s[i+minN] << endl;
        }
    }
}