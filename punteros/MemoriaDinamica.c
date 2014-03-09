// MemoriaDinamica.c

int
main() {
  
  int *x;
  
  /* Solicita memoria dinamica.
   * Requiere la coercion debido a que la operacion
   * malloc esta declarada de la siguiente forma:
   * void* malloc(size_t size);
   */
  x = (int *) malloc(sizeof(int));

  /* Utiliza el operador de dereferencia para 
   * manipular el contenido
   */
  *x = 10;

  printf("El contenido de x es: %d y su direccion es: %p\n",
	 *x, /* El contenido */
	 x); /* La direccion */
  return 0;
}
