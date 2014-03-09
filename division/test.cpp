#include <gmp.h>
#include <limits.h>
#include <stdio.h>
#include "BigInteger.h"

int
main() {

  mpz_t entero1;
  mpz_t entero2;
  mpz_t m_result;
  mpz_t tope;
  gmp_randstate_t state;
  unsigned long n;
  int i;
  u8 *datos1;
  u8 *datos2;
  u8 *a_result;
  size_t tamano;

  tamano = 1000;
  
  datos1 = new u8[tamano];
  datos2 = new u8[tamano];
  a_result = new u8[tamano];

  n = 100;
  // mpz_urandomb(entero1, state, n);

  mpz_init(tope);
  mpz_init(entero1);
  mpz_init(entero2);
  mpz_init(m_result);
  gmp_randinit_default(state);
  mpz_urandomb(tope, state, n);
  mpz_urandomm(entero1, state, tope);
  mpz_urandomm(entero2, state, entero1);
  mpz_out_str(stdout,16,entero1);
//   fprintf(stdout, "\n");
//   mpz_out_str(stdout, 16, tope);
  fprintf(stdout,"\n");
  mpz_out_str(stdout, 16, entero2);
  fprintf(stdout, "\n");
  tamano = 1000;
  mpz_export(datos1, &tamano, -1, 1, 0, 0, entero1);
  BigInteger b1(datos1, 1000, tamano);
  b1.print();
  tamano = 1000;
  mpz_export(datos2, &tamano, -1, 1, 0, 0, entero2);
  BigInteger b2(datos2, 1000, tamano);
  b2.print();
  mpz_cdiv_q (m_result, entero1, entero2);
  BigInteger resultado_b(a_result, 1000, 0);
  resultado_b.divide(b1, b2);
  mpz_out_str(stdout, 16, m_result);
  fprintf(stdout, "\n");
  resultado_b.print();
  return 0;
}
