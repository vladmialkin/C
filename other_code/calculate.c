#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

extern void print_zero_error();

void calculate(char* input) {
  double a, b, result;
  char op[3];
  int scan_result;

  scan_result = sscanf(input, "%lf %s %lf", &a, op, &b);

  if (scan_result != 3) {
    printf("Ошибка: Неправильный ввод. Повторите попытку.\n");
    return;
  }

  if (strcmp(op, "+") == 0)
    result = a + b;

  else if (strcmp(op, "-") == 0)
    result = a - b;

  else if (strcmp(op, "/") == 0) {
    if (b != 0)
      result = a / b;
    else {
      print_zero_error();
      return;
    }
  }

  else if (strcmp(op, "*") == 0)
    result = a * b;

  else if (strcmp(op, "%") == 0) {
    if ((int)b != 0)
      result = (int)a % (int)b;
    else {
      print_zero_error();
      return;
    }
  }

  else if (strcmp(op, "//") == 0) {
    if ((int)b != 0)
      result = (int)a / (int)b;
    else {
      print_zero_error();
      return;
    }
  }

  else if (strcmp(op, "**") == 0)
    result = pow(a, b);

  else {
    printf("Ошибка: Неподдерживаемый оператор '%s'.\n", op);
    return;
  }

  printf("Результат: %.2lf\n", result);
}
