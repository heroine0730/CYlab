#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct PhoneNum {
    char phoneNum[11];
};
struct Node {
    char num;
    bool end;
    int next[10];
    Node () {
        // for(int i=0; i<10; i++) next[i] = -1;
        memset(next, 0, sizeof(int));
        end = false;
    }
};
PhoneNum in[10005];
Node node[100000];
int pt;

bool insertNode(int idx){
    int cur = 0;
    
    for(int i=0; i<strlen(in[idx].phoneNum); i++){
        if(node[cur].next[in[idx].phoneNum[i]-'0']==(0)){
            node[cur].next[in[idx].phoneNum[i]-'0'] = pt;
            // printf("1cur %d, ch %c at node[%d]\n", cur, in[idx].phoneNum[i], node[cur].next[in[idx].phoneNum[i]-'0']);
            cur = pt;
            pt++;
        }else{
            // printf("2cur %d, ch %c at node[%d]\n", cur, in[idx].phoneNum[i], node[cur].next[in[idx].phoneNum[i]-'0']);
            if(node[node[cur].next[in[idx].phoneNum[i]-'0']].end) return true;
            cur = node[cur].next[in[idx].phoneNum[i]-'0'];
        }
    }
    node[cur].end = true;
    // printf("done\n");
    return false;
}

int main(void){
    int t;
    int n;
    
    scanf("%d", &t);
    pt = 0;
    while(t--){
        for(int i=0; i<pt; i++){
            node[i].end = false;
            memset(node[i].next, 0, sizeof(int));
        }
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%s", in[i].phoneNum);
        sort(in, in + n, [](const PhoneNum &a, const PhoneNum &b) {
            return strlen(a.phoneNum) < strlen(b.phoneNum);
        });

        bool flag = false;
        pt = 1;
        for(int i=0; i<n; i++){
            if(insertNode(i)){
                flag = true;
                break;
            }
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
}