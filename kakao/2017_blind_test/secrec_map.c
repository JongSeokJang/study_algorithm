#include <string>
#include <vector>
#include <string.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int field1[16][16];
    int field2[16][16];
    int field3[16][16];
    int ii, jj;
    int count;
    int temp;
    char buffer[16+1];
   
    memset(field1, 0x00, sizeof(field1));
    memset(field2, 0x00, sizeof(field2));
    for( ii = 0; ii < n ; ii++){
        temp = arr1[ii];     
        count = 0;
        while(temp){
            if( temp %2 == 0 )
                field1[ii][(n-1) - count]  = 0;
            else
                field1[ii][(n-1) - count]  = 1;
            count++;
            temp /= 2;
        }
        count = 0;
        temp = arr2[ii];
        while(temp){
            if( temp %2 == 0 )
                field2[ii][(n-1) - count]  = 0;
            else
                field2[ii][(n-1) - count]  = 1;
            count++;
            temp /= 2;
        }
    }
    
    for( ii = 0; ii < n; ii++){
        for( jj = 0; jj < n ; jj++)
            printf(" [%d]", field1[ii][jj]);
        printf("\n");
    }
    for( ii = 0; ii < n; ii++){
        for( jj = 0; jj < n ; jj++)
            printf(" [%d]", field2[ii][jj]);
        printf("\n");
    }
    
    for( ii = 0; ii < n; ii++){
        memset(buffer, 0x00, sizeof(buffer));
        for( jj = 0; jj < n ;jj++){
            field3[ii][jj] = field1[ii][jj] | field2[ii][jj];
            if(field3[ii][jj] == 1)
                buffer[jj] = '#';
            else
                buffer[jj] = ' ';
        }
        answer.push_back(buffer);
    }
    
    return answer;
}
