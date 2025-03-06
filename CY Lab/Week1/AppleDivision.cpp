#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll p[22];

ll find_min(int idx, ll sum1, ll sum2){
    if(idx == n) return abs(sum1-sum2);

    ll put1 = find_min(idx+1, sum1+p[idx], sum2);
    ll put2 = find_min(idx+1, sum1, sum2+p[idx]);
    return min(put1, put2);
}

ll read()
{
    ll ans = 0;
    ll sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            sign = -1;
            ch = getchar();
        }
        else
        {
            ch = getchar();
            return INT32_MAX;
        }
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = (ans << 1) + (ans << 3) + (ch & 0xF); // 10x = 2x+8x
        ch = getchar();
    }
    return ans * sign;
}

int main(void){

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        p[i] = read();
        printf("%lld ", p[i]);
    }
    
    ll minDiff = find_min(0, 0, 0);
    
    printf("%lld\n", minDiff);
    return 0;
}