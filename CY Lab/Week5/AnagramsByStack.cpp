#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

char a[50], b[50], inst[50];
int lenA, lenB;
stack<char> s;

void dfs(int ap, int bp, int ip){
    if((bp >= lenB)&&(ap >= lenA)){
        // print out
        putchar(inst[0]);
        for(int i=1; i<ip; i++) {
            putchar(' ');
            putchar(inst[i]);
        }
        putchar('\n');
        return;
    }

    if(ap < (lenA)){
        s.push(a[ap]);
        inst[ip] = 'i';
        dfs(ap+1, bp, ip+1);
        s.pop();
    }
    if((!s.empty())&&(s.top() == b[bp])){
        s.pop();
        inst[ip] = 'o';
        dfs(ap, bp+1, ip+1);
        s.push(b[bp]);
    }
    return;
}

int main(void){
    while(gets(a)){
        gets(b);
        lenA = strlen(a);
        lenB = strlen(b);
        printf("[\n");
        if(lenA == lenB) dfs(0, 0, 0);
        printf("]\n");
    }
    return 0;
}