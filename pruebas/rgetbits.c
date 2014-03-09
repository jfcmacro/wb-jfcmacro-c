
rgetbits(x, p, n)
unsigned x, p, n;
{
   printf("p: %d n: %d\n", p, n);
   printf("p+1-n: %d x << (p+1-n): %#X\n", p+1-n, x << (p+1- n));
   printf("(unsigned int) * 8 - n: %#X\n", (~0 << sizeof(unsigned)*8 - n));
   return ((x << (p+1-n)) & (~0 << sizeof(unsigned)*8 -n));
}
