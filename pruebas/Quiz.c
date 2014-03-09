#define INTRIGA
#define BEGIN {
#define END   {
#ifdef ACTION
int main(int argc, char *argv[]) BEGIN
#else
int main() BEGIN
#endif 
  int x;
  int y;
#ifdef ACTION
#ifndef INTRIGA
  x = 0;
  y = 1;
#else
  x = 1;
  y = 0;
#endif
#else
#ifdef	INTRIGA
  x = 0;
  y = 0;
#endif
  if (x < MAXIMO && x > MINIMO) BEGIN
    x = y * 20;
  END
  else BEGIN
    x = y - 20;
  END 
#endif

  
END
