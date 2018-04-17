#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARR_SIZE 100


int main(void){

	int field[ARR_SIZE][ARR_SIZE]= {0};
	int temp_field[ARR_SIZE];
	int position = 0;
	int group_num = 1;
	int temp = 0;
	int ii, jj, kk;
	int flag = 0;
	int T;

	scanf("%d", &T);
	
	int ta, tb;
	int max = 0;
	for( ii = 0; ii < T; ii++){
	
		scanf("%d %d", &ta, &tb);
		field[ta][tb] = -1;
		field[tb][ta] = -1;
		
		if( ta > tb ){
			if( max < ta ) 
				max = ta;
		}
		else{
			if( max < tb )
				max = tb;
		}
	}

	group_num = 1;
	
	for( ii = 0; ii <= max; ii++){

		// check column data
		for( jj = 0; jj <= max; jj++){
			if( field[ii][jj] != -1 && field[ii][jj] != 0 ){
				temp = field[ii][jj];
				break;
			}
		}

		for( jj = 0; jj <= max; jj++){

			if( temp != 0 ){
				if( field[ii][jj] == -1 ){
					field[ii][jj] = temp;
					field[jj][ii] = temp;
					printf("[%d %d]= %d\n", ii, jj, temp);
				}
			}
			else{
				if( field[ii][jj] == -1 ){

					for( kk = 0; kk <= ii; kk++ ){
						if( field[kk][jj] != -1 && field[kk][jj] != 0){
							temp = field[kk][jj];
							break;
						}
					}
					if( temp!= 0){
						field[ii][jj] = temp;
						field[jj][ii] = temp;

					}
					else{
					
						printf("[%d %d]= %d\n", ii, jj, group_num);
						field[ii][jj] = group_num;
						field[jj][ii] = group_num;
						flag = 1;
					}
				}
			}
			
		}

		if( flag ){
			group_num++;
			flag = 0;
		}
		temp = 0;


	}
	printf("%d\n", group_num-1);

	return 0;

}
