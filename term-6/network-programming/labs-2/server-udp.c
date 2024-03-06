#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

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

  int server_socket = socket(AF_INET, SOCK_DGRAM, 0);
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

  printf("[UDP] Server listening on port %d...\n", port);

  while (1) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    ssize_t bytes_received =
        recvfrom(server_socket, buffer, BUFFER_SIZE, 0,
                 (struct sockaddr *)&client_address, &client_address_len);

    if (bytes_received == -1) {
      perror("Error receiving data");
      continue;
    }

    const char *business_card = "Hello, world!\r\n";
    sendto(server_socket, business_card, strlen(business_card), 0,
           (struct sockaddr *)&client_address, client_address_len);
  }

  close(server_socket);

  return 0;
}
