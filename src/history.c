#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List *init_history(){
  List *user_history = (List*) malloc(sizeof(Item)*100);
  return user_history;
}

void add_history(List *list, char *str){
  Item *node = list->root;

  if (node == NULL) { //base case
    node = (Item*) malloc(sizeof(Item));
    node->id=1;
    node->str=str;
    node->next=NULL;
    list->root=node;
    printf("%s",node->str);
    printf("%i\n",node->id);
  }else{
    int id=2;
    while(node->next != NULL){
      node = node->next;
      id++;
    }
    node->next = (Item*)malloc(sizeof(Item));
    node->next->id=id;
    node->next->str=str;
    node->next->next=NULL;
    printf("%s\n",node->next->str);
    printf("%i\n",node->next->id);
  }
}

char *get_history(List *list, int id){
  Item *node = list->root;

  while(node!=NULL){
    if(node->id == id){
      return node->str;
    }
    node = node->next;
  }
  return "Error";
}


void print_history(List *list){
  Item *node = list->root;
  while(node != NULL){
    printf("\n%s",node->str);
    node=node->next;
  }
}
void free_history(List *list){
  Item *node = list->root;
  while(node != NULL){
    free(node);
    node = node->next;
  }
  free(list);
}

