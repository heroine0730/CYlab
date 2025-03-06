// Produced by Shibuya.
// copyright All rights reserved.
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

const int MOD = 1e9 + 7;
const int BUF_SZ = 1 << 15;

inline namespace Input {
    char buf[BUF_SZ];
    int pos;
    int len;
    char next_char(){
        if(pos==len){
            pos = 0;
            len = (int)fread(buf, 1, BUF_SZ, stdin);
            if(!len) return EOF;
        }
        return buf[pos++];
    }
    bool readLine(char* line, int maxLen) {
        int idx = 0;
        char ch;
        while ((ch = next_char()) != EOF) {
            if (ch == '\n') break;
            if (idx < maxLen - 1) {
                line[idx++] = ch;
            }
        }
        line[idx] = '\0';
        return idx > 0 || ch != EOF;
    }
    int read_int(){
        int x;
        char ch;
        int sgn = 1;
        while(!isdigit(ch = next_char())){
            if(ch == '-') { sgn = -1; }
        }
        x = ch-'0';
        while(isdigit(ch = next_char())){ x = x * 10 + (ch-'0'); }
        return x * sgn;
    }
}
inline namespace Output{
    char buf[BUF_SZ];
    int pos;
    void flush_out(){
        fwrite(buf, 1, pos, stdout);
        pos = 0;
    }
    void write_char(char c){
        if(pos == BUF_SZ){ flush_out(); }
        buf[pos++] = c;
    }
    void write_string(const char* str) {
        while (*str) {
            write_char(*str++);
        }
    }
    void write_int(int x){
        static char num_buf[100];
        if(x<0){
            write_char('-');
            x *= -1;
        }
        int len = 0;
        for(; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x%10)); }
        write_char((char)'0' + x);
        while(len) { write_char(num_buf[--len]); }
        write_char('\n');
    }
    void init_output(){ assert(atexit(flush_out) == 0); }
}

#include <cstring>
using namespace std;

class Node{
    public:
    char c;
    int freq;
    Node *next[26];

    Node(char ch) : c(ch), freq(1) {
        memset(next, 0, sizeof(next)); // 將 next 陣列設為 nullptr
    }
};

int main(void){
    #ifndef ONLINE_JUDGE
    freopen("input. txt", "r", stdin):
    freopen("output.txt", "w", stdout):
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init_output();

    Node *root = new Node('-');

    int cnt=0;
    char input[1000][30];
    
    while(readLine(input[cnt], 30)){

        Node *cur = root;
        for(int j=0; j<strlen(input[cnt]); ++j){
            if(cur->next[input[cnt][j]-'a'] == NULL){
                Node *newNode = new Node(input[cnt][j]);
                cur->next[input[cnt][j]-'a'] = newNode;
            }else{
                ++cur->next[input[cnt][j]-'a']->freq;
            }
            cur = cur->next[input[cnt][j]-'a'];
        }
        ++cnt;
    }
    // printf("GO!!\n");
    for(int i=0; i<cnt; ++i){
        write_string(input[i]);
        write_char(' ');
        // printf("%s ", input[i]);
        int j=0;
        Node *cur = root;
        while(j<strlen(input[i])){
            if(cur->next[input[i][j]-'a']->freq==1){
                // printf("%c", input[i][j]);
                write_char(input[i][j]);
                break;
            }else{
                // printf("%c", input[i][j]);
                write_char(input[i][j]);
                cur = cur->next[input[i][j]-'a'];
            }
            ++j;
        }
        write_char('\n');
    }
}