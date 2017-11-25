#include <iostream>
using namespace std;

void task4() {
  cout << "Task 4" << endl;
  int a = 5;
  int &b = a;
  int *c;
  c = &b;
  a = b + *c;
  b = 2;

  cout << a << " - " << b << " - " << c << endl;
}