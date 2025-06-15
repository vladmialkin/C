#include <stdio.h>
#include <string.h>

extern void calculate(const char*);

int main() {
  char input[100];

  while (1) {
    printf("Введите выражение (A <OP> B) или 'exit' для выхода: ");
    fgets(input, sizeof(input), stdin);

    input[strlen(input)-1] = '\0';

    if (strcmp(input, "exit") == 0)
      break;

    calculate(input);
  }

  return 0;
}
