#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  printf("\n$ ");
  char user_input[101];
  fgets(user_input, 101, stdin);

  char* start = word_start(user_input);
  printf("\n%s", "Word start running : \n");
  printf("%c\n", *start);

  
}

