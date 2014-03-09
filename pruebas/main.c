#include <stdio.h>

int getbits(unsigned, unsigned, unsigned);
int rgetbits(unsigned, unsigned, unsigned);

int
main()
{
   printf("0xF4: %#X\n", getbits(0xF4, 4, 4));
   printf("0xF4: %#X\n", rgetbits(0xF4, 4, 4));
   printf("sizeof(unsigned)%d\n", sizeof(unsigned));
   printf("0xFFFFFFF4: %#X %#X\n", ~0, rgetbits((unsigned int) ~0, 3, 4));
   return 0;
}
