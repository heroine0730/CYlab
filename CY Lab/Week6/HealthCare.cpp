#include <cstdio>
#include <deque>
using namespace std;

int main(void){
    int p, c;
    int caseCnt = 1;
    char ch;
    while(scanf("%d%d", &p, &c), p&&c){
        printf("Case %d:\n", caseCnt++);
        deque<int> q;
        for(int i=1; i<=min(c, p); i++) q.push_back(i);

        for(int i=0; i<c; i++){
            scanf(" %c", &ch);
            if(ch=='N'){
                printf("%d\n", q.front());
                q.push_back(q.front());
                q.pop_front();
            }
            if(ch=='E'){
                int num;
                scanf("%d", &num);
                for(auto it=q.begin(); it!=q.end(); it++){
                    if(*it == num){
                        q.erase(it);
                        break;
                    }
                }
                q.push_front(num);
            }
        }
    }
}