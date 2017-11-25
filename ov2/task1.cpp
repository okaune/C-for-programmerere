#include <cstring>
#include <iostream>
using namespace std;

void task1() {

  // 1a
  cout << "Task 1a" << endl;

  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  cout << "i: " << i << " -- " << &i << endl;
  cout << "j: " << j << " -- " << &j << endl;
  cout << "p: " << p << " -- " << &p << endl;
  cout << "q: " << q << " -- " << &q << endl;

  // 1b
  cout << "Task 1b" << endl;

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;
  cout << *p << " " << p << " " << *q << endl;
}
