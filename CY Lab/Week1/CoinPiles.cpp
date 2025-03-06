#include <iostream>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;

        bool flag = false;
        
        // need to satisfy 2 condition
        if(((a+b)%3)==0){
            if((a>=b)&&(a<=(b*2))) flag = true;
            if((b>a)&&(b<=(a*2))) flag = true;
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}