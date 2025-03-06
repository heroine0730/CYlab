#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {           // Node of Trie
    Node *next[11];     // refer to the freq of the character
    vector<int> strIdx; // in the end of the trie, record the str's idx
    Node () {
        memset(next, 0, sizeof(next));
    }
};

char str[15002][11];
char ans[50][11];
int charCnt[15002][26];
int tempCnt[26];
bool cleared[15002];
Node *head;

int cmp(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

void insertNode(int idx){
    Node *temp = head;
    for(int i=0; i<26; i++){
        if(temp->next[charCnt[idx][i]]==NULL){
            temp->next[charCnt[idx][i]] = new Node();
        }
        temp = temp->next[charCnt[idx][i]];
    }
    if(temp == NULL) temp = new Node();
    temp->strIdx.push_back(idx);
    return;
}
void clearNode(int idx){
    Node *temp = head;
    for(int i=0; i<26; i++){
        if(temp->next[tempCnt[i]] == NULL) return;
        temp = temp->next[tempCnt[i]];
    }
    if(temp == NULL) return;

    for(auto it = temp->strIdx.begin(); it!=temp->strIdx.end(); it++){
        if((*it) == idx) continue;
        cleared[*it] = true;
    }
    temp->strIdx.clear();
    return;
}

// DFS for traversing all possible combination consist by the idx-th string
//   idx: the idx-th string
//   i  : currently on the i-th alphabet
void dfs(int idx, int i){
    if(i == 26){        // when i=26, we have done the iteration.
                        // we should clear the node which is dominated by the current string
        if (memcmp(tempCnt, charCnt[idx], sizeof(tempCnt)) != 0) {
            clearNode(idx);
        }
        return;
    }
    
    for(int j=0; j<=charCnt[idx][i]; j++){
        tempCnt[i] = j;
        dfs(idx, i+1);
    }
}

int main(void){
    int n = 0;
    head = new Node();
    while(gets(str[n])){
        for(int i=0; str[n][i]; i++) ++charCnt[n][str[n][i]-'a'];
        insertNode(n);
        n++;
    }
    for(int i=0; i<n; i++){
        dfs(i, 0);
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(!cleared[i]) strcpy(ans[cnt++], str[i]);
    }
    qsort(ans, cnt, sizeof(ans[0]), cmp);
    for(int i=0; i<cnt; i++){
        puts(ans[i]);
    }

    return 0;
}