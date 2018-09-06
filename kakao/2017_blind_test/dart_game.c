#include <string>
#include<string.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int flag = 0;
    int curData;
    int score[3];
    int totalScore = 0;
    int ii = 0;
    int scoreIndex = 0;
    
   curData = 0; 
    while( ii < dartResult.length() ){

        if( '0' <=  dartResult[ii] && dartResult[ii] <= '9'){
    
            if( flag )
                curData = curData * 10 + dartResult[ii]-'0';
            else
                curData = dartResult[ii]-'0';

            flag = 1;
        }
        else if( dartResult[ii] == 'S'){
            score[scoreIndex++] = curData;
            curData = 0;
            flag = 0;
        }
        else if( dartResult[ii] == 'D'){
            curData = curData * curData;
            score[scoreIndex++] = curData;
            curData = 0;
            flag = 0;
        }
        else if( dartResult[ii] == 'T'){
            curData = curData * curData * curData;
            score[scoreIndex++] = curData;
            curData = 0;
            flag = 0;
        }
        else if( dartResult[ii] == '*'){
            if( scoreIndex == 1){
            	score[scoreIndex-1] = score[scoreIndex-1] * 2;
            }
            else{
            	score[scoreIndex-1] = score[scoreIndex-1] * 2;
            	score[scoreIndex-2] = score[scoreIndex-2] * 2;
            }
        }
        else if( dartResult[ii] == '#'){
            score[scoreIndex-1] = score[scoreIndex-1] * -1;
        }
        ii++;
    }
    
    totalScore = 0;
    for( ii = 0; ii < 3; ii++)
        totalScore += score[ii];
    
   answer = totalScore; 
    
    return answer;
}
