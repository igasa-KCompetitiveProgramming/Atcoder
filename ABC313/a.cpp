#include <iostream>
using namespace std;
int main(void){
    int n;
    int p1;
    int p[99];
    int add = 0;
    cin >> n;
    cin >> p1;
    for(int i=0;i<n-1;i++){
        cin >> p[i];
    }
    
    for(int i=1;i<n-1;i++){
        if(p[0]<p[i]){
            p[0] = p[i];
        }
    }
    
    if(p[0]>p1-1){
        add = p[0]-p1+1;
    }else{
        add = 0;
    }
    cout << add;
}
