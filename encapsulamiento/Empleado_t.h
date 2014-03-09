#include "Nombre_t.h"
#include "Date_t.h"
#include "Salario_t.h"
#include "Depto_t.h"

struct Empleado_t {
  struct Nombre_t nombre;
  long id;
  struct Date_t fechaNacimiento;
  struct Salario_t salario;
  struct Depto_t depto;
};
