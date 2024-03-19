#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 65536

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server_ip> <port> <words_to_check>\n", argv[0]);
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

  const char *words_to_check = argv[3];
  ssize_t bytes_sent =
      sendto(client_socket, words_to_check, strlen(words_to_check), 0,
             (struct sockaddr *)&server_address, sizeof(server_address));
  if (bytes_sent == -1) {
    perror("Error sending data");
    close(client_socket);
    exit(EXIT_FAILURE);
  }

  char buffer[BUFFER_SIZE];
  ssize_t bytes_received =
      recvfrom(client_socket, buffer, BUFFER_SIZE, 0, NULL, NULL);
  if (bytes_received == -1) {
    perror("Error receiving data");
  } else {
    printf("%s", buffer);
  }

  close(client_socket);

  return 0;
}
