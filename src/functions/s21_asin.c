#include "./../s21_math.h"

long double s21_asin(double x) {

  double sum = x;
  double term = x;
  int n = 1;

  if (x < -1 || x > 1) {
    sum = S21_NAN;
  } else if (x == 1) {
    sum = S21_PI / 2;
  } else if (x == -1) {
    sum = -S21_PI / 2;
  } else {
    for (int i = 1; i < 200; i++) {
      term *= (x * x * (2 * i - 1) * (2 * i - 1)) / (2 * i * (2 * i + 1));
      sum += term;
      n++;
    }
  }
  return sum;
}
