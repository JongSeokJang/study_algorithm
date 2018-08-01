#include<stdio.h>
#include<string.h>

#define MINIMUM 0.0000000001
#define MAXIMUM 1000000000

typedef struct _planet{
  int x;
  int mass;
}planet;

planet data[10];

int main(void){
  int ii, jj;
  double x_value;
  int TC;
  int planet_count;
  scanf("%d", &TC);

  for( ii = 0 ; ii < TC; ii++){

    memset(data, 0x00, sizeof(planet));
    scanf("%d", &planet_count);

    for( jj = 0; jj < planet_count; jj++)
      scanf("%d", &data[jj].x);

    for( jj = 0; jj < planet_count; jj++){
      scanf("%d", &data[jj].mass);
    }




  }

}
