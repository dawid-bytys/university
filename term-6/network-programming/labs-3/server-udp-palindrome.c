#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int is_palindrome(const char *word) {
  int length = strlen(word);

  for (int i = 0; i < length / 2; ++i) {
    if (tolower(word[i]) != tolower(word[length - i - 1])) {
      return 0;
    }
  }

  return 1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int port = atoi(argv[1]);
  if (port <= 0 || port > 65535) {
    fprintf(stderr, "Invalid port number\n");
    return EXIT_FAILURE;
  }

  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) ==
      -1) {
    perror("bind");
    close(sockfd);
    return EXIT_FAILURE;
  }

  printf("[UDP] Server is listening on port... %d\n", port);

  struct sockaddr_in client_addr;
  socklen_t addr_len = sizeof(client_addr);
  char buffer[MAX_BUFFER_SIZE];

  while (1) {
    ssize_t recv_len = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0,
                                (struct sockaddr *)&client_addr, &addr_len);
    if (recv_len == -1) {
      perror("recvfrom");
      close(sockfd);
      return EXIT_FAILURE;
    }

    int palindrome_count = 0;
    int word_count = 0;
    char *token = strtok(buffer, " ");
    buffer[recv_len] = '\0';

    while (token != NULL) {
      if (strlen(token) > 0) {
        ++word_count;

        if (is_palindrome(token)) {
          ++palindrome_count;
        }
      }

      token = strtok(NULL, " ");
    }

    char response[MAX_BUFFER_SIZE];

    snprintf(response, MAX_BUFFER_SIZE, "%d/%d", palindrome_count, word_count);
    sendto(sockfd, response, strlen(response), 0,
           (struct sockaddr *)&client_addr, addr_len);
  }

  close(sockfd);
  return EXIT_SUCCESS;
}
