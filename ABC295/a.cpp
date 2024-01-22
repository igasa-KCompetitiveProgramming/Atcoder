#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        if(s[i]=="and"||s[i]=="not"||s[i]=="that"||s[i]=="the"||s[i]=="you"){
        cout << "Yes";
        return 0;
        }
    }
    cout << "No";
}