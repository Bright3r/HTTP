
#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include "http.c"

#define MAX_NUM_THREADS 2
#define MAX_TASKS 100

typedef struct connection_args {
  int client_socket;
} connection_args;

typedef struct {
    char tasks[MAX_TASKS][256]; // Array of tasks, each can hold up to 255 characters
    int task_count;             // Number of current tasks
    pthread_mutex_t lock;       // Mutex for thread-safe access
} TaskList;

extern TaskList taskList;


void *handleConnection(void *arg);
int getHTMLFromFile(char **document, char *filePath);
char *handleGetRequest(HttpRequest request);
char *handlePostRequest(HttpRequest request);
char *handleDeleteRequest(HttpRequest request);
void add_task(const char* new_task);
char *parse_task(char *data);

#endif
