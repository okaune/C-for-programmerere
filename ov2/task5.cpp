#include <iostream>

using namespace std;

void task5() {
  cout << "Task 5" << endl;

  double tall;
  double *peker = &tall;
  double &ref = tall;

  tall = 1.0;
  cout << tall << endl;
  *peker = 2.0;
  cout << tall << endl;
  ref = 3.0;
  cout << tall << endl;
}