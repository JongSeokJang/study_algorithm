#include <string>
#include <vector>
#include <string.h>
#include <iostream>

int dx[4] = {0,1,1,0};
int dy[4] = {0,0,1,1};

using namespace std;

vector<string> move(int m, int n, vector<string> board){
    int ii, jj, kk;
    
    for( jj = 0; jj < n ; jj++){
        for( ii = m-1; ii >= 0; ii--){
            
            if( board[ii][jj] == '0'){
                for( kk = ii-1; kk >= 0; kk--){
                    
                    if( board[kk][jj] != '0'){
                       	board[ii][jj] = board[kk][jj];
                       	board[kk][jj] = '0';
                        break;
                    }
                }
            }
        }
    }
    
    return board;
}

int solution(int m, int n, vector<string> board) {
    int score[31][31];
    int ii, jj, kk;
    int checkFlag = 0;
    int totalScore = 0;
    int currentScore = 0;
    char remember;
    
    int temp = 0;
    while(1){
        currentScore = 0;
    	board = move(m,n,board);
        
    	memset(score, 0x00, sizeof(score));
        
        for( ii = 0; ii < m-1; ii++){
            for( jj = 0; jj < n-1; jj++){
               checkFlag = 0;
               remember = board[ii][jj];
               if( remember == '0')
                   continue;

               for(kk = 0; kk < 4; kk++){
                   if( remember != board[ii+dy[kk]][jj+dx[kk]] )
                      checkFlag = 1; 
               }

               if( checkFlag == 0 ){
                   for( kk = 0; kk < 4; kk++){
                       score[ii+dy[kk]][jj+dx[kk]]++;
                   }
               }

            }
        }
        
        for( ii = 0; ii < m; ii++){
            for( jj = 0; jj < n; jj++){
                if( score[ii][jj] ){
                    totalScore++;
                    currentScore++;
                    board[ii][jj] = '0';
                    score[ii][jj] = 0;
                }
            }
            cout << endl;
        }
        
        if( currentScore == 0)
            break;
    }
    
    return totalScore;
}
