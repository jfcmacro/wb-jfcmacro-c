#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include "rusers.h"

int
main(int argc, char* argv[])
{
  CLIENT *cl;
  utmp_array *usersArray;
  int opt;
  int *numUsers;
  int i;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s opt host", argv[0]);
    exit(1);
  }

  opt = (int) strtol(argv[1], (char **)NULL, 10);
 
  if (!(cl = clnt_create(argv[2], RUSERSPROG, RUSERSVERS, "udp"))) {
    clnt_pcreateerror(argv[2]);
    exit(1);
  }

  switch(opt) {
  case RUSERSPROC_NUM:
    numUsers = rusersproc_num_3((void *) NULL, cl); 
    fprintf(stdout, "Numero de usuarios %d\n", *numUsers);
    break;
  case RUSERSPROC_NAMES:
    usersArray = rusersproc_names_3((void *) NULL, cl);
    for (i = 0; i < usersArray->utmp_array_len; i++) {
      fprintf(stdout, "%s %s %s %d %d\n", 
	      usersArray->utmp_array_val[i].ut_user,
	      usersArray->utmp_array_val[i].ut_line,
	      usersArray->utmp_array_val[i].ut_host,
	      usersArray->utmp_array_val[i].ut_type,
	      usersArray->utmp_array_val[i].ut_time);
    }
    break;
  case RUSERSPROC_ALLNAMES:
    usersArray = rusersproc_allnames_3((void *) NULL, cl);
    for (i = 0; i < usersArray->utmp_array_len; i++) {
      fprintf(stdout, "%s %s %s %d %d\n", 
	      usersArray->utmp_array_val[i].ut_user,
	      usersArray->utmp_array_val[i].ut_line,
	      usersArray->utmp_array_val[i].ut_host,
	      usersArray->utmp_array_val[i].ut_type,
	      usersArray->utmp_array_val[i].ut_time);
    }
    break;
  }
}

