#include<stdio.h>
#include<string.h>

#define BUFSIZE 200

int main(void){

	int T;
	scanf("%d", &T);

	for( int i = 0; i< T; i++){
		char buf[BUFSIZE];
		scanf("%s", buf);


		char before;
		char current;
		int count = 0;	
		int position = 0; 
		char result[BUFSIZE];


		if( strlen(buf) == 1 ){

			sprintf( &result[position++], "%d", 1);
			result[position++] = buf[0];

		}
		else{


			for( int ii = 0; ii < strlen(buf); ii++){

				current = buf[ii];

				if( ii == 0 ){
					before 	= current;
					count 	= 1;
				}
				else if (ii == strlen(buf) -1){

					if( current == before ){

						count++;
						sprintf( &result[position], "%d", count);

						if( count < 10 )
							position += 1;
						else if (count < 100)
							position += 2;
						else
							position += 3;

						result[position++] = before;

					}
					else{
						sprintf( &result[position], "%d", count);

						if( count < 10 )
							position += 1;
						else if (count < 100)
							position += 2;
						else
							position += 3;
						result[position++] = before;

						sprintf( &result[position++], "%d", 1);
						result[position++] = current;


					}


				}
				else{

					if( current == before ){

						count++;
					}
					else{
						sprintf( &result[position], "%d", count);
						if( count < 10 )
							position += 1;
						else if (count < 100)
							position += 2;
						else
							position += 3;
						result[position++] = before;


						before = current;
						count = 1;

					}
				}



			}
		}
		printf("%s\n", result);


	}

}
