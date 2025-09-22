#include <stdio.h>

int sum(int n) {
  int total = 0;
  for (int i = 1; i <= n; i++) {
    total += i;
  }
  return total;
}

int main() {
  int number;
  printf("Enter a positive integer: ");
  scanf("%d", &number);

  if (number < 1) {
    printf("Please enter a positive integer.\n");
    return 1;
  }

  int result = sum(number);
  printf("The sum of the first %d natural numbers is: %d\n", number, result);

  return 0;
}