#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
inline int readNum(){
    int x=0, f=1; char ch;
    do{ch = getchar(); if(ch=='-') f = -1;} while(ch<'0'||ch>'9');
    do{x = x*10 + ch-48; ch = getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
inline void writeNum(int num) {
    if (num == 0) { putchar_unlocked('0'); return; }
    char buffer[10]; int idx = 0;
    while (num) { buffer[idx++] = '0' + (num % 10); num /= 10; }
    while (idx--) { putchar_unlocked(buffer[idx]); }
}

int main(void){
    int n, q, temp;
    int tc = 1;
    int marbles[10000];
    vector< pair<int, int> > ans[70];
    while(1){
        n = readNum();
        q = readNum();
        if(!(n|q)) break;

        for(int i=0; i<n; i++){
            marbles[i] = readNum();
        }
        sort(marbles, marbles+n);
        // printf("CASE# %d:\n", tc);
        for(int i=0; i<q; i++){
            temp = readNum();
            auto lo = lower_bound(marbles, marbles+n, temp);
            if((*lo) == temp) {
                ans[tc].push_back(make_pair(temp, lo-marbles+1));
                // printf("%d found at %d\n", temp, (int)(lo-marbles+1));
            }else{
                ans[tc].push_back(make_pair(temp, -1));
                // printf("%d not found\n", temp);
            }
        }
        tc++;
    }
    for(int i=1; i<tc; i++){
        printf("CASE# %d:\n", i);
        for(auto it : ans[i]) {
            if(it.second == -1){
                writeNum(it.first);
                putchar_unlocked(' ');
                putchar_unlocked('n'); putchar_unlocked('o'); putchar_unlocked('t');
                putchar_unlocked(' '); 
                putchar_unlocked('f'); putchar_unlocked('o'); putchar_unlocked('u'); putchar_unlocked('n'); putchar_unlocked('d');
                putchar_unlocked('\n');
            }else{
                writeNum(it.first);
                putchar_unlocked(' '); 
                putchar_unlocked('f'); putchar_unlocked('o'); putchar_unlocked('u'); putchar_unlocked('n'); putchar_unlocked('d');
                putchar_unlocked(' ');
                putchar_unlocked('a'); putchar_unlocked('t');
                putchar_unlocked(' ');
                writeNum(it.second);
                putchar_unlocked('\n');
            }
        }
    }
}