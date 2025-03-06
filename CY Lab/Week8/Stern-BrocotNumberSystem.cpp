#include <iostream>
#include <string>
using namespace std;

int main(void){
    int N_u, N_d, L_u, L_d, R_u, R_d, C_u, C_d;
    while(1){
        string out;
        cin >> N_u >> N_d;
        if((N_u==1)&&(N_d==1)) break;
        L_u=0, L_d=1;
        R_u=1, R_d=0;
        C_u=1, C_d=1;

        while((N_u!=C_u)||(N_d!=C_d)){
            if((N_u*C_d) < (C_u*N_d)){ // L
                R_u = C_u;
                R_d = C_d;
                C_u = L_u + C_u;
                C_d = L_d + C_d;
                out += 'L';
            }else{ // R
                L_u = C_u;
                L_d = C_d;
                C_u = R_u + C_u;
                C_d = R_d + C_d;
                out += 'R';
            }
        }
        cout << out << "\n";
    }
}