#include <cstdio>
using namespace std;

typedef long long ll;

// read long long int
inline int readNum(){
    int x=0, f=1; char ch;
    do{ch = getchar(); if(ch=='-') f = -1;} while(ch<'0'||ch>'9');
    do{x = x*10 + ch-48; ch = getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
inline void writeNum(int num) {
    if (num == 0) { putchar('0'); return;}
    char buffer[10]; int idx = 0;
    while (num) { buffer[idx++] = '0' + (num % 10); num /= 10; }
    while (idx--) { putchar(buffer[idx]); }
}

// read a sentence with whitespaces
#define MAXLEN 1000
void readSen(){
    char a[100];
    fgets(a, MAXLEN, stdin);
}