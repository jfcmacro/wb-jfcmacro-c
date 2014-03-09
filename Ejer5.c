#define N 10

int v[N];

void
init() {
  static int x = 0;
  for (i = 0; i < 10; i++) {
    v[i] = x++;
  }
  return; // No es un error.
}

int
main() {
  init();
  init();
  init();
  return 0;
}
