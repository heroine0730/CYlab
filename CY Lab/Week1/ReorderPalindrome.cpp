#include <iostream>
using namespace std;


int main(void){
    int alphabetCnt[26];
    string in;
    cin >> in;

    for(int i=0; i<26; i++){
        alphabetCnt[i] = 0;
    }
    for(int i=0; i<in.length(); i++){
        alphabetCnt[in[i]-'A']++;
    }
    char oddChar = '-';
    for(int i=0; i<26; i++){
        if(alphabetCnt[i]%2){
            if(oddChar == '-') oddChar = 'A'+i;
            else{
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    }
    string out;
    for(int i=0; i<26; i++){
        if(alphabetCnt[i]>0){
            if(alphabetCnt[i]%2) {
                out.append((alphabetCnt[i]-1)/2, 'A'+i);
            }else{
                out.append(alphabetCnt[i]/2, 'A'+i);
            }
        }
    }
    if(oddChar != '-') out.append(1 ,oddChar);
    for(int i=25; i>=0; i--){
        if(alphabetCnt[i]>0){
            if(alphabetCnt[i]%2) {
                out.append((alphabetCnt[i]-1)/2, 'A'+i);
            }else{
                out.append(alphabetCnt[i]/2, 'A'+i);
            }
        }
    }
    cout << out << endl;

}