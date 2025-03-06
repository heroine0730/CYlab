#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main(void){
    int test;
    scanf("%d", &test);

    int l, m, temp, coda;
    char s[10];
    bool curSide;
    int cnt;
    queue<int> q[2];
    while(test--){
        scanf("%d%d", &l, &m);
        while(m--){
            scanf("%d%s", &temp, s);
            if(s[0]=='l') q[0].push(temp);
            else q[1].push(temp);
        }

        l = l * 100;
        curSide = 0;
        cnt = 0;
        coda = l;
        while(!q[0].empty() || !q[1].empty()){
            // printf("side: %d, ", curSide);
            if(q[curSide].empty()){
                cnt++;
                curSide = !curSide;
            }else{
                while((!q[curSide].empty())&&((coda-q[curSide].front())>=0)){
                    // printf("pop %d\n", q[curSide].front());
                    coda = coda-q[curSide].front();
                    q[curSide].pop();
                }
                cnt++;
                curSide = !curSide;
                coda = l;
            }
        }
        printf("%d\n", cnt);
    }
}