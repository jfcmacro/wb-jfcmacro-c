#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>

char*
obtenerNombreGrupo(gid_t grupoId) {
  struct group *pGrpInfo;

  pGrpInfo = getgrgid(grupoId);

  if (pGrpInfo == NULL) 
    return NULL;

  return pGrpInfo->gr_name;
}

const char*
obtenerTipoDispositivo(mode_t mode) {
  
  fprintf(stdout, "Codigo: %o\n", mode);

  if (S_ISLNK(mode)) 
    return "Enlace simbolico";

  if (S_ISREG(mode))
    return "Un fichero regular";

  if (S_ISDIR(mode))
    return "Directorio";

  if (S_ISCHR(mode))
    return "Caracteres";

  if (S_ISBLK(mode))
    return "Bloques";

  if (S_ISFIFO(mode))
    return "Tubería nombrada";

  if (S_ISSOCK(mode))
    return "Socket";

  return "No determinado";
}

char*
obtenerNombreUsuario(uid_t userId) {
  struct passwd *pUinfo;

  pUinfo = getpwuid(userId);

  if (pUinfo == NULL)
    return NULL;

  return pUinfo->pw_name;
}

int
estado(const char* name) {
  
  struct stat statEstado;

  if (stat(name, &statEstado) < 0)
    return -1;
  fprintf(stdout, "\n\nArchivo: %s\n", name);
  fprintf(stdout, "Tipo: %s\n", obtenerTipoDispositivo(statEstado.st_mode));

  fprintf(stdout, "Dispositivo: %d Inodo: %d Modo: %o Enlaces: %d\n",
	  statEstado.st_dev, 
	  statEstado.st_ino, statEstado.st_nlink);

  fprintf(stdout, "Usuario: %s Grupo: %s\n", 
	  obtenerNombreUsuario(statEstado.st_uid),
	  obtenerNombreGrupo(statEstado.st_gid));

  fprintf(stdout, "Tamano: %ld Bloque: %ld NBloquesAsignados: %ld\n",
	  statEstado.st_size, 
	  statEstado.st_blksize, 
	  statEstado.st_blocks);

  fprintf(stdout, "Acceso: %s \nModificacion: %s \nCambio: %s\n",
	  ctime(&statEstado.st_atime), 
	  ctime(&statEstado.st_mtime),
	  ctime(&statEstado.st_ctime));
  return 0;
}

int
main(int argc, char *argv[]) {

  int i;

  if (argc == 1) {
    fprintf(stderr, "Uso: %s filesnames ....\n", 
	    argv[0]);
    exit(0);
  }

  for (i = 1; i < argc; i++) {
    if (estado(argv[i]) < 0) {
      fprintf(stderr, "Error al obtener estado de %s %d\n", 
	      argv[i], errno, strerror(errno));
    }
  }
  return 0;
}
