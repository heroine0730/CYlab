#include <cstdio>
using namespace std;

const int MAX = 2e5;
#define MOD 10007

char str[MAX];
int next[MAX];
int pre[MAX];

int main(void){
    int t;
    
    scanf("%d", &t);
    while(t--){
        int len;
        scanf("%d ", &len);
        fread(str, 1, len, stdin);
        // printf("test: %s\n", str);

        int res = len;
        next[0] = -1;
        pre[0] = 0;
        int j = -1; // j: point to the LPS array
        for (int i = 1; i < len; i++) { // i: traverse through the word
            while (j > -1 && str[i] != str[j + 1]) {
                j = next[j];
            }
            if (str[i] == str[j + 1]) {
                j++;
            }
            next[i] = j;

            pre[i] = (j==-1)? 0: (1+pre[next[i]])%MOD;
            res = (res+pre[i]);
        }
        res = res%MOD;
        printf("%d\n", res);
    }
}