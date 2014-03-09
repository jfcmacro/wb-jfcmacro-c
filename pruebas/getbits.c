
getbits(x, p, n)
unsigned x, p, n;
{
   return ((x >> (p+1-n)) & ~(~0 << n));
}
