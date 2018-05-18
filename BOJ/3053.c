#include<stdio.h>
#include<math.h>


double area_e(int r){
  return M_PI*r*r;

}
double area_h(int r){
  return 2*r*r;
}

int main(void){
  int r;
  scanf("%d", &r);
  printf("%.6f\n", area_e(r) );
  printf("%.6f\n", area_h(r) );
  
}
