#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void){
    int n;
    string inst;
    string name;
    stack<string> s;
    cin >> n;
    while(n--){
        cin >> inst;
        if(inst == "Sleep"){
            cin >> name;
            s.push(name);
        }else if(inst == "Kick"){
            if(!s.empty()) s.pop();
        }else{
            if(!s.empty()) cout << s.top() << endl;
            else cout << "Not in a dream\n";
        }
    }
}