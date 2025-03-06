#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        char W[10003];
        int next[10003];
        char T[1000003];
        scanf(" %s %s", W, T);

        // deal with next[]
        next[0] = -1;
        int patLen = strlen(W);
        int optIdx = 0;
        for(int i=1; i<patLen; ++i){
            if(W[i] == W[optIdx]){
                next[i] = optIdx ++;
            }else if()
        }
    }
}