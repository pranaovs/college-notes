#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define VOWEL_MAP "AEIOUaeiou"

// Structure to pass filename to thread
typedef struct {
  char *filename;
  int total_vowels;
  int vowel_counts[5]; // Vowel count
} VowelData;

int is_vowel(char c, int vowel_counts[]) {
  char lc = tolower(c);

  switch (lc) {
  case 'a':
    vowel_counts[0]++;
    return 1;
  case 'e':
    vowel_counts[1]++;
    return 1;
  case 'i':
    vowel_counts[2]++;
    return 1;
  case 'o':
    vowel_counts[3]++;
    return 1;
  case 'u':
    vowel_counts[4]++;
    return 1;
  default:
    return 0;
  }
}

// Thread function to count vowels in file
void *vowel_counter_thread(void *arg) {
  VowelData *data = (VowelData *)arg;
  char buffer[BUFFER_SIZE];
  int fd;
  ssize_t bytes_read;

  // Initialize counts
  data->total_vowels = 0;
  for (int i = 0; i < 5; i++) {
    data->vowel_counts[i] = 0;
  }

  // Open file for reading
  fd = open(data->filename, O_RDONLY);
  if (fd == -1) {
    perror("Thread - Failed to open file");
    pthread_exit(NULL);
  }

  // Read file in chunks and count vowels
  while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
    for (int i = 0; i < bytes_read; i++) {
      data->total_vowels += is_vowel(buffer[i], data->vowel_counts);
    }
  }

  if (bytes_read == -1) {
    perror("Thread - Error reading file");
  }

  // Close on error
  if (close(fd) == -1) {
    perror("Thread - Error closing file");
  }

  printf("[PARENT] Found %d vowels in total:\n", data->total_vowels);
  printf("  - 'a'/'A': %d occurrences\n", data->vowel_counts[0]);
  printf("  - 'e'/'E': %d occurrences\n", data->vowel_counts[1]);
  printf("  - 'i'/'I': %d occurrences\n", data->vowel_counts[2]);
  printf("  - 'o'/'O': %d occurrences\n", data->vowel_counts[3]);
  printf("  - 'u'/'U': %d occurrences\n", data->vowel_counts[4]);

  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pid_t child_pid;
  int status;
  pthread_t tid;
  VowelData vowel_data;
  time_t current_time;
  char time_string[100];

  // Check arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get and display current time
  current_time = time(NULL);
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S",
           localtime(&current_time));

  printf("Start time: %s\n", time_string);

  vowel_data.filename = argv[1];

  // Create child process
  printf("[PARENT] Creating child process\n");
  child_pid = fork();

  if (child_pid < 0) {
    // Fork failed
    perror("Fork failed");
    return EXIT_FAILURE;
  } else if (child_pid == 0) {
    // Child process
    printf("[CHILD] Process started (PID: %d)\n", getpid());
    printf("[CHILD] Executing 'wc -l %s'\n\n", argv[1]);

    // Execute wc command
    execlp("wc", "wc", "-l", argv[1], NULL);

    // if execlp failed
    perror("Exec failed");
    _exit(EXIT_FAILURE); // exit only child
  } else {
    // Parent process
    printf("[PARENT] Child process created with PID: %d\n", child_pid);
    printf("[PARENT] Creating thread to count vowels\n");

    // Create thread for vowel counting
    if (pthread_create(&tid, NULL, vowel_counter_thread, &vowel_data) != 0) {
      perror("Thread creation failed");
      return EXIT_FAILURE;
    }

    // Wait for child process to complete
    printf("[PARENT] Waiting for child process to complete\n");
    if (waitpid(child_pid, &status, 0) == -1) {
      perror("Wait failed");
      return EXIT_FAILURE;
    }

    if (WIFEXITED(status)) {
      printf("\n[PARENT] Child process completed with status: %d\n",
             WEXITSTATUS(status));
    } else {
      printf("\n[PARENT] Child process terminated abnormally\n");
    }

    // Wait for thread to complete
    printf("[PARENT] Waiting for vowel counter thread to complete\n");
    if (pthread_join(tid, NULL) != 0) {
      perror("Thread join failed");
      return EXIT_FAILURE;
    }

    printf("File: %s\n", argv[1]);
  }

  return EXIT_SUCCESS;
}
