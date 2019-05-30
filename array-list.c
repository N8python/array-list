#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

ArrayList * new_ArrayList(int length){
  ArrayList * arraylist = (ArrayList *) malloc(sizeof(ArrayList));
  arraylist->size = 0;
  arraylist->max_length = length;
  arraylist->data = malloc(sizeof(void *) * arraylist->max_length);
  arraylist->add = ArrayList_add;
  arraylist->get = ArrayList_get;
  arraylist->set = ArrayList_set;
  arraylist->dub = ArrayList_double;
  arraylist->clear = ArrayList_clear;
  return arraylist;
}

void ArrayList_add(ArrayList * arr, void * val){
  ArrayList_double(arr);
  arr->data[arr->size++] = val;
}

void * ArrayList_get(ArrayList * arr, int index){
  return arr->data[index];
}

void ArrayList_set(ArrayList * arr, int index, void * val){
  while(arr->max_length < index){
    int toAdd = 0;
    ArrayList_add(arr, &toAdd);
  }
  arr->data[index] = val;
}
void ArrayList_double(ArrayList * arr){
  if(arr->size >= arr->max_length - 10){
    arr->max_length *= 2;
    arr->data = realloc(arr->data, sizeof(void *) * arr->max_length);
  }
}

void ArrayList_clear(ArrayList * arr){
  free(arr);
}
