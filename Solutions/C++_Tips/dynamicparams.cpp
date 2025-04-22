#include <bits/stdc++.h>

using namespace std;

template <size_t R, size_t C>
void printarray(const int (&array)[R][C], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << array[i][j] << ' ';
    }
    if (i < rows - 1) {
      cout << endl;
    }
  }
}

void printarray(const int **array) {
  int rows = sizeof(array);
  for (int i = 0; i < rows; i++) {
    int cols = sizeof(array[i]);
    for (int j = 0; j < cols; j++) {
      cout << array[i][j] << ' ';
    }
    if (i < rows - 1) {
      cout << endl;
    }
  }
}

void printarray(const void *VOID_ARR, ...) {
  int **array = (int **)VOID_ARR;
  int rows = sizeof(VOID_ARR);

  for (int i = 0; i < rows; i++) {
    int cols = sizeof(array[i]);
    for (int j = 0; j < cols; j++) {
      cout << array[i][j] << ' ';
    }
    if (i < rows - 1) {
      cout << endl;
    }
  }
  va_list list;

  va_start(list, VOID_ARR);
  void *vp = va_arg(list, void *);
}

void func(int _count, ...) {
  va_list list;

  va_start(list, _count);
  for (int i = 0; i < _count; ++i) {
    cout << (char)va_arg(list, int) << ", ";
  }
}

void dynamicparametertest() {
  int cnt = 5;

  int a = 97;
  int b = 98;
  int c = 99;
  int d = 100;
  int e = 101;
  char x = 'a';
  func(cnt, (char)a, (char)b, (char)c, (char)d, (char)x);
}

int main(void) { dynamicparametertest(); }