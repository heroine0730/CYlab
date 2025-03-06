#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int MAX = 2e7;
char input[MAX];
bool hashVal[MAX];

int main(void){
    int n, nc;
    scanf("%d%d", &n, &nc);
    int i=0;
    getchar();
    fread(input, sizeof(char), MAX, stdin);
    
    bool visited[300] = {0};
    int charIdx[300];
    int idx = 0;
    int cnt = 0;
    int len = strlen(input)-1;

    int temp = 0;
    int maxBase = pow(nc, n-1);
    for(int i=0; i<n; ++i){
        if(!visited[input[i]]){
            visited[input[i]] = true;
            charIdx[input[i]] = idx;
            ++idx;
        }
        temp = temp * nc + charIdx[(int)input[i]];
    }
    hashVal[temp] = true;
    ++cnt;

    for(int i=n; i<len; ++i){
        if(!visited[input[i]]){
            visited[input[i]] = true;
            charIdx[input[i]] = idx;
            ++idx;
        }

        temp -= maxBase*charIdx[input[i-n]];
        temp *= nc;
        temp += charIdx[input[i]];
        if(!hashVal[temp]){
            hashVal[temp] = true;
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}