// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// TODO: Complete function implementations and file handling logic.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
  Student s1;
  strcpy(s1.name, "Dev");
  s1.age = 21;
  s1.gpa = 3.75f;

  const char *filename = "student.txt";

  save_student(s1, filename);

  Student s2 = load_student(filename);

  printf("Name: %s\n", s2.name);
  printf("Age: %d\n", s2.age);
  printf("GPA: %.2f\n", s2.gpa);

  return 0;
}

void save_student(Student s, const char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file for writing");
    return;
  }
  fprintf(fp, "%s\n", s.name);
  fprintf(fp, "%d\n", s.age);
  fprintf(fp, "%.2f\n", s.gpa);
  fclose(fp);
}

Student load_student(const char *filename) {
  Student s;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file for reading");
    return s;
  }
  fgets(s.name, sizeof(s.name), fp);
  fscanf(fp, "%d\n", &s.age);
  fscanf(fp, "%f\n", &s.gpa);
  fclose(fp);
  return s;
}