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

  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_address = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = inet_addr(server_ip),
      .sin_port = htons(port),
  };

  if (connect(client_socket, (struct sockaddr *)&server_address,
              sizeof(server_address)) == -1) {
    perror("Error connecting to server");
    close(client_socket);
    exit(EXIT_FAILURE);
  }

  char buffer[BUFFER_SIZE];
  ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);

  if (bytes_received == -1) {
    perror("Error receiving data");
  } else if (bytes_received == 0) {
    fprintf(stderr, "Connection closed by the server\n");
  } else {
    printf("Business card received from the server:\n");

    for (int i = 0; i < bytes_received; ++i) {
      if (is_printable_or_control(buffer[i])) {
        putchar(buffer[i]);
      }
    }
  }

  close(client_socket);

  return 0;
}