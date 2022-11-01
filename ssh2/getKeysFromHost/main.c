#include <stdio.h>
#include <stdlib.h>
#include <libssh2.h>

int
main(int argc, char *argv[]) {
  LIBSSH2_SESSION* session = NULL;
  LIBSSH2_AGENT* agent = NULL;
  struct libssh2_agent_publickey *publickey;
  struct libssh2_agent_publickey *prevkey = NULL;
  libssh2_init(0);
  session = libssh2_session_init();
  agent = libssh2_agent_init(session);
  if (!libssh2_agent_connect(agent)) {
    int retValue;
    while ((retValue = libssh2_agent_get_identity(agent, &publickey, prevkey)) == 0) {
      fprintf(stdout, "blob: %s comment: %s\n",
	      publickey->blob, publickey->comment);
      prevkey = publickey;
    }
    if (retValue < 0) {
      fprintf(stderr, "Error: %d\n", retValue);
    }
    else {
      fprintf(stdout, "retValue: %d\n", retValue);
    }
  }
  else {
    fprintf(stderr, "Agent connect error\n");
  }
  libssh2_agent_disconnect(agent);
  libssh2_agent_free(agent);
  libssh2_session_free(session);
  libssh2_exit();
  return EXIT_SUCCESS;
}
