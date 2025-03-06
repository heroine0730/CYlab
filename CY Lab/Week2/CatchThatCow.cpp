#include <cstdio>
#include <queue>
using namespace std;
 
const int maxn = 100000;
int n, k, dis[maxn+1], now;
queue <int> q;
 
int main() {
    while (scanf("%d%d", &n, &k)!=EOF){
        if(n>k){
            printf("%d\n", n-k);
            continue;
        }
        memset(dis, 0x3F, sizeof(dis));
        q.push(n);
        dis[n] = 0;
        while (!q.empty()){
            now = q.front();
            q.pop();
            if (now+1 <= maxn && dis[now]+1 < dis[now+1]){
                dis[now+1] = dis[now]+1;
                q.push(now+1);
            }
            if (now-1 >= 0 && dis[now]+1 < dis[now-1]){
                dis[now-1] = dis[now]+1;
                q.push(now-1);
            }
            if (now*2 <= maxn && dis[now]+1 < dis[now*2]){
                dis[now*2] = dis[now]+1;
                q.push(now*2);
            }
        }
        printf("%d\n", dis[k]);
    }
}