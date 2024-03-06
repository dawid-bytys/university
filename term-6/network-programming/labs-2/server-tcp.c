#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int port = atoi(argv[1]);
  if (port <= 0 || port > 65535) {
    fprintf(stderr, "Invalid port number: %d\n", port);
    exit(EXIT_FAILURE);
  }

  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_address = {
      .sin_family = AF_INET,
      .sin_port = htons(port),
      .sin_addr.s_addr = INADDR_ANY,
  };

  if (bind(server_socket, (struct sockaddr *)&server_address,
           sizeof(server_address)) == -1) {
    perror("Error binding socket");
    close(server_socket);
    exit(EXIT_FAILURE);
  }

  if (listen(server_socket, 5) == -1) {
    perror("Error listening for connections");
    close(server_socket);
    exit(EXIT_FAILURE);
  }

  printf("[TCP] Server listening on port %d...\n", port);

  while (1) {
    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
      perror("Error accepting connection");
      continue;
    }

    const char *business_card = "Hello, world!\r\n";
    if (send(client_socket, business_card, strlen(business_card), 0) == -1) {
      perror("Error sending data");
    }

    close(client_socket);
  }

  close(server_socket);

  return 0;
}
