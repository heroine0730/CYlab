#include <iostream>
using namespace std;

int main(void){
    int t;
    cin >> t;
    char str[50][1003];
    char res[1003];
    enum DNA {T, A, G, C};
    while(t--){
        int m, len;
        cin >> m >> len;
        for(int i=0; i<m; i++){
            cin >> str[i];
        }
        int cnt[4];
        int maxIdx;
        int error = 0;
        for(int i=0; i<len; i++){
            cnt[DNA::A] = 0;
            cnt[DNA::C] = 0;
            cnt[DNA::G] = 0;
            cnt[DNA::T] = 0;
            for(int j=0; j<m; j++){
                switch (str[j][i]){
                    case 'A': ++cnt[DNA::A]; break;
                    case 'C': ++cnt[DNA::C]; break;
                    case 'G': ++cnt[DNA::G]; break;
                    case 'T': ++cnt[DNA::T]; break;
                }
            }
            // find max
            if(cnt[DNA::A]>=cnt[DNA::C])
        }
    }
}