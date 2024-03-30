#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAXLINE 256

int
main(int argc, char **argv) {
  int sockfd, n;
  char recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;

  if (argc != 2) {
    fprintf(stderr, "usage: daytimecln <IPaddress>");
    exit(1);
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "socket error: %d %s\n", errno, strerror(errno));
    exit(1);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(13);

  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "inet_pton error for %s\n", argv[1]);
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
   fprintf(stderr, "connect error: %d %s\n", errno, strerror(errno));
    exit(1);
  }

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    recvline[n] = 0;
    if (fputs(recvline, stdout) == EOF) {
      fprintf(stderr, "fputs error: %d %s\n", errno, strerror(errno));
      exit(1);
    }
  }

  if (n < 0) {
      fprintf(stderr, "fputs error: %d %s\n", errno, strerror(errno));
      exit(1);
  }

  exit(0);
}
