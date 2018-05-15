#include<stdio.h>
#include<string.h>

int Check_Group(char *word){

  int ii;
  int index;
  char alpabet_cnt[26] ={0};
  for( ii = 0; word[ii]; ii++ ){
  
    index = (int)(word[ii]-'a');
    if( alpabet_cnt[index] != 0 && word[ii-1] != word[ii]){
      return 0;

    }

    alpabet_cnt[index]++;
  }
  return 1;
}

int main(void){

  int TC;
  int result = 0;
  char word[100];

  scanf("%d", &TC);
  while(TC--){
    memset( word, 0x00, sizeof(word) );
    scanf("%s", word);

    result += Check_Group(word);
  }
  printf("%d\n", result);

}
