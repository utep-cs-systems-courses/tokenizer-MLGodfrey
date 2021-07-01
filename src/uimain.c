#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  List *history = init_history();
  int run =1;

  printf("%s\n","Enter a string to tokenize, or !# (# = 1-9) to recall history, or !p to print history, or !q to quit.");
  
  while(run){
    
  printf("\n$ ");
  char user_input[101];
  fgets(user_input, 101, stdin);
  printf("%s\n", user_input);

  if(user_input[0] == 33 && user_input[1] == 113){
    printf("%s,\n", "--quitting");
    run = 0;
  }
  else
  if(user_input[0] == 33 && (user_input[1] > 47 && user_input[1] < 58)){
    printf("%s\n", "--Finding history");
    int num = atoi(user_input+1);
    char* token = get_history(history, num);

    if(*token){
      printf("%s%s\n", "$", token);
    }
  }else
    if(user_input[0] == 33 && user_input[1] == 112){
      printf("%s", "--Printing history");
      print_history(history);
    }else{
      char **tokens = tokenize(user_input);
      print_tokens(tokens);
      printf("%s\n", "--Making history");
      char *copy = copy_str(user_input, str_length(user_input));
      printf("%s\n", copy);
      add_history(history,copy);
    }
  }
}
