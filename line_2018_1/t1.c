// #include <iostream>
//#include <cstdio>
//#include <cstring>
#include <stdio.h>
#include<string.h>
// cin,cout 대신 scanf,printf를 사용하려면 iostream 대신 cstdio 를 사용하세요 .
typedef struct _{
  int team;
  int x;
  int y;
  int result;
}info;

void quickSort(info field[], int left, int right) {
      int ii = left, jj = right;
      int pivot = field[(left + right)/ 2].result;
      int temp;
      info temp_1;
      do {
        while (field[ii].result < pivot) 
            ii++;
        while (field[jj].result > pivot)
            jj--;
        if (ii<= jj) {

          temp_1.x      = field[ii].x;
          temp_1.y      = field[ii].y;
          temp_1.team   = field[ii].team;
          temp_1.result = field[ii].result;

          field[ii].x    = field[jj].x;
          field[ii].y    = field[jj].y;
          field[ii].team = field[jj].team;
          field[ii].result = field[jj].result;

          field[jj].x    = temp_1.x;
          field[jj].y    = temp_1.y;
          field[jj].team = temp_1.team;
          field[jj].result = temp_1.result;

            ii++;
            jj--;


        }
	} while (ii<= jj);

    /* recursion */
    if (left < jj)
        quickSort(field, left, jj);

    if (ii < right)
        quickSort(field, ii, right);
}


int main() {
	
	int T, tc;
  int ii,jj;
  int min = 99999;
  info field[100];
  info temp_1;

  int x, y;
  int cnt;
  char name[20];

  scanf("%d", &T);
  
  while(T--){
    scanf("%d", &tc);

    for( ii = 0; ii < tc; ii++){
      memset(name, 0x00, sizeof(name));
      scanf("%d %d %s", &x, &y, name);

      if( strcmp(name, "Brown") == 0 ){
        field[ii].team = 1;
      }
      else{
        field[ii].team = 2;
      }
      field[ii].x = x;
      field[ii].y = y;
      field[ii].result = x*x + y*y;
    }
    
    quickSort(field, 0, tc-1);
    /*
    for( ii = 0; ii < tc; ii++){
      for( jj = ii+1; jj < tc; jj++){

        if( field[ii].result > field[jj].result ){
          temp_1.x      = field[ii].x;
          temp_1.y      = field[ii].y;
          temp_1.team   = field[ii].team;
          temp_1.result = field[ii].result;

          field[ii].x    = field[jj].x;
          field[ii].y    = field[jj].y;
          field[ii].team = field[jj].team;
          field[ii].result = field[jj].result;

          field[jj].x    = temp_1.x;
          field[jj].y    = temp_1.y;
          field[jj].team = temp_1.team;
          field[jj].result = temp_1.result;
        }
      }
    }
    */

    cnt = 0;    
    int temp_2 = field[0].team;

    for( ii = 0; ii < tc; ii++){
    
      if( temp_2 == field[ii].team ){
        cnt++; 
      }
      else{
        if( ii > 0 && field[ii].result == field[ii-1].result ){
          if(field[ii].team != field[ii-1].team){
            cnt--;
          }
        }
        break;
      }
    }

    if( temp_2 == 1 ){
      printf("Brown %d\n", cnt);
    }
    else{
      printf("Cony %d\n", cnt);
    }

  }

    
}
