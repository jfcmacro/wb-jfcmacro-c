#define INTEGER 257
#define VARIABLE 258
typedef union {
  int   iValue; /* integer value */
  char* sValue;/* a string value */
} YYSTYPE;
extern YYSTYPE yylval;
