#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <string>
using namespace std;

vector<bool> sieve(10000, false);
void eratosthenes()
{
	int sqrt_9999 = sqrt(9999);
	sieve[0] = sieve[1] = true;
	for (int i=2; i<=sqrt_9999; i++)
		if (!sieve[i])
			for (int k=(9999)/i, j=i*k; k>=i; k--, j-=i)
				if (!sieve[k])
					sieve[j] = true;
}

int bfs(int init, int goal){
    vector<int> cnt(10000, -1);
    queue<int> q;
    cnt[init] = 0;
    q.push(init);
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        string mod;
        int nxt;
        for(int i=0; i<4; i++){
            for(int j=0; j<=9; j++){
                if(j == 0 && i == 0) continue;  // 跳過把第一位改成0的情況
                // mod = to_string(cur);
                // mod[i] = j+'0';
                // nxt = stoi(mod);
                // 換成數字直接轉換
                // 用數字處理四個位數
                int d = cur / pow(10, 3-i); // 取得要修改的位數
                d = d % 10; // 若不是第一位，要 mod 10
                int diff = (j - d) * pow(10, 3-i); // 計算差值
                nxt = cur + diff;  // 修改該位數

                if(nxt == goal) return cnt[cur]+1;
                if((cnt[nxt] != -1)||(nxt < 1000)||(sieve[nxt])) continue;
                cnt[nxt] = cnt[cur] + 1;
                q.push(nxt);
                //printf("%d: %d\n", cnt[nxt], nxt);
            }
        }
    }
    return -1;
}

int main(void){
    int t;
    scanf("%d", &t);

    eratosthenes();
    while(t--){
        int init, goal;
        scanf("%d%d", &init, &goal);
        if(init == goal){
            printf("0\n");
            continue;
        }
        int ret = bfs(init, goal);
        if(ret == -1) printf("Impossible\n");
        else printf("%d\n", ret);
    }

    return 0;
}