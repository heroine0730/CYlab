#include <stack>
#include <cstdio>
using namespace std;

// IO optimization: 40ms -> 10ms
inline int read(){
    int x=0, f=1; char ch;
    do{ch = getchar(); if(ch=='-') f = -1;} while(ch<'0'||ch>'9');
    do{x = x*10 + ch-48; ch = getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int main(void){
    int len, temp, num, in[1003];
    stack<int> s;

    while(len = read(), len){
        while(temp = read(), temp){
            bool flag = true;

            in[1] = temp;
            for(int i=2; i<=len; i++) in[i] = read();

            int num = 1, goal = 1;
            while(!s.empty()) s.pop();
            while(goal < len){
                // printf("num: %d, coach: %d\n", num, in[goal]);
                if(in[goal] == num){
                    ++num; ++goal;
                }else if(!s.empty() && in[goal] == s.top()){
                    ++goal;
                    s.pop();
                }else if(num <= len){
                    s.push(num++);
                }else{
                    putchar('N');
                    putchar('o');
                    putchar('\n');

                    flag = false;
                    break;
                }
            }
            
            if(flag){
                putchar('Y');
                putchar('e');
                putchar('s');
                putchar('\n');
            }
        }
        putchar('\n');
    }
}