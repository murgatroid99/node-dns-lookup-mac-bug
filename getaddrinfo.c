#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main(int argc, char **argv) {
  struct addrinfo *result;
  struct addrinfo *res;
  int error;

  if (argc != 2) exit(EXIT_FAILURE);

  /* resolve the domain name into a list of addresses */
  error = getaddrinfo(argv[1], NULL, NULL, &result);
  if (error != 0) {
    if (error == EAI_SYSTEM) {
      perror("getaddrinfo");
    } else {
      fprintf(stderr, "error in getaddrinfo: %s\n", gai_strerror(error));
    }
    exit(EXIT_FAILURE);
  }

  /* loop over all returned results and print them */
  for (res = result; res != NULL; res = res->ai_next) {
    char ip[256];
    switch (res->ai_addr->sa_family) {
      case AF_INET:
        inet_ntop(AF_INET, &(((struct sockaddr_in *) res->ai_addr)->sin_addr), ip, 255);
        break;
      case AF_INET6:
        inet_ntop(AF_INET6, &(((struct sockaddr_in6 *) res->ai_addr)->sin6_addr), ip, 255);
        break;
      default:
        strcpy(ip, "???");
        break;
    }
    printf("%s\n", ip);
  }

  freeaddrinfo(result);
  return 0;
}
