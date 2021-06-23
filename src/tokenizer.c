#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if (c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if (c == '\t' || c == ' '|| c=='\0'){
    return 0;
  }
  return 1;
}

char *word_start(char *str){
  while (space_char(*str)){
    str++;
  }
  return str;
}



char *word_terminator(char *word){
  while(non_space_char(*word)){
    word++;
  }
  return word;
}

//int count_words(char *str){
//int word_count =0;
//while(space_char){
    
//}
