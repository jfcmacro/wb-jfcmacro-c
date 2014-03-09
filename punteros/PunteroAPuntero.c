/* Puntero a puntero */

int
main() {
  
  /* Declara un puntero a un entero */ 
  int *p = (int) malloc(sizeof(int));
  /* Declara un puntero a un puntero */
  int **pAp = &p;

  *p = 20;

  printf("El contenido de p: %d la direccion de p: %p\n",
	 *p, // el contenido
	 p); // la direccion

  printf("El contenido que apunta pAp: %d El contenido de pAp: %p la direccion de pAp: %p\n",
	 **pAp,
	 *pAp,
	 pAp);
	 
  free(p);

  return 0;
} 
