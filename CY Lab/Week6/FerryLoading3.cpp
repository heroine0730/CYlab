#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef struct _node{
    int id;
    int t_in, t_out;
} Node;
Node car[10003];

int main(void){
    int test;
    scanf("%d", &test);

    int n, t, m;
    int curTime;
    bool curSide;
    bool first = true;
    char s[10];

    while(test--){
        if(!first){
            printf("\n");
        }
        first = false;
        queue<Node> q[2]; //0-left, 1-right
        scanf("%d%d%d", &n, &t, &m);
        for(int i=0; i<m; i++){
            scanf("%d%s", &car[i].t_in, s);
            car[i].id = i;
            if(s[0]=='l') q[0].push(car[i]);
            else q[1].push(car[i]);
        }
        
        curTime = 0;
        curSide = 0;
        while(!q[0].empty() || !q[1].empty()){
            // printf("time %d side %d ", curTime, curSide);
            if(q[curSide].empty()){
                // printf("a ");
                curTime = max(q[!curSide].front().t_in, curTime)+t;
                curSide = !curSide;
            }else{
                if(q[curSide].front().t_in <= curTime){ // can deliver
                    for(int i=0; (i<n)&&(!q[curSide].empty())&&(q[curSide].front().t_in<=curTime); i++){
                        // printf("set %d, %d\n", q[curSide].front().id, curTime+t);
                        car[q[curSide].front().id].t_out = curTime+t;
                        q[curSide].pop();
                    }
                    curTime += t;
                    curSide = !curSide;
                }else{
                    if(q[!curSide].empty()){
                        // printf("b ");
                        curTime = q[curSide].front().t_in;
                    }else{
                        if(q[!curSide].front().t_in <= curTime){
                            // printf("c ");
                            curTime += t;
                            curSide = !curSide;
                        }else{
                            if(q[curSide].front().t_in <= q[!curSide].front().t_in){
                                // printf("d ");
                                curTime = q[curSide].front().t_in;
                                curSide = curSide;
                            }else{
                                // printf("e ");
                                curTime = q[!curSide].front().t_in + t;
                                curSide = !curSide;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            printf("%d\n", car[i].t_out); 
        }
    }
}