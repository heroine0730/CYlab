#include <cstdio>
#include <algorithm>
using namespace std;

inline int readNum(){
    int x=0, f=1; char ch;
    do{ch = getchar(); if(ch=='-') f = -1;} while(ch<'0'||ch>'9');
    do{x = x*10 + ch-48; ch = getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int main(void){
    int n, q, temp;
    int heights[50000]; // non-decreasing
    int tc[25000];
    n = readNum();
    for(int i=0; i<n; i++) heights[i] = readNum();
    q = readNum();
    for(int i=0; i<q; i++) tc[i] = readNum();

    for(int i=0; i<q; i++){

        int* lo = lower_bound(heights, heights+n, tc[i]); // >= tc[i]
        int* up = upper_bound(heights, heights+n, tc[i]);
        if(lo == heights) printf("X");
        else printf("%d", *(lo-1));
        if(up == heights+n) printf(" X\n");
        else printf(" %d\n", *up); 

    }
}