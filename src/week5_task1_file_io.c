// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  char filename[100] = "data.txt";
  char line[256];

  fp = fopen(filename, "w");

  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  fprintf(fp, "Hello, World!\n");
  fprintf(fp, "This is a test file.\n");
  fprintf(fp, "Goodbye, World!\n");
  fclose(fp);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
  }
  fclose(fp);

  printf("Enter filename: ");
  fgets(filename, sizeof(filename), stdin);
  filename[strcspn(filename, "\n")] = 0;

  int line_count = 0;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    line_count++;
  }
  fclose(fp);
  printf("Total lines read: %d\n", line_count);

  return 0;
}