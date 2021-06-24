#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "malloc.h"

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

int str_length(char *str){
  int count;
  for(count=0; *str != '\0'; str++){
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *new_str = (char*)malloc(sizeof(char)*len);
  while (*inStr != '\0'){
    *new_str = *inStr;
    new_str++;
    inStr++;
  }
  new_str-=len;
  return new_str;
}
