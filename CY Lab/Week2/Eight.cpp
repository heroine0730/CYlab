#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 362880

struct Node {
    vector<int> m;
    int X;
    int idx;
    int par_idx;
    char op;
} node[MAX+3];
bool visited[MAX+3];
vector<int> fact= {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int encode(const vector<int>& perm) {
    int n = perm.size();
    
    vector<bool> used(10, false);
    int rank = 0;

    // 計算排列的編碼
    for (int i = 0; i < n; i++) {
        int smaller = 0;

        // 計算小於 perm[i] 且未使用的數字個數
        for (int j = 0; j < perm[i]; j++) {
            if (!used[j]) {
                smaller++;
            }
        }

        rank += smaller * fact[n - i - 1]; // 加上對應階乘的權重
        used[perm[i]] = true;             // 標記當前數字已使用
    }
    return rank;
}

void reverse_print(int idx){
    if(node[idx].par_idx == -1) return;
    reverse_print(node[idx].par_idx);
    printf("%c", node[idx].op);
}

int main(void){
    // initializing
    vector<int> init;
    int x;
    for(int i=0; i<9; i++){
        char temp;
        scanf(" %c", &temp);
        if(temp == 'x'){
            init.push_back(0);
            x = i;
        } else {
            init.push_back(temp-'0');
        }
    }

    // solvable check
    int inversionCount = 0;
    // 計算逆序數
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (init[i] > init[j] && init[j] != 0) {
                inversionCount++;
            }
        }
    }
    if(inversionCount%2 != 0){
        printf("unsolvable\n");
        return 0;
    }

    int init_idx = encode(init);
    node[init_idx].m = init;
    node[init_idx].X = x;
    node[init_idx].idx = init_idx;
    node[init_idx].par_idx = -1;
    node[init_idx].op = 'i';
    visited[init_idx] = true;

    queue<Node> q;
    q.push(node[init_idx]);

    vector<int> g;
    g.push_back(1);
    g.push_back(2);
    g.push_back(3);
    g.push_back(4);
    g.push_back(5);
    g.push_back(6);
    g.push_back(7);
    g.push_back(8);
    g.push_back(0);
    int goal = encode(g);
    while(!q.empty()){
        Node temp = q.front();
        q.pop();

        if(temp.idx == goal){
            reverse_print(temp.idx);
            printf("\n");
            return 0;
        }

        // 4 operations
        if((temp.X - 3)>=0){ // can go up
            vector<int> test = temp.m;
            test[temp.X] = temp.m[temp.X-3];
            test[temp.X-3] = temp.m[temp.X];
            int new_idx = encode(test);
            if(!visited[new_idx]){
                visited[new_idx] = true;
                node[new_idx].m = test;
                node[new_idx].op = 'u';
                node[new_idx].idx = new_idx;
                node[new_idx].par_idx = temp.idx;
                node[new_idx].X = temp.X-3;
                q.push(node[new_idx]);
            }
        }
        if((temp.X + 3) < 9){ // can go down
            vector<int> test = temp.m;
            test[temp.X] = temp.m[temp.X+3];
            test[temp.X+3] = temp.m[temp.X];
            int new_idx = encode(test);
            if(!visited[new_idx]){
                visited[new_idx] = true;
                node[new_idx].m = test;
                node[new_idx].op = 'd';
                node[new_idx].idx = new_idx;
                node[new_idx].par_idx = temp.idx;
                node[new_idx].X = temp.X+3;
                q.push(node[new_idx]);
            }
        }
        if(((temp.X - 1)>=0)&&(temp.X % 3 != 0)){ // can go left
            vector<int> test = temp.m;
            test[temp.X] = temp.m[temp.X-1];
            test[temp.X-1] = temp.m[temp.X];
            int new_idx = encode(test);
            if(!visited[new_idx]){
                visited[new_idx] = true;
                node[new_idx].m = test;
                node[new_idx].op = 'l';
                node[new_idx].idx = new_idx;
                node[new_idx].par_idx = temp.idx;
                node[new_idx].X = temp.X-1;
                q.push(node[new_idx]);
            }
        }
        if(((temp.X + 1) < 9)&&((temp.X + 1) % 3 != 0)){ // can go right
            vector<int> test = temp.m;
            test[temp.X] = temp.m[temp.X+1];
            test[temp.X+1] = temp.m[temp.X];
            int new_idx = encode(test);
            if(!visited[new_idx]){
                visited[new_idx] = true;
                node[new_idx].m = test;
                node[new_idx].op = 'r';
                node[new_idx].idx = new_idx;
                node[new_idx].par_idx = temp.idx;
                node[new_idx].X = temp.X+1;
                q.push(node[new_idx]);
            }
        }
    }
    printf("unsolvable\n");
}