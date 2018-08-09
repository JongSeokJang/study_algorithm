#include<stdio.h>
#include<string.h>

#define MAX_HASH_TABLE 1000000
#define MAX_ROW 100000
#define MAX_COL 50


char strArr1[MAX_ROW][MAX_COL];
char strArr2[MAX_ROW][MAX_COL];
int hashCount[MAX_HASH_TABLE];

int makeHashKey(char *keyword){

}

void makeHash(){
  memset(hashCount, 0x00, sizeof(hashCount));
}

int calculate(int N, int M){
  int ii, jj;
  int count = 0;

  for( ii = 0 ; ii < N; ii++){
    for( jj = 0; jj < M; jj++){
      if( strcmp(strArr1[ii], strArr2[jj]) == 0){
        memset(strArr2[jj], 0x00, sizeof(strArr2[jj]));
        strcpy(strArr2[jj], strArr2[M-1]);
        M = M-1;

        count++;
        break;
      }
    }
  }
  return count;

}

int main(void){
  int TC;
  int N, M;
  int ii, jj;


  scanf("%d", &TC);

  for( ii = 1; ii <= TC; ii++){
    scanf("%d %d", &N, &M);

    for( jj = 0; jj < N; jj++)
      scanf("%s", strArr1[jj]);
    
    for( jj = 0; jj < M; jj++)
      scanf("%s", strArr2[jj]);

    printf("#%d %d\n", ii, calculate(N,M));
    
  }

}
