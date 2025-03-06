// -- 解法
// 用一個vector來存每一個字元在原本字串的位置
// O(100000)
// -- 技巧
// | upper_bound(from, to, val) -> 找到大於val的最近位置
// | 一次做所有的input並一次輸出
//    比每一個回圈中輸入一次然後運算然後再輸入一次還要快 (IO burst)

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    char s[1000005];
    char ss[3505][105];
    int outL[3505];
    int outH[3505];
    vector<int> alpCnt[128];
    int test;

    fgets(s, 1000005, stdin);
    scanf("%d", &test);
    getchar();
    for(int i=0; i<test; i++){
        fgets(ss[i], 105, stdin);
    }
    for(int i=0; s[i]; i++){
        alpCnt[s[i]].push_back(i);
    }

    for(int cs = 0; cs < test; cs++){
        outH[cs]=-1, outL[cs]=-1;

        for(int i=0; ss[cs][i]!='\n'; i++){
            vector<int>::iterator it = upper_bound(alpCnt[ss[cs][i]].begin(), alpCnt[ss[cs][i]].end(), outH[cs]);
            if(it == alpCnt[ss[cs][i]].end()) {
                outH[cs]=-1, outL[cs]=-1;
                break;
            }
            outH[cs] = *it;
            // printf("ss[i]= %c j=%d\n", ss[i], j);
            if(outL[cs]==-1) {
                outL[cs] = outH[cs];
            }
        }
    }

    for(int i=0; i<test; i++){
        if((outH[i]==-1)||(outL[i]==-1)) printf("Not matched\n");
        else printf("Matched %d %d\n", outL[i], outH[i]);

    }

    return 0;
}