#include<stdio.h>
#include<string.h>

int main(void){

  int ii;
  int index;
  int c1, c2, fn, color;
  int x,y,z;
  char temp[10][100];


  scanf("Canvas size: %d x %d", &c1, &c2);
  getchar();
  scanf("Background color: %x", &color);
  getchar();
  scanf("Number of frames: %d", &fn);
  getchar();

  scanf("%s %s %s %s %s", temp[0], temp[1], temp[2], temp[3], temp[4]);

  printf("\n");
  printf("%d\n", c1);
  printf("%d\n", c2);
  printf("%d\n", color);
  printf("%d\n", fn);
  
  for( ii = 0; ii < fn; ii++){
    memset(temp[5], 0x00, sizeof(temp[5]));
    scanf("%d: %d %d %s %d", &index, &x, &y, temp[5], &z);
    getchar();

    if( strcmp( temp[5], "yes") == 0 )
      printf("%dx%d, %d, 1\n", x, y, z);
    else
      printf("%dx%d, %d, 0\n", x, y, z);

  }

}
