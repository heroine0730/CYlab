#include <iostream>
using namespace std;

#define BoardSize 8

char chessBoard[BoardSize][BoardSize];
int cnt = 0;
bool ColUsed[BoardSize];
bool SLUsed[2*BoardSize-1]; // /
bool SRUsed[2*BoardSize-1]; // \ 

void Play(int col, int row){
    if(row == (BoardSize-1)){
        cnt ++;
        return;
    }

    // Mark down
    ColUsed[col] = true;
    SLUsed[col+row] = true;
    SRUsed[col-row+BoardSize] = true;

    // find next to place
    int nextRow = row+1;
    for(int nextCol=0; nextCol<BoardSize; nextCol++){
        if( ColUsed[nextCol] || SLUsed[nextCol+nextRow] 
            || SRUsed[nextCol-nextRow+BoardSize] 
            || chessBoard[nextRow][nextCol]=='*') 
            continue;
        Play(nextCol, nextRow);
    }

    // Clear up
    ColUsed[col] = false;
    SLUsed[col+row] = false;
    SRUsed[col-row+BoardSize] = false;
}

// bool checkBoardClear(void){
//     for(int i=0; i<BoardSize; i++) {
//         if(ColUsed[i] == true){
//             cout << "ColUsed " << i << endl;
//             return true;
//         }
//     }
//     for(int i=0; i<(2*BoardSize-1); i++){
//         if(SLUsed[i] == true){
//             cout << "SLUsed " << i << endl;
//             return true;
//         }
//         if(SRUsed[i] == true){
//             cout << "SRUsed " << i << endl;
//             return true;
//         }
//     }
//     return false;
// }


int main(void){

    for(int i=0; i<BoardSize; i++){
        for(int j=0; j<BoardSize; j++){
            cin >> chessBoard[i][j];
        }
    }

    for(int j=0; j<BoardSize; j++){
        if(chessBoard[0][j] == '.') Play(j, 0);
        // if(checkBoardClear()){
        //     cout << "chest board not clear" << endl;
        // }
    }

    cout << cnt << endl;
}