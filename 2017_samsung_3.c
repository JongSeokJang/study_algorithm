#include<stdio.h>
#include<string.h>

int check[4];
int map[4][8];

void rotate_right(int *array){

    int temp = array[7];
    for( int i = 7; i > 0; i-- ){
        array[i] = array[i-1];
    }
    array[0] = temp;
}
void rotate_left(int *array){

    int temp = array[0];
    for( int i = 0; i < 7; i++ ){
        array[i] = array[i+1];
    }
    array[7] = temp;
}

void change(int *array, int side){
    if( side == -1){
        rotate_left(array);
    }
    else{
        rotate_right(array);
    }
}

void solve(int idx, int side){
    check[idx] = 1;
    if( idx + 1 < 4 && !check[idx+1] ){
        if( map[idx][2] != map[idx+1][6] ){
            solve( idx + 1, -1*side);
        }
    }
    if( idx -1 >= 0 && !check[idx-1] ){
        if( map[idx][6] != map[idx-1][2] ){
            solve( idx -1, -1*side);
        }
    }
    change(map[idx], side);
}



int main(void){

    char temp[9];
    int ii, jj, kk;
    int idx, side;
    for( ii = 0; ii < 4; ii++){
        scanf("%s", temp);
        for( jj = 0; jj < 8; jj++ ){
            map[ii][jj] = temp[jj]-'0';
        }
    }
    scanf("%d", &kk);
    for( ii = 0; ii < kk; ii++){
        scanf("%d %d" , &idx, &side);
        memset( check, 0x00, sizeof(check) );
        solve(idx-1, side);
    }

    int res = 0;
    int score = 1;
    for( ii = 0; ii < 4; ii++){
        if(map[ii][0] == 1){
            res += score;
        }
        score *= 2;
    }
    printf("%d\n", score);
    return 0;
    
}