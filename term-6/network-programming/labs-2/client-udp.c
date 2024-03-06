#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int is_printable_or_control(char c) {
  return isprint(c) || c == '\n' || c == '\r' || c == '\t';
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *server_ip = argv[1];
  int port = atoi(argv[2]);
  if (port <= 0 || port > 65535) {
    fprintf(stderr, "Invalid port number: %d\n", port);
    exit(EXIT_FAILURE);
  }

  int client_socket = socket(AF_INET, SOCK_DGRAM, 0);
  if (client_socket == -1) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_address = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = inet_addr(server_ip),
      .sin_port = htons(port),
  };

  sendto(client_socket, "", 0, 0, (struct sockaddr *)&server_address,
         sizeof(server_address));

  char buffer[BUFFER_SIZE];
  ssize_t bytes_received =
      recvfrom(client_socket, buffer, BUFFER_SIZE, 0, NULL, NULL);

  if (bytes_received == -1) {
    perror("Error receiving data");
    close(client_socket);
    exit(EXIT_FAILURE);
  }

  printf("Received business card: ");

  for (ssize_t i = 0; i < bytes_received; ++i) {
    const char current_char = buffer[i];

    if (is_printable_or_control(current_char)) {
      putchar(current_char);
    }
  }

  close(client_socket);

  return 0;
}
