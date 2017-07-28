#include<stdio.h>

typedef struct item_t {
  char value;
} item;

typedef int ((*item_less_function)(item,item));

void insertion_sort(item s[], int n, item_less_function less);
int item_less(item, item);
void swap(item*,item*);
void printItem(item s[], int n);

int
main() {
  item s[] = { {'I'}, {'N'}, {'S'}, {'E'}, {'R'}, {'T'}, {'I'}, {'O'}, {'N'}, {'S'}, {'O'}, {'R'}, {'T'} };

  printItem(s, sizeof(s)/sizeof(item));

  insertion_sort(s, sizeof(s)/sizeof(item), item_less);

  printItem(s, sizeof(s)/sizeof(item));

  return 0;
}


int
item_less(item a, item b) {
  return a.value < b.value;
}

void
insertion_sort(item s[], int n, item_less_function less) {

  int i,j;

  for (i = 1; i < n; ++i) {
    j = i;
    while ((j > 0) && less(s[j], s[j-1])) {
      swap(&s[j], &s[j-1]);
      j = j - 1;
    }
    printItem(s,n);
  }
}

void
printItem(item s[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%c ", s[i]);
  }
  printf("\n");
}

void
swap(item* a, item* b) {
  item tmp = *a;
  *a = *b;
  *b = tmp;
}
