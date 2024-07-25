#include "./../s21_math.h"

long double s21_exp(double x) {
  long double result = 1.0;
  long int del = 2;
  long double xPowI = x;

  for (int i = 1; i < 200000; i++) {
    result += xPowI;
    xPowI *= x;
    xPowI /= del;
    del += 1;
  }

  if (x == S21_INF)
    result = S21_INF;
  else if (x == -S21_INF)
    result = 0;
  else if ((int)x == x) {
    result = 1.0;
    int flag = 0;
    if (x < 0)
      flag = 1;
    x = s21_fabs(x);
    for (int i = 0; i < (int)x; i++) {
      result *= S21_E;
    }
    if (flag)
      result = 1 / result;
  }
  return result;
}
