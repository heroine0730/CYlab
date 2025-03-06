#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

inline int readNum(){
    int x=0, f=1; char ch;
    do{ch = getchar(); if(ch=='-') f = -1;} while(ch<'0'||ch>'9');
    do{x = x*10 + ch-48; ch = getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int main(void){
    int t;
    int cnt = 1;
    int numInTeam[1000000];

    while(scanf("%d", &t), t){
        int num, temp;
        char s[50];
        queue<int> team;
        queue<int> q[1000];

        for(int i=0; i<t; i++){
            // scanf("%d", &num);
            num = readNum();
            while(num--){
                temp = readNum();
                numInTeam[temp] = i;
            }
        }
        printf("Scenario #%d\n", cnt++);
        // while(scanf("%s", s), s[0]!='S'){
        while(1){
            gets(s);
            if(s[0] == 'S') break;
            if(s[0] == 'E'){
                // scanf("%d", &temp);
                temp = 0;
                for(int i=8; ((s[i]>='0')&&(s[i]<='9')); i++){
                    // printf("s[i] = %c\n", s[i]);
                    temp = temp*10 + s[i]-48;
                }
                // printf("temp = %d\n", temp);
                if(q[numInTeam[temp]].empty()){
                    q[numInTeam[temp]].push(temp);
                    team.push(numInTeam[temp]);
                }else{
                    q[numInTeam[temp]].push(temp);
                }
            }
            if(s[0] == 'D'){
                // printf("%d\n", q[team.front()].front());
                int x = q[team.front()].front();
                static int sta[35];
                int top = 0;
                do {
                    sta[top++] = x % 10, x /= 10;
                } while (x);
                while (top) putchar(sta[--top] + 48);  // 48 是 '0'
                putchar('\n');
                
                q[team.front()].pop();
                if(q[team.front()].empty()) team.pop();
            }
        }
        printf("\n");
    }
}