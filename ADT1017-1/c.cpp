#include <cstdio>
#include <iostream>
#include <string>
#include <cmath> 
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    string str;
    cin >> str;
    vector<char> s(str.begin(), str.end());
    sort(s.begin(),s.end());
    for(auto item : s){
        cout << item;
    }
}