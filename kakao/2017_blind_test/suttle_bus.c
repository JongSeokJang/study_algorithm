#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

string makeFormat(int temp_hour, int temp_min, int time){
    string time_format;
    string hour, min;
    
    if( time != 0){
        if( time / 60 < 10)
            hour = "0" + to_string(time / 60);
        else
            hour = to_string(time / 60);
        
        if( time % 60 < 10)
            min = "0" + to_string(time % 60);
        else
            min = to_string(time % 60);
    }
    else{
        
        if(  temp_hour < 10)
            hour = "0" + to_string(temp_hour);
        else
            hour = to_string(temp_hour);

        if( temp_min < 10)
            min = "0" + to_string(temp_min);
        else
            min = to_string(temp_min);
    }
    return hour + ":" + min;
    
}

string solution(int n, int t, int m, vector<string> timetable) {
    int maxCount = n * m;
    int maxTime  = 540 + (n-1) * t;
    int personCount[24][60];
    int ii, jj, kk ;
    int total = 0;
    string hour;
    string min;
    string answer = "";
    memset(personCount, 0x00, sizeof(personCount));
    
        for( ii = 0; ii < timetable.size(); ii++){
            int temp_hour;
            int temp_min;
            
            temp_hour = stoi( timetable[ii].substr(0,2));
            temp_min = stoi( timetable[ii].substr(3,5));
            
            personCount[temp_hour][temp_min]++;   
        }
        
        int current_time = 0;
        kk = 0;
        total = 0;
        int flag = 0;
        int current_person = 0;
        for( ii = 0; ii < 24; ii++){
            for( jj = 0; jj < 60; jj++){
                
                current_time = ii * 60 + jj;
                current_person += personCount[ii][jj];
                
                if( current_person + 1 > maxCount ){
                    int temp_hour;
                    int temp_min;
                    if( jj == 0){
                        temp_hour = ii -1;
                        temp_min = 59;
                    }
                    else{
                        temp_hour = ii;
                        temp_min = jj-1;
                    }
                    answer = makeFormat(temp_hour,temp_min,0);
                    flag = 1;
                    break;
                }
                
                if( current_time == 540 + kk * t ){
                    maxCount -= m;
                    current_person -= m;
                    if( current_person < 0)
                        current_person = 0;
                    kk++;
                }
            }
            
            if( flag )
                break;
        }

    return answer;
}
