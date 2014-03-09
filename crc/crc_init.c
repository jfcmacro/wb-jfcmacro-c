#include <stdio.h>
#include <unistd.h>

int 
main(int argc, char *argv[])
{
  unsigned long crc, poly;
  int n, i;

  sscanf(argv[1], "%lo", &poly);

  if (poly & 0xffff0000) {

    fprintf(stderr, "polynomial is to large\n");
    exit(1);
  }

  printf("/*\n * CR 0%o\n */\n", poly);

  printf("static unsigned short crc_table[256] = {\n");

  for (n = 0; n < 256; n++) {

    crc = n;

    if ((n % 8) == 0) 
      printf("    ");
    
    for (i = 0; i < 8; i++) {

      if (crc & 1) {
	crc >>= 1;
	crc ^= poly;
      }
      else {
	crc >>= 1;
      }
    }
    printf("0x%x, ", crc);
    
    if (n % 8 == 7)
      printf("\n");
  }
  printf("};\n\n");
  exit(0);
}
