#include "sirkel.cpp"
#include <iostream>

using namespace std;

int task2() {
  Sirkel enSirkel(5);
  double arealet = enSirkel.finnAreal();
  cout << "Arealet er lik " << arealet << endl;
  double omkretsen = enSirkel.finnOmkrets();
  cout << "Omkretsen er lik " << omkretsen << endl;
  return 0;
}