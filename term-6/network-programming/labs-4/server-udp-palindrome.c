#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define UDP_MAX_PACKET_SIZE 65507

struct buffer_result {
  int palindrome_count;
  int word_count;
};

int is_palindrome(const char *word) {
  int length = strlen(word);

  for (int i = 0; i < length / 2; ++i) {
    if (tolower(word[i]) != tolower(word[length - i - 1])) {
      return 0;
    }
  }

  return 1;
}

struct buffer_result process_buffer(const char *buffer, ssize_t buffer_len) {
  struct buffer_result result = {0, 0};

  int word_start = 0;

  for (int i = 0; i < buffer_len; ++i) {
    if (isspace(buffer[i]) || buffer[i] == '\n' || i == buffer_len - 1) {
      if (i >= word_start) {
        ++result.word_count;

        int word_length;

        if (i == buffer_len - 1 && buffer[i] != '\n') {
          word_length = i - word_start + 1;
        } else {
          word_length = i - word_start;
        }

        char word[word_length + 1];
        strncpy(word, buffer + word_start, word_length);
        word[word_length] = '\0';

        if (is_palindrome(word)) {
          ++result.palindrome_count;
        }
      }

      word_start = i + 1;
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  int port;

  if (argc == 1) {
    port = 2020;
  } else if (argc == 2) {
    port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
      fprintf(stderr, "Invalid port number\n");
      return EXIT_FAILURE;
    }
  } else {
    fprintf(stderr, "Usage: %s [<port>]\n", argv[0]);
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

  printf("[UDP] Server is listening on port %d...\n", port);

  struct sockaddr_in client_addr;
  socklen_t addr_len = sizeof(client_addr);
  char buffer[MAX_BUFFER_SIZE];

  while (1) {
    ssize_t recv_len = recvfrom(sockfd, buffer, UDP_MAX_PACKET_SIZE, 0,
                                (struct sockaddr *)&client_addr, &addr_len);
    if (recv_len == -1) {
      perror("recvfrom");
      close(sockfd);
      return EXIT_FAILURE;
    }

    if (recv_len > MAX_BUFFER_SIZE) {
      snprintf(buffer, MAX_BUFFER_SIZE, "ERROR\n");
      sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr,
             addr_len);
      continue;
    } else if (recv_len == 0) {
      snprintf(buffer, MAX_BUFFER_SIZE, "0/0\n");
      sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr,
             addr_len);
      continue;
    }

    printf("Received %zd bytes from %s:%d\n", recv_len,
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    printf("Received message: %.*s\n", (int)recv_len, buffer);

    struct buffer_result result = process_buffer(buffer, recv_len);

    snprintf(buffer, MAX_BUFFER_SIZE, "%d/%d\n", result.palindrome_count,
             result.word_count);
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr,
           addr_len);
  }

  close(sockfd);
  return EXIT_SUCCESS;
}
