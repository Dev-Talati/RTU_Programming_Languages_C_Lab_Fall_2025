/*
 * week4_3_struct_database.c
 * Author: [Dev Talati]
 * Student ID: [241ADB037]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  struct Student *students = NULL;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  students = (struct Student *)malloc(n * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("Enter data for student %d: ", i + 1);
    // Read name (no spaces), id, and grade
    if (scanf("%49s %d %f", students[i].name, &students[i].id,
              &students[i].grade) != 3) {
      printf("Invalid input.\n");
      free(students);
      return 1;
    }
  }

  printf("\n%-7s %-12s %-5s\n", "ID", "Name", "Grade");
  for (int i = 0; i < n; i++) {
    printf("%-7d %-12s %.1f\n", students[i].id, students[i].name,
           students[i].grade);
  }

  free(students);
  return 0;
}
