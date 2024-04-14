#include <ctype.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 2020
#define BUFFER_SIZE 1024

int is_palindrome(char *word) {
  int length = strlen(word);

  for (int i = 0; i < length / 2; ++i) {
    if (tolower(word[i]) != tolower(word[length - i - 1])) {
      return 0;
    }
  }

  return 1;
}

void *handle_client(void *client_socket) {
  int sock = *(int *)client_socket;
  free(client_socket);

  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);

  int total_recv_size = 0;
  int recv_size;
  while ((recv_size = recv(sock, buffer + total_recv_size,
                           BUFFER_SIZE - total_recv_size - 1, 0)) > 0) {
    total_recv_size += recv_size;

    if (total_recv_size >= BUFFER_SIZE - 1 ||
        buffer[total_recv_size - 1] == '\n') {
      break;
    }
  }

  if (recv_size < 0) {
    perror("recv failed");
    close(sock);
    return NULL;
  }

  buffer[total_recv_size] = '\0';

  if (total_recv_size == 0 ||
      (total_recv_size == 2 && strncmp(buffer, "\r\n", 2) == 0)) {
    write(sock, "0/0\r\n", 5);
    close(sock);
    return NULL;
  }

  char previous_char = '\0';
  for (int i = 0; i <= total_recv_size; ++i) {
    char current_char = buffer[i];

    if (current_char == '\0' && i != total_recv_size) {
      write(sock, "ERROR\r\n", 7);
      close(sock);
      return NULL;
    }

    if (current_char == ' ' && previous_char == ' ') {
      write(sock, "ERROR\r\n", 7);
      close(sock);
      return NULL;
    }

    if (current_char != ' ' && !isalpha(current_char) && current_char != '\r' &&
        current_char != '\n' && current_char != '\0') {
      write(sock, "ERROR\r\n", 7);
      close(sock);
      return NULL;
    }

    previous_char = current_char;
  }

  int palindrome_count = 0, word_count = 0;
  char *line, *line_context;
  char *word, *word_context;

  line = strtok_r(buffer, "\r\n", &line_context);

  while (line != NULL) {
    if (line[0] == ' ' || line[strlen(line) - 1] == ' ') {
      write(sock, "ERROR\r\n", 7);
      close(sock);
      return NULL;
    }

    word = strtok_r(line, " ", &word_context);

    while (word) {
      if (is_palindrome(word)) {
        ++palindrome_count;
      }

      ++word_count;
      word = strtok_r(NULL, " ", &word_context);
    }

    line = strtok_r(NULL, "\r\n", &line_context);
  }

  char response[32];
  sprintf(response, "%d/%d\r\n", palindrome_count, word_count);
  write(sock, response, strlen(response));

  close(sock);
  return NULL;
}

int main() {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  pthread_t thread_id;

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 100) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  while (1) {
    new_socket =
        accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (new_socket < 0) {
      perror("accept failed");
      continue;
    }

    int *new_sock = (int *)malloc(sizeof(int));
    *new_sock = new_socket;

    if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) !=
        0) {
      perror("thread creation failed");
    }

    pthread_detach(thread_id);
  }

  return 0;
}
