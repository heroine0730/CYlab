#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char key[44] = "the quick brown fox jumps over the lazy dog";
const int keyLen = 44;
char sen[115][88];
char map[26];
int Size;

bool find(){
    vector<int> rec;
    for(int i=0; i<Size; i++){
        if(strlen(sen[i])==keyLen){
            rec.push_back(i);
        }
    }
    if(rec.empty()) {
        return false;
    }
    bool flag = 1;
    for(auto it = rec.begin(); it!=rec.end();){
        for(int j=0; sen[*it][j]; j++){
            if((key[j]==' ')&&(sen[*it][j]!=' ')){
                it = rec.erase(it);
                flag = 0;
                break;
            }
            if((key[j]!=' ')&&(sen[*it][j]==' ')){
                it = rec.erase(it);
                flag = 0;
                break;
            }
        }
        if(flag) it++;
    }
    if(rec.empty()){
        return false;
    }

    for(auto it = rec.begin(); it!=rec.end(); it++){
        bool flag = 1;
        memset(map, 0, sizeof(map));
        for(int j=0; sen[*it][j]; j++){
            if(sen[*it][j]>'z' || sen[*it][j]<'a') continue;
            if(!map[sen[*it][j]-'a']) {
                map[sen[*it][j]-'a'] = key[j];
            }
            else{
                if(key[j] != map[sen[*it][j]-'a']) {
                    flag = 0;
                }
            }
        }
        if(flag) return true;
    }
    return false;
}

int main(void){

    int test;
    scanf("%d", &test);
    getchar();
    getchar();
    while(test--){
        Size=0;
        while(fgets(sen[Size], 88, stdin)) {
            // putchar(sen[Size][0]);
            if(sen[Size][0] == '\n') break;
            ++Size;
        }
        
        if(!find()) printf("No solution.\n");
        else{
            for(int i=0; i<Size; i++){
                for(int j=0; sen[i][j]; j++){
                    if(sen[i][j] == ' ') printf(" ");
                    else printf("%c", map[sen[i][j]-'a']);
                }
                printf("\n");
            }
        }
        if(test) printf("\n");
    }
}