#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROW 30
#define MAX_COL 30
#define MAX_LEN 256

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int visitCount[MAX_ROW][MAX_COL] = {0};
int count = 0;


char turnRight(char direction){

  if( direction == '>')
    return 'v';
  else if( direction == 'v')
    return '<';
  else if( direction == '<')
    return '^';
  else if( direction == '^')
    return '>';
  else 
    return direction;
}

char turnLeft(char direction){

  if( direction == '>')
    return '^';
  else if( direction == 'v')
    return '>';
  else if( direction == '<')
    return 'v';
  else if( direction == '^')
    return '<';
  else 
    return direction;

}
void move(char direction, int current_x, int current_y, int *next_x, int *next_y){

  if( direction == '^'){
    *next_x = current_x;
    *next_y = current_y - 1;
  }
  else if( direction == '>'){
    *next_x = current_x + 1;
    *next_y = current_y;
  }
  else if( direction == 'v'){
    *next_x = current_x;
    *next_y = current_y +1;
  }
  else if( direction == '<'){
    *next_x = current_x -1;
    *next_y = current_y;
  }

}
void printMaze(int (*maze)[MAX_COL], int n, int m, 
                int start_x, int start_y, int end_x, int end_y ){

  int ii, jj;
  for( ii = 0; ii < n; ii++){
    for( jj = 0; jj < m ; jj++){
      if( start_x == jj && start_y == ii)
        printf(" S");
      else if( end_x == jj && end_y == ii)
        printf(" E");
      else
        printf("%2d",maze[ii][jj]);
      printf(" ");
    }
    printf("\n");
  }
}

void findRightSlove(int (*maze)[MAX_COL],int n, int m, 
                    int start_x, int start_y, int end_x, int end_y, char *record){
  // Todo Implement
 
  char direction = '^';
  int current_x = start_x;
  int current_y = start_y;
  int next_x, next_y;
  int ii;
  int jj = 0;

  while( !(current_x == end_x && current_y == end_y) ){

    direction = turnRight(direction);
    move(direction, current_x, current_y, &next_x, &next_y);

    if(  !(0 <= next_x  && next_x < m) )
      continue;
    else if( !(0 <= next_y && next_y < n) )
      continue;
    else if( maze[next_y][next_x] == 0 ) { // Exist the Load
      current_x = next_x;
      current_y = next_y;
      record[jj++] = direction;
    }
    else{

      for( ii = 0; ii < 4; ii++){
        direction = turnLeft(direction);
        move(direction, current_x, current_y, &next_x, &next_y);

        if(  !(0 <= next_x  && next_x < m) )
          continue;
        else if( !(0 <= next_y && next_y < n) )
          continue;
        else if( maze[next_y][next_x] == 0 ) { // Exist the Load
          current_x = next_x;
          current_y = next_y;
          record[jj++] = direction;
          break;
        }
      }
    }
  }
  record[jj] = '\0';
  memset( visitCount, 0x00, sizeof(visitCount));
  count = 0;
  visitCount[start_y][start_x] = 1;
}

void findRightSloveMin(int(*maze)[MAX_COL], int n, int m,
                      int start_x, int start_y, int end_x, int end_y){

  char direction = '^';
  int ii;
  int current_x, current_y;
  int next_x, next_y;

  current_x = start_x;
  current_y = start_y;

  if( current_x == end_x && current_y == end_y)
    return ;

  for( ii = 0; ii < 4; ii ++){

    direction = turnRight(direction);
    move(direction, current_x, current_y, &next_x, &next_y);
    if(  !(0 <= next_x  && next_x < m) )
      continue;
    else if( !(0 <= next_y && next_y < n) )
      continue;
    else if( maze[next_y][next_x] == 0 && visitCount[next_y][next_x] == 0){
      visitCount[next_y][next_x] = visitCount[current_y][current_x] + 1;
      findRightSloveMin(maze, n, m, next_x, next_y, end_x, end_y);
    }

  }
  // Todo Implement
}



int main(void){
  char record[MAX_LEN];
  int start_x, start_y;
  int end_x, end_y;
  int row, col;
  int maze1[MAX_ROW][MAX_COL] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
  };

  row = 10;
  col = 10;
  start_x = 1;
  start_y = 3;
  end_x = 7;
  end_y = 3;
  memset(record, 0x00, sizeof(record));
  printMaze(maze1, row, col, start_x, start_y, end_x, end_y);
  findRightSlove(maze1, row, col, start_x, start_y, end_x, end_y, record);
  printf("[%s]\n", record);

  memset(visitCount, 0x00, sizeof(visitCount));
  printf("-----min Load-------\n");
  findRightSloveMin(maze1, row, col, start_x, start_y, end_x, end_y);
  printMaze(visitCount, row, col, start_x, start_y, end_x, end_y);


  int maze2[MAX_ROW][MAX_COL] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,0,1,1},
    {1,0,1,0,1,1,1,0,1,1},
    {1,0,1,0,1,1,1,0,1,1},
    {1,0,1,0,0,1,1,0,1,1},
    {1,0,1,1,0,1,1,0,1,1},
    {1,0,0,0,0,1,1,0,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
  };
  row = 10;
  col = 10;
  start_x = 1;
  start_y = 1;
  end_x = 7;
  end_y = 7;
  memset(record, 0x00, sizeof(record));
  printMaze(maze2, row, col, start_x, start_y, end_x, end_y);
  findRightSlove(maze2, row, col, start_x, start_y, end_x, end_y, record);

  printf("min Load\n");
  memset(visitCount, 0x00, sizeof(visitCount));
  findRightSloveMin(maze2, row, col, start_x, start_y, end_x, end_y);
  printMaze(visitCount, row, col, start_x, start_y, end_x, end_y);
  printf("[%s]\n", record);


  int maze3[MAX_ROW][MAX_COL] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1,0,1,1},
    {0,0,0,1,0,0,0,0,0,1},
    {1,0,1,0,0,1,1,0,1,1},
    {1,0,1,0,1,1,1,0,1,1},
    {1,0,1,0,0,1,1,0,1,1},
    {1,0,1,1,0,1,1,0,1,1},
    {1,0,0,0,0,1,1,0,1,1},
    {1,0,1,1,0,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
  };
  row = 10;
  col = 10;
  start_x = 1;
  start_y = 1;
  end_x = 7;
  end_y = 7;
  memset(record, 0x00, sizeof(record));
  printMaze(maze3, row, col, start_x, start_y, end_x, end_y);
  findRightSlove(maze3, row, col, start_x, start_y, end_x, end_y, record);

  memset(visitCount, 0x00, sizeof(visitCount));
  printf("-----min Load-------\n");
  findRightSloveMin(maze3, row, col, start_x, start_y, end_x, end_y);
  printMaze(visitCount, row, col, start_x, start_y, end_x, end_y);

  printf("[%s]\n", record);


}


