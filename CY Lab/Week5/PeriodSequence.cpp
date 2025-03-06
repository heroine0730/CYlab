#include <cstdio>
#include <stack>
#include <map>
using namespace std;

char str[50];
stack<long long> s;

int main(void){

    long long N, n;
    long long cnt;
    long long x, i;
    long long prevRes;
    char ch;
    while(scanf("%lld", &N)){
        scanf("%lld", &n);
        gets(str);
        if(N == 0) break;
        
        cnt = 0;
        i = 0;
        prevRes = n;
        map<long long, long long> m;
        while(1){
            ch = str[i];
            if(ch == ' ') {
                i++;
                continue;
            } else if(ch == 'x') {
                s.push(prevRes);
            } else if(ch == 'N') {
                s.push(N);
            } else if((ch == '+')||(ch == '*')||(ch == '%')){
                long long a, b;
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                
                if(ch == '+') {
                    s.push((a+b)%N);
                } else if(ch == '*') {
                    s.push((a*b)%N);
                } else if(ch == '%') {
                    int res = b%a;
                    if(m.find(res) != m.end()){
                        printf("%lld\n", cnt - m[res]);
                        break;
                    }else{
                        m.insert(pair<long long, long long>(res, cnt));
                    }

                    ++cnt;
                    i = 0;
                    prevRes = res;
                    continue;
                }
            }else{
                // number
                x = 0;
                while(ch>='0'&&ch<='9'){ x = x*10 + ch-48; ch = str[++i]; }
                s.push(x);
            }
            i++;
        }
    }
}