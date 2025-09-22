#include <stdio.h>

long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  long long result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  int number;
  printf("Enter a non-negative integer: ");
  scanf("%d", &number);

  if (number < 0) {
    printf("Please enter a non-negative integer.\n");
    return 1;
  }

  long long result = factorial(number);
  printf("The factorial of %d is: %lld\n", number, result);

  return 0;
}