#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(int n, ...)
{
        va_list ap;
        int d;
        char c, *p, *s;
	int i;

        va_start(ap, n);
	printf("%d\n", n);
	for (i = 0; i < n; i++) {
	d = va_arg(ap, int);
	printf("%d\n", d);
	}
        va_end(ap);
}

char* foo2(int n, ...) {
  va_list ap;
  char *pBuffer = malloc((size_t) 128);
  char *p;
  int i;

  if (pBuffer == NULL) {
    return NULL;
  }

  *pBuffer = '\0';
  va_start(ap, n);

  for (i = 0; i < n; i++) {
    p = va_arg(ap, char*);
    printf("%s\n", p);
    strcat(pBuffer, p);
    strcat(pBuffer, " ");
  }

  va_end(ap);
  return pBuffer;
}

int
main()
{
  char* pBuffer;

  pBuffer = foo2(2, "Hola", "Mundo");
  printf("%s\n", pBuffer);
  free(pBuffer);
  pBuffer = foo2(3, "Hola", "Mundo", "cruel");
  printf("%s\n", pBuffer);
  free(pBuffer);
  return 0;
}
