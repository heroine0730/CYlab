#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

enum Operation { FillA, FillB, EmptyA, EmptyB, PourAB, PourBA, Init};

struct State {
    int curA, curB;
    int preA, preB;
    int cnt;
    Operation op;
} node[102][102];

int A, B, goal;
bool visited[102][102];
queue<State> q;
int FoundA, FoundB;

int bfs(){

    auto q_push = [&](int curA, int curB, int preA, int preB, int cnt, Operation op) {
        visited[curA][curB] = true;
        node[curA][curB] = {curA, curB, preA, preB, cnt + 1, op};
        q.push(node[curA][curB]);
    };

    // init
    q_push(0, 0, -1, -1, -1, Init);

    State temp, next;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if((temp.curA == goal) || (temp.curB == goal)) {
            FoundA = temp.curA;
            FoundB = temp.curB;
            return temp.cnt;
        }
        
        // test
        // printf("%d (%d, %d)\n", temp.cnt, temp.curA, temp.curB);

        // performing operations
        // Fill
        if(!visited[A][temp.curB])
            q_push(A, temp.curB, temp.curA, temp.curB, temp.cnt, FillA);
        if(!visited[temp.curA][B])
            q_push(temp.curA, B, temp.curA, temp.curB, temp.cnt, FillB);
        // Empty
        if(!visited[0][temp.curB])
            q_push(0, temp.curB, temp.curA, temp.curB, temp.cnt, EmptyA);
        if(!visited[temp.curA][0])
            q_push(temp.curA, 0, temp.curA, temp.curB, temp.cnt, EmptyB);
        // Pour AB
        int A_rest = A - temp.curA;
        int B_rest = B - temp.curB;
        if((B_rest <= temp.curA) && (!visited[temp.curA-B_rest][B])){
            q_push(temp.curA-B_rest, B, temp.curA, temp.curB, temp.cnt, PourAB);
        } else if ((B_rest > temp.curA) && (!visited[0][temp.curB+temp.curA])){
            q_push(0, temp.curB+temp.curA, temp.curA, temp.curB, temp.cnt, PourAB);
        }
        // Pour BA
        if((A_rest <= temp.curB) && (!visited[A][temp.curB-A_rest])){
            q_push(A, temp.curB-A_rest, temp.curA, temp.curB, temp.cnt, PourBA);
        } else if ((A_rest > temp.curB) && (!visited[temp.curA+temp.curB][0])){
            q_push(temp.curA+temp.curB, 0, temp.curA, temp.curB, temp.cnt, PourBA);
        }
    }
    return -1;
}
void traceBack(int A, int B){
    if(node[A][B].cnt == 0) return;

    traceBack(node[A][B].preA, node[A][B].preB);
    switch (node[A][B].op){
        case FillA:
            printf("FILL(1)\n");
        break;
        case FillB:
            printf("FILL(2)\n");
        break;
        case EmptyA:
            printf("DROP(1)\n");
        break;
        case EmptyB:
            printf("DROP(2)\n");
        break;
        case PourAB:
            printf("POUR(1,2)\n");
        break;
        case PourBA:
            printf("POUR(2,1)\n");
        break;
        default:
            printf("Failed\n");
    }
    return;
}

int main(void){
    scanf("%d%d%d", &A, &B, &goal);
    if((goal > A) && (goal > B)) {
        printf("impossible\n");
        return 0;
    }
    int cnt = bfs();
    if(cnt == -1) {
        printf("impossible\n");
    }else{
        printf("%d\n", cnt);
        traceBack(FoundA, FoundB);
    }
}