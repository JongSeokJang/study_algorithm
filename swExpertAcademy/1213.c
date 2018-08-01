#include<stdio.h>
#include<string.h>

char input[1000+1];
char word[10+1];
char temp_word[10+1];

int findWord(void){

  int ii;
  int word_count = 0;
  for( ii = 0; ii < strlen(input); ii++){
    memset(temp_word,0x00, sizeof(temp_word));
    strncpy(temp_word, &input[ii], strlen(word));

    if( strncmp(temp_word, word, strlen(word)) == 0)
      word_count++;
  }

  return word_count;

}

int main(void){
  int ii;
  int test_case; 
  int word_count;
  for( ii = 1; ii <= 10; ii++){
    memset( input, 0x00, sizeof(input) );
    memset( word , 0x00, sizeof(word)  );
    scanf("%d", &test_case);
    scanf("%s", word);
    scanf("%s", input);

    word_count = findWord();
    printf("#%d %d\n", ii, word_count);
  }
}
