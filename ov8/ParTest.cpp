#include "Par.cpp"
#include <iostream>

using namespace std;


int main() {
  Par<double, int> p1(3.5, 14);
  Par<double, int> p2(2.1, 7);

  cout << "p1: " << p1.t1 << ", " << p1.t2 << endl;
  cout << "p2: " << p2.t1 << ", " << p2.t2 << endl;

  if(p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;
  auto sum = p1 + p2;
  cout << "Sum: " << sum.t1 << ", " << sum.t2 << endl;
}