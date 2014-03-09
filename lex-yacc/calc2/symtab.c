
//symtab.c
#include <stdlib.h>

#include "item.h"
#define null(A) (key(st[A]) == key(NULLitem))

Item NULLitem = {0,0};

static int N, M;

static Item *st;

void STinit(int max) {
  int i;
  N = 0;
  M = 2*max;
  st = (Item *) malloc(M*sizeof(Item));
  for(i=0; i<M; i++) st[i] = NULLitem;
}


void STinsert(Item item) {
  Key v = key(item);
  int i = hash(v,M);
  while(!null(i)) i = (i+1) % M;
  st[i] = item; N++;
}

Item STsearch(Key v) {
  int i = hash(v,M);
  while (!null(i)) 
    if eq(v,key(st[i])) 
	   return st[i];
    else
      i = (i+1) % M;
  return NULLitem;
}   


Item *SThandle(Key v) {
  int i = hash(v,M);
  while (!null(i))
    if eq(v,key(st[i]))
	   return st+i;
    else
      i = (i+1) % M;
  return NULL;
}


int hash(char *v, int M) {
  int h, a = 31415, b=27183;
  for(h=0; *v != '\0'; v++, a = a*b % (M-1))
    h  = (a*h + *v) % M;
  return h;
}


