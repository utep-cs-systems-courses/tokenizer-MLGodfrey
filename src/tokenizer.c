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

int count_words(char *str){
  int word_count = 0;
  while (*str != '\0'){
    str = word_start(str);
    if(non_space_char(*str)){
      word_count++;
    }
    str = word_terminator(str);
  }
  return word_count;
}

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
char **tokenize(char *str){
  int word_size = 0;
  char *word_end;
  char *word_begin;
  int total_words = count_words(str);
  char **tokens = (char**)malloc(sizeof(char*)*total_words);
  char *pointer = word_start(str);
  int i = 0;
  while(i <= total_words){
    word_begin = pointer;
    word_end = word_terminator(word_begin);
    pointer = word_end;
    word_size = word_end - word_begin;
    *tokens = copy_str(word_begin, word_size);
    pointer = word_start(word_end);
    i++;
  }
  return tokens;
}

void print_tokens(char **tokens){
  while(*tokens){
    printf("\n%s", *tokens);
    *tokens++;
  }
}


void free_tokens(char **tokens){
  while(*tokens){
    free(*tokens);
    *tokens++;
  }
}


