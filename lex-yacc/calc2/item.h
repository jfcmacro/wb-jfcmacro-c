//item.h 

/* Key is defined as a string */
typedef char *Key;

/* Variable names are the only identifier 

   /* key value pair stored in the hash table */

typedef struct {
  Key key;   //  variable name is the key 
  int value; //  its value is an integer
} Item;


/* eq macro compares two key values A and B,
   returns true if they are equal */
#define eq(A,B) (strcmp(A,B) == 0) 

#define key(item) (item.key)


