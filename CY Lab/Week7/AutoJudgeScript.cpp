#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    int n, m, cnt = 0;
    bool AC, PE;
    string temp;
    while(cin >> n){
        if(n == 0) break;
        
        vector<string> ans, out;
        string ansNum, outNum;
        int ansLen, outLen;
        cnt ++;
        cin.ignore();
        while(n--){
            getline(cin, temp);
            ans.emplace_back(temp);
        }
        cin >> m;
        cin.ignore();
        while(m--){
            getline(cin, temp);
            out.emplace_back(temp);
        }
        
        if(ans == out){
            cout << "Run #" << cnt << ": Accepted\n";
        }else{
            for(auto i : ans){
                for(auto j : i)
                if((j>='0')&&(j<='9')) ansNum += j;
            }
            for(auto i : out){
                for(auto j : i)
                if((j>='0')&&(j<='9')) outNum += j;
            }
            if(ansNum == outNum) cout << "Run #" << cnt << ": Presentation Error\n";
            else cout << "Run #" << cnt << ": Wrong Answer\n";
        }
    }
}